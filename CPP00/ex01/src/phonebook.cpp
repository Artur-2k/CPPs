/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:02:10 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:02:11 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "phonebook.h"

//* Constructors
// default
PhoneBook::PhoneBook() : idx(0) {};

//* Getters
Contact& PhoneBook::getContact(int idx)
{
    return contacts[idx];
}

short PhoneBook::getIdx() const
{
    return idx;
}

//* Setters
void PhoneBook::setIdx(const short &value)
{
    this->idx = value;
}

//* Methods
// ADD
void PhoneBook::addContact(PhoneBook *pBook)
{
    // Getting the entry idx
    short currentIdx = pBook->getIdx();

    // Checking if the entry table is full
    if (currentIdx == 8)
        currentIdx = 0;

    // Creating a new entry
    std::cout << "\nCREATING A NEW CONTACT\n" << std::endl;

    pBook->getContact(currentIdx).set_firstName(readInput("FIRST NAME: "));
    pBook->getContact(currentIdx).set_lastName(readInput("LAST NAME: "));
    pBook->getContact(currentIdx).set_nickname(readInput("NICKNAME: "));
    pBook->getContact(currentIdx).set_phoneNumber(readInput("PHONE NUMBER: "));
    pBook->getContact(currentIdx).set_darkest_Secret(readInput("DARKEST SECRET: "));

    std::cout << "\nCONTACT CREATED\n" << std::endl;

    // Updating the entry idx
    pBook->setIdx(currentIdx + 1);
}

/*
    std::string(size, char) => cria uma string com size size e filled com char
*/
// Format (use setw and right justify next time)
std::string PhoneBook::formatString(const std::string &content)
{  
    size_t maxSize = 10;
    // Truncates 9 and places a . on the 10th character or pads if needed
    if (content.length() > maxSize)
        return content.substr(0, maxSize - 1).insert(maxSize - 1, 1, '.');
    else
        return std::string(maxSize - content.length(), ' ') + content;
}

// SEARCH
void PhoneBook::searchContact(PhoneBook *pBook)
{
    // First Prompt
    std::cout << "[ID]|[FIRST NAME]|[LAST NAME ]|[NICKNAME  ]|[PHONE     ]" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << "[ " << i + 1 << "]|[" <<  pBook->formatString(pBook->getContact(i).get_firstName()) << "]|["
                            << pBook->formatString(pBook->getContact(i).get_lastName()) << "]|["
                            << pBook->formatString(pBook->getContact(i).get_nickname()) << "]|["
                            << pBook->formatString(pBook->getContact(i).get_phoneNumber()) << "]"
                            << std::endl;
    }

    // Search by index
    std::string option;
    if (!pBook->getContact(0).get_firstName().empty())
    {
        // Reading until we get a 1~8 number
        do
        {
            option.clear();
            option = readInput("SEARCH INDEX: ");
        }
        while (!isAllDigits(option) || 1 > std::atoi(option.c_str()) || std::atoi(option.c_str()) > 8 );
        
        // If field is empty prompts a message and leaves
        pBook->getContact(std::atoi(option.c_str()) - 1).displayContact();
    }
}
