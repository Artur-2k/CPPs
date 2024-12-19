#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include "phonebook.h"

int main()
{
    printIntro();

    std::string input;
    PhoneBook pBook;

    while (true)
    {
        input = readInput("ENTER YOUR COMMMAND: ");

        if (input == "ADD")
            pBook.addContact(&pBook);
        else if (input == "SEARCH")
            pBook.searchContact(&pBook);
        else if (input == "EXIT")
        {
            std::cout << "EXIT GOODBYE!" << std::endl;
            return (0);
        }
        else
            std::cout << "HUMM.... WHAT?" << std::endl;
        input.clear();
    }
    return 0;
}
