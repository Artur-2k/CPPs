#include "phonebook.h"

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

bool isAllPrintable(const std::string &input)
{
    size_t len = input.length();
    for (size_t i = 0; i < len; i++)
    {
        if (!isprint(input[i]))
            return false;
    }
    return true;
}

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
    for (size_t i = 0; i < len; i++)
    {
        if (!isspace(input[i]))
            return false;
    }
    return true; 
}

void replaceWStoSpaces(std::string &input)
{
    size_t len = input.length();
    for (size_t i = 0; i < len; i++)
    {
        if (isspace(input[i]))
            input[i] = ' ';
    }
}

// Reads until something is filled if reading the phone number asks for 9 numbers
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
            input.clear();
            exit(0);
        }
        if (!isAllPrintable(input))
        {
            std::cout << "CHOOSE BETTER CHARACTERS" << std::endl;
            input.clear();
            continue;
        }
        if (isAllSpaces(input))
        {
            std::cout << "YOU MUST WRITE SOMETHIG OTHER THAN SPACES" << std::endl;
            input.clear();
            continue;
        }
        if (prompt == "PHONE NUMBER: " && (input.length() != 9 || !isAllDigits(input)))
        {
            std::cout << "PHONE NUMBER MUST CONTAIN 9 NUMBERS" << std::endl;
            input.clear();
            continue;
        }
    } while (input.empty());
    replaceWStoSpaces(input);
    return input;
}