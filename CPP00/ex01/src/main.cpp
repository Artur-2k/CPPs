#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>  

void printIntro();

bool isAllDigits(const std::string &input)
{
    size_t len = input.length();
    for (size_t i = 0; i < len; i++)
    {
        if (!isdigit(input[i]))
            return false;
    }
    return true;
}

bool isAllSpaces(const std::string &input)
{
    size_t len = input.length();
    bool flag = false;
    for (size_t i = 0; i < len; i++)
    {
        if (!isspace(input[i]))
            return false;
    }
    return true; 
}

void replaceTabsToSpaces(std::string &input)
{
    size_t len = input.length();
    for (size_t i = 0; i < len; i++)
    {
        if (isspace(input[i]))
            input[i] = ' ';
    }
}


std::string readInput(const std::string &prompt)
{
    std::string input;
    do
    {
        std::cout << prompt;
        getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << "\nEOF GOODBYE!" << std::endl;
            exit(0);
        }
        if (prompt == "PHONE NUMBER: " && !isAllDigits(input))
        {
            std::cout << "PHONE NUMBER MUST ONLY CONTAIN NUMBERS" << std::endl;
            input.clear();
            continue;
        }
        if (isAllSpaces(input))
        {
            std::cout << "YOU MUST WRITE SOMETHIG OTHER THAN SPACES" << std::endl;
            input.clear();
            continue;
        }
    } while (input.empty());
    replaceTabsToSpaces(input);
    return input;
}

void addEntry(PhoneBook *pBook)
{
    // Getting the entry idx
    short currentIdx = pBook->getIdx();

    // Checking if the entry table is full
    if (currentIdx == 8)
        currentIdx = 0;

    // Creating a new entry
    std::cout << "\nCREATING A NEW CONTACT" << std::endl;

    pBook->getContact(currentIdx).set_firstName(readInput("FIRST NAME: "));
    pBook->getContact(currentIdx).set_lastName(readInput("LAST NAME: "));
    pBook->getContact(currentIdx).set_nickname(readInput("NICKNAME: "));
    pBook->getContact(currentIdx).set_phoneNumber(readInput("PHONE NUMBER: "));
    pBook->getContact(currentIdx).set_darkest_Secret(readInput("DARKEST SECRET: "));

    std::cout << "CONTACT CREATED" << std::endl;

    // Updating the entry idx
    pBook->setIdx(currentIdx + 1);
}

/*
    std::string(size, char) => cria uma string com size size e filled com char
*/
static std::string formatString(const std::string &content)
{
    int maxSize = 10;
    // Truncates 9 and places a . on the 10th character or pads if needed
    if (content.length() > maxSize)
        return content.substr(0, maxSize - 1).insert(maxSize - 1, 1, '.');
    else
        return content + std::string(maxSize - content.length(), ' ');
}

void search(PhoneBook *pBook)
{
    
    std::cout << "[ID]|[First Name]|[Last Name ]|[Nickname  ]|[Phone     ]" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << "[ " << i + 1 << "]|[" <<  formatString(pBook->getContact(i).get_firstName()) << "]|["
                            << formatString(pBook->getContact(i).get_lastName()) << "]|["
                            << formatString(pBook->getContact(i).get_nickname()) << "]|["
                            << formatString(pBook->getContact(i).get_phoneNumber()) << "]"
                            << std::endl;
    } 

    //todo
    // search by index
}

 

int main()
{
    printIntro();

    std::string input;
    PhoneBook pBook;

    while (true)
    {
        input = readInput("ENTER YOUR COMMMAND: ");

        if (input == "ADD")
            addEntry(&pBook);
            // pBook.addContact();
        else if (input == "SEARCH")
            search(&pBook);
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

void printIntro()
{
    std::cout << "****************************************" << std::endl;
    std::cout << "|                                      |" << std::endl;
    std::cout << "|              Phonebook               |" << std::endl;
    std::cout << "|                                      |" << std::endl;
    std::cout << "|        CAPSLOCK IS STUCK LOL         |" << std::endl;
    std::cout << "|                                      |" << std::endl;
    std::cout << "|TYPE ONE OF THE FOLLOWING TO USE      |" << std::endl;
    std::cout << "|YOUR PHONEBOOK:                       |" << std::endl;
    std::cout << "|                                      |" << std::endl;
    std::cout << "|ADD     (MAX 8 CONTACTS)              |" << std::endl;
    std::cout << "|SEARCH  (DISPLAY AND SEARCH BY INDEX) |" << std::endl;
    std::cout << "|EXIT    (TO CLOSE)                    |" << std::endl;
    std::cout << "****************************************" << std::endl;

}
