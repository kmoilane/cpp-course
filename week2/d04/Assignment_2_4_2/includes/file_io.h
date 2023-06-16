#ifndef FILE_IO_H
#define FILE_IO_H

#include "device.h"
#include <string>
#include <vector>

int create_device_file(const std::vector<Device>& devices, std::string file_name);
int create_register_file(const std::vector<Device>& devices, std::string file_name);
void create_files(const std::vector<Device>& devices);
void read_register(const std::vector<Device>& devices);
void write_to_register(const std::vector<Device>& devices);

inline const static std::string device_file_name { "devices.csv" };
inline const static std::string register_file_name { "registers.csv" };

#endif
