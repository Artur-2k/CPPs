#include <stack>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

// Mover para uma classe de utils
#include <algorithm>
bool containsOnlyAllowed(const std::string& str, const std::string allowed)
{
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (allowed.find(str[i]) == std::string::npos)
            return false;
    }
    return true;
}

int main(int ac, char *av[])
{
try
{
    // 2 3 +
    if  (ac != 2) throw std::runtime_error("Error: Bad program arguments");

    std::stack<double> stk;
    std::stringstream ss(av[1]);
    std::string token;
    short n = 0;
    while(ss >> token)
    {
        if (ss.fail()) throw std::runtime_error("Error: internal error on tokenizer");

        if (token.length() != 1) throw std::runtime_error("Error: invalid format");


        if (std::isdigit(*token.data()))
        // add digit
        {
            if (n == 2)
                throw std::runtime_error("Error: too many operands");
            ++n;
            double num = convertToDouble(token); // todo pegar do ex00
            stk.push(num);
        }
        else if (token.find_first_of("+-*/") != std::string::npos)
        {
            if (n != 2)
                throw std::runtime_error("Error: not enough operands");
            
            double num1 = stk.top();
            stk.pop();
            double num2 =  stk.top();
            stk.pop();

            if (token[0] == '+')
                stk.push(num1 + num2);
            else if(token[0] == '-')
                stk.push(num1 - num2);
            else if(token[0] == '*')
                stk.push(num1 * num2);
            else
            {
                if (num2 == 0) throw std::runtime_error("Error: division by zero");
                stk.push(num1 / num2);
            }
        }
        else throw std::runtime_error("Error: invalid operands/operators");
    }
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
    return 0;
}