#include <algorithm>
#include <array>
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>

/*
**  Exercise 1
**  Prints the integer from reference provided by for_each loop
*/
void print(const int& n)
{
    std::cout << n << ' ';
}

/*
**  Exercise 2
**  Checks the Exercise 1 array for element n and returns true if found
*/
bool is_in_array(std::array<int, 10> arr, int n)
{
    for (int elem : arr)
    {
        if (elem == n)
            return true;
    }
    return false;
}

/*
**  Exercie 3
**  Calculates and returns the sum of every element in int vector
*/
int calc_vect_sum(std::vector<int> vect)
{
    int sum {};
    for (int n : vect)
        sum += n;

    return sum;
}

/*
**  Exercise 4
**  Calculates the product (multpilication) of every element in the vector
**  and returns it to the caller.
*/
int calc_vect_product(std::vector<int> vect)
{
    int product { 1 };
    for (int n : vect)
        product *= n;

    return product;
}

/*
**  Exercise 5
**  Ask user for a vector size and return it..
*/
int prompt_vect_size()
{
    int size {};
    std::cout << "Enter vector size: ";
    std::cin >> size;
    return size;
}

/*
**  Exercise 6
**  Prints smallest and greatest values from std::list (also finds them)
*/
void print_smallest_and_greatest(std::list<int> li)
{
    int smallest = *li.begin();
    int greatest = smallest;
    for (std::list<int>::iterator it = li.begin(); it != li.end(); ++it)
    {
        if (*it < smallest)
            smallest = *it;
        if (*it > greatest)
            greatest = *it;
    }
    std::cout  << smallest << " is smallest\n";
    std::cout << greatest << " is greatest\n";
}

/*
**  Exercise 7
**  Finds every element in the vector that has same value as n. Erases the
**  element and prints found msg.
*/
void search_and_destroy(std::vector<int>& vect, int n)
{
    for (auto it = vect.begin(); it != vect.end(); ++it)
    {
        if (*it == n)
        {
            vect.erase(it);
            std::cout << n << " found and removed!\n";
        }
    }
}

int main()
{
    //  Exercise 1
    std::array<int, 10> arr{ 2, 8, 46, 9, 17, 29, 4, 75, 11, 36 };
    std::cout << "Exercise 1:\n";
    std::for_each(arr.begin(), arr.end(), print);
    std::cout << std::endl;

    //  Exercise 2
    std::cout << "\nExercise 2:\n";
    std::cout << std::boolalpha;
    std::cout << "9 is in array? " << is_in_array(arr, 9) << '\n';
    std::cout << "1 is in array? " << is_in_array(arr, 1) << '\n';

    //  Exercise 3
    std::vector<int> vect { 3, 6, 9, 10, 38, 73, 27 };
    std::cout << "\nExercise 3:\n";
    std::cout << "3 + 6 + 9 + 10 + 38 + 73 + 27 = ";
    std::cout << calc_vect_sum(vect) << std::endl;

    //  Exercise 4
    std::cout << "\nExercise 4:\n";
    std::cout << "3 * 6 * 9 * 10 * 38 * 73 * 27 = ";
    std::cout << calc_vect_product(vect) << std::endl;

    //  Exercise 5
    std::cout << "\nExercise 5:\n";
    int vect_size { prompt_vect_size() };
    std::vector<int> vect2(static_cast<size_t>(vect_size));
    std::cout << "New vector size: " << vect2.size() << std::endl;

    //  Exercise 6
    std::cout << "\nExercise 6:\n";
    std::cout << "In the following list: \n";
    std::list<int> li = { 2, 55, 42, -12, 98 };
    std::for_each(li.begin(), li.end(), print);
    std::cout << '\n';
    print_smallest_and_greatest(li);

    //  Exercise 7
    std::cout << "\nExercise 7:\n";
    std::cout << "Vector before removing number 5's:\n";
    std::vector<int> vect3 { 3, 5, 9, 5, 38, 3, 5, 27 };
    std::for_each(vect3.begin(), vect3.end(), print);
    std::cout << "\nSearch and destroy 5's...\n";
    search_and_destroy(vect3, 5);
    std::cout << "Same vector after removing number 5's:\n";
    std::for_each(vect3.begin(), vect3.end(), print);
    std::cout << '\n';
}
