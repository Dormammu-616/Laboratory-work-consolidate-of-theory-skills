#include "LabRunner.h"
#include "RollbackAction.h"
#include "SessionCacheChaining.h"
#include "SessionCacheOpenAddr.h"
#include <OrderTask.h>
#include <TwoEndedQueue.h>
#include <iostream>
#include <forward_list>
#include <stack>
#include <deque>
#include <queue>
#include <random>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#pragma warning(disable: 5045)

namespace RandomUtils
{
	inline static std::mt19937 gen(42);
}

struct CompareByPriority
{
	bool operator() (const OrderTask& task_a, const OrderTask& task_b) const
	{
		return task_a.priority < task_b.priority;
	}
};

struct Metrics
{
	std::string name_hash{};
	int64_t time_ms{};
	size_t memory_kb{};
	float load_factor{};
	uint8_t padding[4]{};
	Metrics(const std::string& name, const int64_t time, size_t memory, float load) : name_hash(name), time_ms(time), memory_kb(memory), load_factor(load) {};
};

std::ostream& operator<<(std::ostream& os, const std::forward_list<ProductUpdate>& list)
{
	os << "ID\t|PRICE\n"
		<< "---------------\n";
	for (const auto& datas : list)
	{
		os << datas.product_id << "\t| " << datas.price << "\n";
	}
	os << "\n";

	return os;
}

std::ostream& operator<<(std::ostream& os, const ProductAttribute& attribute)
{
	switch (attribute)
	{
		case ProductAttribute::Price:
		{
			return os << "Price";
		}
		case ProductAttribute::Stock_count:
		{
			return os << "Stock count";
		}
		case ProductAttribute::Status:
		{
			return os << "Status";
		}
		default:
		{
			return os << "UNKNOWN ATTRIBUTE";
		}
	}
}

std::ostream& operator<<(std::ostream& os, const RollbackAction& data)
{
	return os << "ID: " << data.product_id
		<< "\tAttribute: " << data.field_name
		<< "\tOld value: " << data.old_value
		<< "\tNew value: " << data.new_value << "\n";
}

void print_top_elem_stack(const std::stack<RollbackAction>& stack)
{
	if (!stack.empty())
	{
		std::cout << stack.top() << "\n";
		return;
	}

	std::cout << "The stack is empty!\n\n";
}

