#pragma once
#include <laboratory 2/IPowerManaged.h>
#include <laboratory 2/IConnectable.h>
#include <laboratory 2/ISensor.h>

void optimize_battery(IPowerManaged& device);

void sync_sensor_data(IConnectable& network_device, ISensor& sensor);