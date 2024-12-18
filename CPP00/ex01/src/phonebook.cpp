#include "PhoneBook.class.hpp"

// Constructors
// default
PhoneBook::PhoneBook() : idx(0) {};


// Getters
Contact& PhoneBook::getContact(int idx)
{
    return contacts[idx];
}

short PhoneBook::getIdx() const
{
    return idx;
}


// Setters
void PhoneBook::setIdx(const short &value)
{
    this->idx = value;
}

//todo
// Methods
void PhoneBook::addContact(PhoneBook *pBook)
{

}


