/*
**  Create a program with a class that has a private member variable. Implement
**  getter and setter functions for the private variable and demonstrate how
**  the lifetime of the private variable is controlled by the class.
*/

#include <iostream>

struct My_struct
{
    private:
        int val {}; // This can be only accessed within this struct.
                    // We can declare a function that returns it's value
                    // or changes it's value, that can be public so it
                    // can be indirectly accessed.

    public:
        My_struct()
        {
            val = 0; 
        }

        int get_val()
        {
            return val;
        }

        void set_val(int value)
        {
            val = value;
        }
};

int main()
{
    My_struct my_struct;
    std::cout << my_struct.get_val() << std::endl;

    my_struct.set_val(10);
    std::cout << my_struct.get_val() << std::endl;

    return 0;
}
