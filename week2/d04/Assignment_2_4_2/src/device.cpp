#include "../includes/device.h"
#include "../includes/utils.h"
#include <iostream>
#include <vector>
#include <string>

Device create_devices(int& id, int& reg_id, bool master)
{
    if (master)
        return {++id, master};
    else
    {
        Device new_device {++id, master};
        int regs { random_num(2, 5) };
        for (int i = 0; i < regs; ++i, ++reg_id)
            new_device.reg[reg_id] = random_num(0, 1);
        return new_device;
    }
}

std::vector<Device> create_devices(int& id, int& reg_id, int amount, bool master)
{
    std::vector<Device> devices {};
    for (int i = 0; i < amount; ++i)
    {
        devices.push_back(create_devices(id, reg_id, master));
    }
    return devices;
}

void print_registers(const std::vector<Device>& devices, int device_id)
{
    for (Device device : devices)
    {
        if (device_id == device.id)
        {
            for (auto reg : device.reg)
            {
                std::cout << reg.first << ") register_" << reg.first << '\n';
            }
        }
    }
}

void print_devices(const std::vector<Device>& devices)
{
    int i { 1 };
    for (Device device : devices)
    {
        if (!device.master)
            std::cout << device.id << ") Device_" << device.id << '\n';
        ++i;
    }
}

int slave_count(const std::vector<Device>& devices)
{
    int count { 0 };
    for (Device device : devices)
    {
        if (device.master)
            continue;
        ++count;
    }
    return count;
}

int select_register(const std::vector<Device>& devices, int device_id)
{
    while (true)
    {
        std::cout << "\nSelect register:\n";
        print_registers(devices, device_id);
        int register_id { listen_int_input() };
        if (register_id == 0)
        {
            std::cout << "\nInvalid register number!\n";
            continue ;
        }
        return register_id;
    }
}

int select_device(const std::vector<Device>& devices)
{
    while (true)
    {
        std::cout << "\nSelect device:\n";
        print_devices(devices);
        int device_id { validate_int_input(1, slave_count(devices)) };
        if (device_id == 0)
        {
            std::cout << "\nInvalid device number!\n";
            continue ;
        }
        return device_id;
    }
}
