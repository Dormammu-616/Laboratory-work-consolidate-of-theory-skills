#pragma once
#include <forward_list>
#include <ostream>
#include "ProductUpdate.h"

inline std::ostream& operator<<(std::ostream& os, const std::forward_list<ProductUpdate>& list);

namespace LabRunner
{
	void run_lab_forward_list();
	void run_lab_stack();
	void run_lab_queue();
	void run_lab_hash();
}