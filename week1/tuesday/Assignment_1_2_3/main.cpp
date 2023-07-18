/*
**  This program prompts user for the amount of students, and for each, asks
**  name, age and grade. It then calculates and prints the average grade
**  and name of the highest graded student.
*/

#include <iostream>
#include <limits>
#include <vector>

struct Student
{
    std::string name {};
    int         age {};
    int         grade {};
};

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string get_name()
{
    std::string name {};
    std::cout << "Enter the student's name: ";
    std::getline(std::cin >> std::ws, name);
    return name;
}

int get_age(std::string name)
{

    int age { 0 };
    int min_age { 0 };
    int max_age { 125 };
    while (true)
    {
        std::cout << "Enter " << name << "'s age: ";
        std::cin >> age;
        if (!std::cin)
            clear_cin();
        if (age > min_age && age < max_age)
            return age;
        std::cout << "Invalid age! Try again... :)\n";
    }
}

int get_grade(std::string name)
{
    int grade { 0 };
    while (true)
    {
        std::cout << "Enter " << name << "'s grade (1-5): ";
        std::cin >> grade;
        if (!std::cin)
            clear_cin();
        if (grade > 0 && grade <= 5)
            return grade;
        std::cout << "Invalid grade! Try again... :)\n";
    }
}

/*
**  Populates the vector of type struct Student and returns the populated vector
*/
std::vector<Student> create_database(int amount)
{
    std::vector<Student> students;

    for (size_t i = 0; i < static_cast<size_t>(amount); ++i)
    {
        Student student {};
        student.name = get_name();
        student.age = get_age(student.name);
        student.grade = get_grade(student.name);
        
        students.push_back(student);

        std::cout << '\n'; //New line after getting the user input
    }
    return students;
}

/*
**  Loops through student vector and finds the highest graded student.
**  Doesn't check for ties, returns the name of the first encountered
*/
std::string find_primus(std::vector<Student> students)
{
    std::string name {};
    int highest_grade { 0 };

    for (Student student : students)
    {
        if (student.grade > highest_grade)
        {
            highest_grade = student.grade;
            name = student.name;
        }
    }
    return name;
}

/*
**  Calculates the sum of all the grades in the student vector
**  and returns the average of it based on the vector size.
*/
double calc_avg_grade(std::vector<Student> students)
{
    int sum { 0 };
    for (Student student : students)
    {
        sum += student.grade;
    }
    return sum / static_cast<double>(students.size());
}

int get_student_amount()
{
    int amount { 0 };
    while (true)
    {
        std::cout << "Enter the amount of students: ";
        std::cin >> amount;
        if (!std::cin)
            clear_cin();
        if (amount > 0)
            return amount;
        std::cout << "What was that? Try again...\n";
    }
}

int main()
{
    int student_amount { get_student_amount() };
    std::vector<Student> students { create_database(student_amount) };

    std::cout.precision(3);
    std::cout << "Average grade among the students is: "
        << calc_avg_grade(students) << '\n';
    std::cout << "Student with the highest grade is: "
        << find_primus(students) << '\n';
    return 0;
}
