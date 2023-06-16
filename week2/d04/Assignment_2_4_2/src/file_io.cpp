#include "../includes/device.h"
#include "../includes/file_io.h"
#include <algorithm>
#include <fstream>
#include <iostream>
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

    file << "Device id,Master\n";
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

    file << "Device id, Register address, Register value\n";
    for (Device device : devices)
    {
        if (device.master)
            continue ;
        file << device.id << '\n';
        for (auto reg : device.reg)
        {
            file << reg.first << ',';
            for(auto val = reg.second.begin(); val != reg.second.end(); ++val)
            {
                file << *val;
                if (val != reg.second.end())
                    file << ',';
            }
            file << '\n';
        }
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
    std::ifstream file(device_file_name);
    
    if (!file.is_open())
    {
        std::cout << "\n";
    }
}

void write_to_register(const std::vector<Device>& devices)
{
    
}
/*
**  This function opens the bank_db file and loops through it line by line.
**  Based on the formatting and order of data in the file, we can take every
**  part and place it to our User struct in the correct member. After each
**  User, we push it to our global g_bank vector that holds all Users. We also
**  update the g_highest_user and g_highest_acc to keep them up to date.
*/
/*
void load_file()
{
    std::string file_path{ "bank_db" };
    std::ifstream file(file_path);

    if (!file)
        return ;

    std::string line {};
    User client;
    bool reading_accounts = false;

    while (std::getline(file, line))
    {
        if (line.empty()) {
            reading_accounts = false;
            g_bank.push_back(client);
            client = User();
        }
        else if (!reading_accounts)
        {
            std::istringstream iss(line);
            std::string customer_num_str {};
            std::getline(iss, customer_num_str, ',');
            std::getline(iss, client.name, ',');
            std::getline(iss, client.address, ',');
            std::getline(iss, client.phone_num);
            client.customer_num = std::stoi(customer_num_str);

            if (client.customer_num > g_highest_user)
                g_highest_user = client.customer_num;

            reading_accounts = true;
        }
        else
        {
            std::istringstream iss(line);
            Account acc {};
            std::string acc__num_str {};
            std::string balance_str {};
            std::getline(iss, acc__num_str, ',');
            std::getline(iss, balance_str);
            acc.account_num = std::stoi(acc__num_str);
            acc.balance = std::stoi(balance_str);
            client.accounts.push_back(acc);

            if (acc.account_num > g_highest_acc)
                g_highest_acc = acc.account_num;
        }

    }
    file.close();
}
*/
