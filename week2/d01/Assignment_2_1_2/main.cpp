#include <algorithm>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <random>
#include <vector>

void print(const int& n)
{
    std::cout << n << ' ';
}

/*
**  Generates and returns random sized vector with random values
*/
std::vector<int> random_vector()
{
    std::mt19937 mt { std::random_device{}() };

    std::uniform_int_distribution vect_range{ 1, 15 };
    std::uniform_int_distribution value_range{-10, 10};
    int vect_size = vect_range(mt);
    std::vector<int> vect(static_cast<size_t>(vect_size));

    for (auto& i : vect)
    {
        i = value_range(mt);
    }
    return vect;
}

/*
**  Exercise 6
**  Prints smallest and greatest values from array (also finds them)
*/
void print_smallest_and_greatest(std::vector<int> vect)
{
    int smallest = *vect.begin();
    int greatest = smallest;
    for (auto it = vect.begin(); it != vect.end(); ++it)
    {
        if (*it < smallest)
            smallest = *it;
        if (*it > greatest)
            greatest = *it;
    }
    std::cout  << smallest << " is smallest\n";
    std::cout << greatest << " is greatest\n";
}

int main()
{
    //  Exercise 1
    std::cout << "Exercise 1:\n";
    std::vector<int> vect { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout << "Origianl vector:\n";
    std::for_each(vect.begin(), vect.end(), print);

    [[maybe_unused]] auto it = std::partition(vect.begin(), vect.end(),
    [](int i) {
        return i % 2 == 0;
    });
    std::cout << "\nPartitioned vector:\n";
    std::for_each(vect.begin(), vect.end(), print);
    std::cout << '\n';
    
    //  Exercise 2
    std::cout << "\nExercise 2:\nIntersections for vectors:\n";
    std::vector<int> v1 { 2, 4, 8, 32, 5, 67, 32, 1, 56 };
    std::vector<int> v2 { 12 , 4, 6, 3, 5, 554, 84 };
    std::for_each(v1.begin(), v1.end(), print);
    std::cout << "\nAnd\n";
    std::for_each(vect.begin(), vect.end(), print);
    std::cout << "\nAre:\n";
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    std::vector<int> v_intersection {};
    std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),
        std::back_inserter(v_intersection));
    std::for_each(v_intersection.begin(), v_intersection.end(), print);
    std::cout << '\n';

    //  Exercise 3
    std::cout << "\nExercise 3:\n";
    std::vector<int> v3 { 2, 81, 27, 19, 3, 84, 67, 9, 33, -2 };
    std::cout << "Vector before rotation:\n";
    for_each(v3.begin(), v3.end(), print);
    std::rotate(v3.rbegin(), v3.rbegin() + 3, v3.rend());
    std::cout << "Vector after rotating to the right by 3:\n";
    for_each(v3.begin(), v3.end(), print);
    std::cout << '\n';

    //  Exercise 4
    std::cout << "\nExercise 4:\n";
    std::list<int> li { 5, 3, 7, 5, 9, 8, 3, 0, 0, 8};
    std::cout << "In the following list:\n";
    std::for_each(li.begin(), li.end( ), print);
    auto i1 = std::adjacent_find(li.begin(), li.end());
    if (i1 == li.end())
        std::cout << "\nThere is no adjacent numbers!\n";
    else
        std::cout << "\nFirst two adjacent numbers are: " << *i1 << "'s\n";

    // Exercise 5
    std::cout << "\nExercise 5:\nRandom vector:\n";
    std::vector<int> rv { random_vector() };
    std::for_each(rv.begin(), rv.end(), print);
    std::cout << '\n';

    //  Exercise 6
    std::cout << "\nExercise 6:\n";
    std::cout << "In the random vector: \n";
    std::for_each(rv.begin(), rv.end(), print);
    std::cout << '\n';
    print_smallest_and_greatest(rv);

    return 0;
}
