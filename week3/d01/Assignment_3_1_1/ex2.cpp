#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define LIST_ERROR_CODE -1
#define FILE_ERROR_CODE -2


/*
**  Returns -2 if file can't be opened, -1 if there's no int elements in the
**  list and if there is a list, sorts the list, prints the highest value
**  and returns 0
*/
int print_max_val_from_file(std::string file_name)
{
    std::ifstream file(file_name);
    if (!file.is_open())
        return -2;
    int i {};
    std::vector<int> vect;
    while (file >> i)
    {
        vect.push_back(i);
    }
    if (vect.empty())
    {
        file.close();
        return -1;
    }
    std::partial_sort(vect.begin(), vect.begin() +1, vect.end(), std::greater<int>());
    std::cout << "Highest value is : " << *vect.begin() << '\n';
    file.close();
    return 0;
}

/*
**  Loops until the program gets a filename that has a list in it, otherwise
**  prints messages to cout and loops for a new filename
*/
int main(int argc, char* argv[])
{
    bool get_file_name = false;
    while (true)
    {
        std::string file_name {};
        if (argc != 2 || get_file_name)
        {
            std::cout << "Enter the filename that has the list:\n";
            std::getline(std::cin >> std::ws, file_name);
        }
        else
        {
            file_name = static_cast<std::string>(argv[1]);
        }

        int result {print_max_val_from_file(file_name)};

        if (result == FILE_ERROR_CODE)
        {
            std::cout << "File not found!\n";
            get_file_name = true;
            continue ;
        }
        else if (result == LIST_ERROR_CODE)
        {
            std::cout << "No list inside the file!\n";
            get_file_name = true;
            continue ;
        }
        return 0;
    }
}
