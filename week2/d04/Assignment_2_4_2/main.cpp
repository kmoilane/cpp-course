#include "includes/device.h"
#include "includes/file_io.h"
#include "includes/utils.h"
#include <fstream>
#include <iostream>
#include <vector>

int modbus_ui(std::vector<Device>& devices)
{
    while (true)
    {
        std::cout << "1) Read\n";
        std::cout << "2) Write\n";
        std::cout << "3) Quit\n";
        int option { validate_int_input(1, 3) };
        switch (option)
        {
            case 1:
                read_register(devices);
                break ;
            case 2:
                write_to_register(devices);
                break ;
            case 3:
                return 0;
            default :
                std::cout << "\nInvalid option!\n";
        }
    }   
}

int main()
{
    static int id { 0 };
    static int reg_id { 100 };
    std::vector<Device> devices{create_devices(id, reg_id, 10, false)};
    devices.push_back(create_devices(id, reg_id, true));
    create_files(devices);
    std::cout << "Modbus\n\nI am the master now!\n";
    while (true)
    {
        if (modbus_ui(devices) == 0)
            return 0;
    }
}
