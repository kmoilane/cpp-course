#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <vector>
#include <map>

struct Device
{
    int id {};
    bool master {false};
    std::map<int, int> reg {};
};

std::vector<Device> create_devices(int& id, int& reg_id, int amount, bool master);
Device create_devices(int& id, int& reg_id, bool master);
void print_devices(const std::vector<Device>& devices);
int select_device(const std::vector<Device>& devices);
int slave_count(const std::vector<Device>& devices);
int select_register(const std::vector<Device>& devices, int device_id);

#endif
