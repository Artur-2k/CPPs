#ifndef PHONE_BOOK_CLASS
#define PHONE_BOOK_CLASS

#include <iostream>
#include <string>
#include "Contact.class.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        short idx;

    public:
        // Construtors
        // default
        PhoneBook();

        // Getters
        Contact& getContact(int idx);
        short getIdx() const;

        // Setters
        void setIdx(const short &value);

        // Methods
        // ADD
        void addContact(PhoneBook *pBook);
        // SEARCH
        void searchContact(PhoneBook *pBook);
        // Format
        static std::string formatString(const std::string &content);
};

#endif