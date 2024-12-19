#ifndef PHONEBOOK_H 
#define PHONEBOOK_H

#include <iostream> // cin cout
#include <string> // string
#include <cstdlib> // exit


void printIntro();
bool isAllDigits(const std::string &input);
bool isAllSpaces(const std::string &input);
void replaceWStoSpaces(std::string &input);
std::string readInput(const std::string &prompt);

#endif