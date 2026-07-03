#pragma once
#include "Lab2/DataExporter.hpp"

class JsonExporter : public DataExporter
{
public:
	~JsonExporter() override = default;
protected:
	void format_data() const override;
};