char generate_rand_sym()
{
	static constexpr std::string_view ALPHABET{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	std::uniform_int_distribution<size_t> dist(0, ALPHABET.size() - 1);
	return ALPHABET[dist(RandomUtils::gen)];
}

std::string generate_rand_str(const size_t min_len, const size_t max_len)
{
	std::uniform_int_distribution<size_t> dist(min_len, max_len);
	const size_t CUR_STR_LEN{ dist(RandomUtils::gen)};

	std::string rand_str;
	rand_str.reserve(CUR_STR_LEN);

	for (size_t i = 0; i < CUR_STR_LEN; ++i)
	{
		rand_str += generate_rand_sym();
	}

	return rand_str;
}

size_t get_stl_memory(const std::unordered_map<std::string, UserSession>& map)
{
	const size_t BUCKET_MEMORY{ map.bucket_count() * sizeof(void*) }; // память под указатели корзин
	const size_t NODES_MEMOTY{ map.size() * (sizeof(std::pair<std::string, UserSession>) + sizeof(void*) * 2) };// память под узлы (данные + служебные)
	return BUCKET_MEMORY + NODES_MEMOTY;// итого занятой памяти.
}

size_t get_total_memory(const std::unordered_map<std::string, UserSession>& map)
{
	return (get_stl_memory(map) / 1024);
}

template <typename T>
size_t get_total_memory(const T& cont)
{
	return (cont.get_hash_memory() / 1024);
}

template <typename CustomCache>
void insert_item(CustomCache& cont, const UserSession item)
{
	cont.emplace(item);
}

void insert_item(std::unordered_map<std::string, UserSession>& cont, const UserSession item)
{
	cont.emplace(item.session_token, item);
}

template <typename Container, typename Data, typename InsertFunc>
void run_operation_data_in_hash(Container& container, const Data& test_data, InsertFunc insert_logic)
{
	for (const auto& item : test_data)
	{
		insert_logic(container, item);
	}
}

template <typename Container, typename Func>
const Metrics get_metrics_after_operation(Container& cont, const std::string& name_cont, const std::vector<UserSession>& data_for_operation, Func lambda_func)
{
	const auto START_TIME { std::chrono::steady_clock::now() };
	run_operation_data_in_hash(cont, data_for_operation, lambda_func);
	const auto END_TIME {std::chrono::steady_clock::now()};
	const auto DIFF_TIME{ std::chrono::duration_cast<std::chrono::milliseconds>(END_TIME - START_TIME) };

	return Metrics{ name_cont, DIFF_TIME.count(), get_total_memory(cont), cont.load_factor()};
}

void log_hash_metrics(const std::vector<Metrics>& metrics)
{
	std::cout << "---------------------------------------------------------\n"
		<< "Implementation\t| Time (ms)\t| Memory (KB) \t| Load Factor\n"
		<< "---------------------------------------------------------\n";

	for (const auto& result : metrics)
	{
		std::cout << result.name_hash << "\t| " << result.time_ms << "\t\t| " << result.memory_kb << "\t\t| " << result.load_factor << "\n";
	}
	std::cout << "\n";
}

void LabRunner::run_lab_forward_list()
{
	auto comp_is_negative = [](ProductUpdate& data_product) {return data_product.price <= 0.0; };
	std::cout << "*** Starting lab on a std::forward_list ***\n\n";

	std::forward_list<ProductUpdate> first_data_stream{};
	std::forward_list<ProductUpdate> second_data_stream{};
	std::cout << "Two lists of the 'ProductUpdate' type have been created!\n\n";

	first_data_stream.emplace_front(4ULL, 4.5 );
	first_data_stream.emplace_front(8ULL, -4.5);
	first_data_stream.emplace_front(2ULL, 7.1 );
	first_data_stream.emplace_front(6ULL, 1.0 );

	second_data_stream.emplace_front(4ULL, 1.1 );
	second_data_stream.emplace_front(11ULL, -10.123 );
	second_data_stream.emplace_front(7ULL, 80.4 );
	second_data_stream.emplace_front(13ULL, 99.01 );

	std::cout << "*** Initial values of lists ***\n";
	std::cout << "The first list\n" << first_data_stream;
	std::cout << "The second list\n" << second_data_stream;
	
	first_data_stream.remove_if(comp_is_negative);
	second_data_stream.remove_if(comp_is_negative);
	std::cout << "*** The list after removed negative value price contains ***\n";
	std::cout << "The first list\n" << first_data_stream;
	std::cout << "The second list\n" << second_data_stream;
	
	std::cout << "*** The list after sorting by ID contains ***\n";
	first_data_stream.sort();
	second_data_stream.sort();
	std::cout << "The first list\n" << first_data_stream;
	std::cout << "The second list\n" << second_data_stream;
	
	first_data_stream.merge(second_data_stream);
	std::cout << "*** After the merge operation, the single list contains ***\n" << first_data_stream;
	std::cout << "The second list became empty after the merger - " << ((second_data_stream.empty()) ? ("TRUE!") : ("FALSE!")) << "\n\n";
	
	first_data_stream.unique();
	std::cout << "*** The merged list after removing duplicates contains ***\n" << first_data_stream;

	std::forward_list<ProductUpdate> final_buffer{ std::move(first_data_stream) };
	std::cout << "*** The operation std::move for merged list ***\n";
	std::cout << "The merged list became empty after operation - " << (first_data_stream.empty() ? "TRUE!" : "FALSE!") << "\n";
	std::cout << "The final list after data acceptance contains:\n" <<final_buffer;
}

void LabRunner::run_lab_stack()
{
	std::stack<RollbackAction> rollback_stack{};
	std::cout << "*** Starting lab on a std::stack(deque) ***\n\n";

	std::cout << "*** Inserting an existing object ***\n";
	RollbackAction first_new_product{ 4, ProductAttribute::Price, 47, 64 };
	RollbackAction second_new_product{ 1, ProductAttribute::Status, 1, 4 };
	RollbackAction third_new_product{ 2, ProductAttribute::Status, 8, 4 };
	rollback_stack.push(first_new_product);
	rollback_stack.push(second_new_product);
	rollback_stack.push(third_new_product);
	std::cout << "After the addition operations, the stack contains '" << rollback_stack.size() <<"' elements.\n"
		<< "The last element of the stack contains the values:\n";
	print_top_elem_stack(rollback_stack);

	std::cout << "*** Inserting an object in place ***\n";
	rollback_stack.emplace(5UL, ProductAttribute::Price, 27, 84);
	rollback_stack.emplace(8UL, ProductAttribute::Stock_count, 42, 40);
	rollback_stack.emplace(8UL, ProductAttribute::Price, 47, 78);
	std::cout << "After the addition operations, the stack contains '" << rollback_stack.size() << "' elements.\n"
		<< "The last element of the stack contains the values:\n";
	print_top_elem_stack(rollback_stack);

	std::cout << "*** Removing the last object ***\n";
	std::cout << "The last element BEFORE the delete operation contains::\n";
	print_top_elem_stack(rollback_stack);
	rollback_stack.pop();
	std::cout << "The last element AFTER the delete operation contains:\n";
	print_top_elem_stack(rollback_stack);
}

void LabRunner::run_lab_queue()
{
	std::cout << "*** Starting lab on a std::deque ***\n\n";

	std::deque<OrderTask> orders_customers{};
	std::priority_queue<OrderTask, std::deque<OrderTask>, CompareByPriority> orders_vip_customers{};
	TwoEndedQueue warehouse_operations{};


	std::cout << "--- Filling the deque ---\n";
	orders_customers.emplace_back(45UL, "sell");
	orders_customers.emplace_back(10UL, "sell");
	orders_customers.emplace_back(15UL, "pay");
	orders_customers.emplace_back(4UL, "pay");
	std::cout << "The client deque is filled! The queue size is '" << orders_customers.size() << "'.\n";

	orders_vip_customers.emplace(11UL, uint8_t{ 1 }, "sell");
	orders_vip_customers.emplace(8UL, uint8_t{ 3 }, "sell");
	orders_vip_customers.emplace(9UL, uint8_t{ 1 }, "pay");
	orders_vip_customers.emplace(2UL, uint8_t{ 5 }, "pay");
	std::cout << "The VIP client deque is filled! The queue size is '" << orders_vip_customers.size() << "'.\n";

	warehouse_operations.push_back(OrderTask{ 2UL, "sell" });
	warehouse_operations.push_back(OrderTask{ 7UL, "sell" });
	warehouse_operations.push_front(OrderTask{ 74UL, "pay" });
	warehouse_operations.push_front(OrderTask{ 3UL, "pay" });
	std::cout << "The warehouse deque is filled! The queue size is '" << warehouse_operations.size() << "'.\n";


	std::cout << "--- Deque processing ---\n";
	if (!orders_customers.empty())
	{
		const OrderTask& CUR_TASK{ orders_customers.front() };
		std::cout << "Processing a value from the CLIENT DEQUE whose ID is '" << CUR_TASK.order_id << "'.\n";

		orders_customers.pop_front();
		std::cout << "Extraction a value from the CLIENT DEQUE. The size after the operation is '" << orders_customers.size() << "'.\n\n";
	}

	if (!orders_vip_customers.empty())
	{
		const OrderTask& CUR_TASK{ orders_vip_customers.top() };
		std::cout << "Processing a value from the VIP CLIENT DEQUE whose ID is'" << CUR_TASK.order_id << "'.\n";

		orders_vip_customers.pop();
		std::cout << "Extraction a value from the VIP CLIENT DEQUE. The size after the operation is '" << orders_vip_customers.size() << "'.\n\n";
	}

	if (!warehouse_operations.is_empty())
	{
		const OrderTask& CUR_TASK_FRONT{ warehouse_operations.peek_front() };
		const OrderTask& CUR_TASK_BACK{ warehouse_operations.peek_back() };
		std::cout << "Processing a value from the WAREHOUSE DEQUE whose ID at the beginning ig equal to '" << CUR_TASK_FRONT.order_id << "' and the end is equal to '" << CUR_TASK_BACK.order_id << "'.\n";

		warehouse_operations.pop_front();
		warehouse_operations.pop_back();

		std::cout << "Extraction a value from the WAREHOUSE DEQUE. The size after the operation is '" << warehouse_operations.size() << "'.\n\n";
	}

	std::cout << "--- Analysis of the resulting queues ---\n";
	std::cout << "size the client deque:\t" << orders_customers.size() << "\n"
		<< "size the VIP client deque:\t" << orders_vip_customers.size() << "\n"
		<< "size the warehouse deque:\t" << warehouse_operations.size() << "\n\n";

	if (!orders_customers.empty())
	{
		std::cout << "The first element from the client deque contains:\n" << orders_customers.front() << "\n";
	}
	
	if (!orders_vip_customers.empty())
	{
		std::cout << "The highest priority element from the VIP client deque contains:\n" << orders_vip_customers.top() << "\n";
	}

	if (!warehouse_operations.is_empty())
	{
		std::cout << "The first element from the warehouse deque contains:\n" << warehouse_operations.peek_front() << "\n"
			<< "The last element from the client deque contains:\n" << warehouse_operations.peek_back() << "\n";
	}
}

void LabRunner::run_lab_hash()
{
	std::cout << "*** Starting lab on a HASH ***\n";

	const size_t DATA_SIZE{ 10000 };
	const size_t MIN_STR_LEN{ 3 };
	const size_t MAX_STR_LEN{ 25 };

	std::vector<UserSession> test_data;
	test_data.reserve(DATA_SIZE);

	for (size_t i = 0; i < DATA_SIZE; ++i)
	{
		const std::string token{ generate_rand_str(MIN_STR_LEN, MAX_STR_LEN) };
		test_data.emplace_back(UserSession{token, i, 1});
	}

	std::cout << "Successfully generated " << test_data.size() << " random session.\n\n";

	std::unordered_map<std::string, UserSession> hash_stl{};
	SessionCacheChaining hash_chaining{};
	SessionCacheOpenAddr hash_open_addr{};

	std::cout << "Metrics after adding " << test_data.size() << " elements!\n";
	auto logic_add_operation{ [](auto& table, auto& item) {insert_item(table, item); } };
	const Metrics RESULT_ADD_HASH_STL{ get_metrics_after_operation(hash_stl, "STL (unordered)", test_data, logic_add_operation)};
	const Metrics RESULT_ADD_HASH_CHAINING{ get_metrics_after_operation (hash_chaining, "Chaining", test_data, logic_add_operation)};
	const Metrics RESULT_ADD_HASH_OPEN_ADDR{ get_metrics_after_operation(hash_open_addr, "OpenAddr", test_data, logic_add_operation) };
	const std::vector<Metrics> METRICS_ADD_OPER{ RESULT_ADD_HASH_STL, RESULT_ADD_HASH_CHAINING, RESULT_ADD_HASH_OPEN_ADDR };
	log_hash_metrics(METRICS_ADD_OPER);

	const size_t NUM_TO_PERCENT { (test_data.size() * 25) / 100 };
	std::vector<UserSession> sampled_data{};
	std::sample(test_data.begin(), test_data.end(), std::back_inserter(sampled_data), NUM_TO_PERCENT, RandomUtils::gen);
	std::cout << "Metrics after adding duplicate " << NUM_TO_PERCENT << " elements!\n";
	
	const Metrics RESULT_DUPLICATE_HASH_STL { get_metrics_after_operation(hash_stl, "STL (unordered)", sampled_data, logic_add_operation)};
	const Metrics RESULT_DUPLICATE_HASH_CHAINING { get_metrics_after_operation(hash_chaining, "Chaining", sampled_data, logic_add_operation) };
	const Metrics RESULT_DUPLICATE_OPEN_ADDR { get_metrics_after_operation(hash_open_addr, "OpenAddr", sampled_data, logic_add_operation) };
	const std::vector<Metrics> METRICS_DUPLICATE_OPER{ RESULT_DUPLICATE_HASH_STL , RESULT_DUPLICATE_HASH_CHAINING, RESULT_DUPLICATE_OPEN_ADDR };
	log_hash_metrics(METRICS_DUPLICATE_OPER);

	std::cout << "Metrics after deleted " << NUM_TO_PERCENT << " elements!\n";
	auto logic_erase_operation{ [](auto& table, auto& item) {table.erase(item.session_token); } };
	const Metrics RESULT_ERASE_HASH_STL{get_metrics_after_operation(hash_stl, "STL (unordered)", sampled_data, logic_erase_operation)};
	const Metrics RESULT_ERASE_HASH_CHAINING{ get_metrics_after_operation(hash_chaining, "Chaining", sampled_data, logic_erase_operation) };
	const Metrics RESULT_ERASE_HASH_OPEN_ADDR{ get_metrics_after_operation(hash_open_addr, "OpenAddr", sampled_data, logic_erase_operation) };
	const std::vector<Metrics> METRICS_ERASE_OPERATION{ RESULT_ERASE_HASH_STL, RESULT_ERASE_HASH_CHAINING, RESULT_ERASE_HASH_OPEN_ADDR };
	log_hash_metrics(METRICS_ERASE_OPERATION);
}