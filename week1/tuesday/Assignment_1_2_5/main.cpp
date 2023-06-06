/*
** Simple library management program. You can add, remove, display books
** and see if there's any left to be loaned.
*/

#include <iostream>
#include <string>
#include <vector>

struct Book
{
    std::string title {};
    std::string author {};
    long long   isbn {};
    int         year {};
    int         quantity {};
};

std::vector<Book> library;

/*
** Displays data of book based on it's title
*/
void display_book(std::string title)
{
    size_t i { 0 };
    while (i < library.size())
    {
        if (title == library[i].title)
        {
            std::cout << "Title:\t\t" << library[i].title << '\n';
            std::cout << "Author:\t\t" << library[i].author << '\n';
            std::cout << "ISBN:\t\t" << library[i].isbn << '\n';
            std::cout << "Year:\t\t" << library[i].year << '\n';
            std::cout << "Quantity:\t" << library[i].quantity << '\n';
            return ;
        }
        ++i;
    }
    std::cout << "Book not found!\n";
}

/*
** Adds book to vector
*/
void add_book(Book book)
{
    library.push_back(book);
    library.shrink_to_fit();
}

/*
** Removes book based on it's isbn if it exists.
*/
void remove_book(long long isbn)
{
    for (size_t i = 0; i < library.size(); ++i)
    {
        if (isbn == library[i].isbn)
        {
            library.erase(library.begin() + static_cast<int>(i));
            library.shrink_to_fit();
            std::cout << "Book removed!\n";
            return ;
        }
    }
    std::cout << "Book not found!\n";
}


/*
** Returns true if book is found and there's over 0 quantity of books
*/
bool is_loanable(long long isbn)
{
    for (size_t i = 0; i < library.size(); ++i)
    {
        if (library[i].isbn == isbn)
        {
            if (library[i].quantity > 0)
                return true;
        }
    }
    return false;
}

/*
** Tests to see if this library works at all
*/
void some_tests()
{
    // Add some books to library
    add_book(
        Book("Extreme Ownership", "Jocko Willink", 1000000000000, 2015, 3)
    );
    add_book(
        Book("Hyvän ja pahan tuolla puolen", "Friedrich Nietzsche",
        1000000000001, 1886, 0)
    );
    add_book(
        Book("How to Win Friends and Influence People", "Dale Carnegie",
        1000000000002, 1936, 2)
    );

    // Testing to display books
    display_book("Juoppuhullun päiväkirja"); // Should not be found
    display_book("Extreme Ownership"); // Should be found

    // Testing to see if book is loanable
    if (is_loanable(1000000000000)) // Should be loanable
        std::cout << "Is loanable!\n";
    else
        std::cout << "Is not loanable!\n";
    if (is_loanable(1000000000001)) // Should not be loanable
        std::cout << "Is loanable!\n";
    else
        std::cout << "Is not loanable!\n";
    
    // Remove book
    remove_book(1000000000000); // Should remove the Extreme Ownership

    // Test to see removed book
    if (is_loanable(1000000000000)) // Should not be loanable
        std::cout << "Is loanable!\n";
    else
        std::cout << "Is not loanable!\n";
}

int main()
{
    some_tests();
    return 0;
}
