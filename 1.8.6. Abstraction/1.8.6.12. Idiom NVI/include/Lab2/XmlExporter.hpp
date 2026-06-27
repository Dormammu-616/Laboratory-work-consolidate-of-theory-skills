#pragma once
#include "Lab2/DataExporter.hpp"

class XmlExporter : public DataExporter
{
public:
	~XmlExporter() override = default;
protected:
	void format_data() const override;
};