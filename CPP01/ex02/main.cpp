#include <iostream>
#include <string>

using std::cout;

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptrStr = &str;
    std::string &adrStr = str;

    cout << "The memory address of the string variable is: " << &str << std::endl;
    std::cout << "The memory address held by stringPTR " << ptrStr<< std::endl;
    std::cout << "The memory address held by stringREF: " << &adrStr<< std::endl;

    std::cout << "The value of the string variable: " << str << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *ptrStr << std::endl;
    std::cout << "The value pointed to by stringREF: " << adrStr << std::endl;

    return 0;
}