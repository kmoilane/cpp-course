#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int random_num(int min, int max)
{
    std::mt19937 mt { std::random_device{}() };

    std::uniform_int_distribution rand_range{ min, max };

    return rand_range(mt);
}

/*
**  This program has a list of users that is rotated random amount of times,
**  but at least once and at most the size of student list - 1 to the right.
**  This way you don't get to review yourself, and two people wont review each
**  other at the same time.
*/
int main()
{
    std::vector<std::string> v1 { "Erkki Esimerkki", "Maija Mehiläinen",
    "Roope Ankka", "Kroisos Pennonen", "Kulta Into Pii", "Aku Ankka" };
    std::mt19937 mt { std::random_device{}() };
    std::shuffle(v1.begin(), v1.end(), mt);

    int list_size = static_cast<int>(v1.size());
    int rotate_amount {};
    std::vector<std::string> v2 { v1 };
    while (true)
    {
        rotate_amount = random_num(1, list_size - 1);
        if ((rotate_amount == (list_size / 2)) && (list_size % 2 == 0))
            continue ;
        else break ;
    }
    std::rotate(v2.rbegin(), v2.rbegin() + rotate_amount, v2.rend());

    for (size_t i = 0; i < v1.size(); ++i)
    {
        std::cout << v1[i] << " -> " << v2[i] << '\n';
    }

    return 0;
}
