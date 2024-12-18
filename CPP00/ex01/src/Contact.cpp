#include "Contact.class.hpp"

// Getters
std::string Contact::get_firstName() const
{
    return firstName;
}

std::string Contact::get_lastName() const
{
    return lastName;
}

std::string Contact::get_phoneNumber() const
{
    return phoneNumber;
}

std::string Contact::get_nickname() const
{
    return nickname;
}

std::string Contact::get_darkest_Secret() const
{
    return darkest_Secret;
}


// Setters
void Contact::set_firstName(const std::string &value)
{
    this->firstName = value;
}

void Contact::set_lastName(const std::string &value)
{
    this->lastName = value;
}

void Contact::set_nickname(const std::string &value)
{
    this->nickname = value;
}

void Contact::set_phoneNumber(const std::string &value)
{
    this->phoneNumber = value;
}

void Contact::set_darkest_Secret(const std::string &value)
{
    this->darkest_Secret = value;
}


// Constructors
// default
Contact::Contact() : firstName(""), lastName(""), phoneNumber(""), darkest_Secret("") {}