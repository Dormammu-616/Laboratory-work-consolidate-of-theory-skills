#pragma once
#include "lab1/SerializableConcept.hpp"
#include <iostream>

namespace lab1
{
	template <lab1::Serializable T>
	void export_to_json(const T& obj)
	{
		std::string json_data{ obj.serialize() };

		std::cout << "[export_to_json] Data exported to JSON.\n";
	}
}