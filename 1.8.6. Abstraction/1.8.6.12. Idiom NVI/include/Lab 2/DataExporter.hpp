#pragma once

class DataExporter
{
public:
	void export_data();
	virtual ~DataExporter() = default;
protected:
	virtual void format_data() const;
};
