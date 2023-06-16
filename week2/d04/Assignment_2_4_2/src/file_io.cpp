#include "../includes/device.h"
#include "../includes/file_io.h"
#include "../includes/utils.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

/*
**  This function creates a file from the g_bank global variable in csv format.
**  It is only called at the end of the program and overwrites
**  itself on each run
*/
int create_device_file(const std::vector<Device>& devices, std::string file_name)
{
    std::ofstream file(file_name);

    if(!file.is_open())
        return 1;

    for (Device device : devices)
    {
        file << std::boolalpha
            << device.id << ','
            << device.master << '\n';
    }

    file.close();
    return 0;
}

int create_register_file(const std::vector<Device>& devices, std::string file_name)
{
    std::ofstream file(file_name);

    if(!file.is_open())
        return 1;

    for (Device device : devices)
    {
        if (device.master)
            continue ;
        file << device.id << '\n';
        for (auto reg : device.reg)
            file << reg.first << ',' << reg.second << '\n';
        file << '\n';
    }
    file.close();
    return 0;
}

void create_files(const std::vector<Device>& devices)
{
    create_device_file(devices, device_file_name);
    create_register_file(devices, register_file_name);
}


void read_register(const std::vector<Device>& devices)
{
    int device_id { select_device(devices) };
    int register_id { select_register(devices, device_id) };
    std::ifstream file(register_file_name);
    
    if (!file.is_open())
    {
        std::cout << "Register file not found!\n";
        return ;
    }
    std::string line {};

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string id_str {};
        std::getline(iss, id_str, ',');
        if (std::to_string(register_id) == id_str)
        {
            std::cout << "Register_" << register_id << " values:\n";
            std::string val_str {};
            std::getline(iss, val_str, '\n');
            std::cout << std::noboolalpha << val_str;
            std::cout << '\n';
            file.close();
            return ;
        }
    }
    file.close();
    return ;
}

int ask_value()
{
    std::cout << "Enter value: ";
    int val { listen_int_input() };
    return val;
}

void write_to_register(std::vector<Device>& devices)
{
    int device_id { select_device(devices) };
    int register_id { select_register(devices, device_id) };
    int value = ask_value();

    for (auto& device : devices)
    {
        for (auto& reg : device.reg)
        {
            if (reg.first == register_id)
            {
                reg.second = value;
            }
        }
    }
    create_files(devices);
}
