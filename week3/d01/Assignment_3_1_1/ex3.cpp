#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <exception>

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

struct Names
{
    int id {};
    std::string name {};
};

void print_names(std::vector<Names>& names)
{
    for (Names name : names)
    {
        std::cout << name.id << ") " << name.name << '\n';
    }
}

/*
**  Asks user for an id,. Keeps asking if user inputs something that will fail
**  std::cin, like characters or max int/min int etc.
*/
int ask_id()
{
    while (true)
    {
        std::cout << "Select an id: ";
        int id {};
        std::cin >> id;
        if (!std::cin)
            clear_cin();
        else
            return id;
    }
}

void check_names(std::vector<Names>& names, int id)
{
    for (Names name : names)
    {
        if (name.id == id)
        {
            std::cout << "\nYou selected " << name.name << '\n';
            return ;
        }
    }
    throw std::range_error("Selected id is out of range!");
}

int main()
{
    std::vector<Names> name_list {
        { 0, "Aku Ankka" },
        { 1, "Tupu Ankka" },
        { 2, "Hupu Ankka" },
        { 3, "Lupu Ankka" }
    };

    while (true)
    {
        std::cout << "ID\tName\n";
        print_names(name_list);
        int id { ask_id() };

        /*
        **  Loops through the names and checks for a matching id in the list. If not
        **  found, it will throw a range_error
        */
        try {
            check_names(name_list, id);
        }
        catch (std::range_error& e) {
            std::cout << "Error: " << e.what() << '\n';
            continue ;
        }
        return 0;
    }
    
    return 0;
}
