#include "RNP.hpp"

std::string RNP::_validOps = "+-*/";

RNP::RNP() {};
RNP::RNP(RNP &other) { (void)other; }
RNP RNP::operator=(const RNP &other) { (void)other;return *this; };
RNP::~RNP() {};


double RNP::_resolveOperator(std::deque<double>& stack, char op)
{
    if (stack.size() < 2)
    {
        throw std::runtime_error("Not enough parameters on operation " + std::string(1, op));
    } 
    double b = stack.back();
    stack.pop_back();
    double a = stack.back();
    stack.pop_back();

    switch (op)
    {
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    case '*':
        return (a * b);
    case '/':
        if (b == 0)
        {
            throw std::runtime_error("Division by zero");
        }
        return (a / b);
    default:
        throw std::runtime_error("Invalid operator");
    }
}

double RNP::calculate(std::string& expression)
{
    std::deque<double>_stack;

    std::stringstream ss(expression);
    ss >> std::noskipws;
    char token;

    while (ss >> token)
    {
        if (token == ' ')
        {
            continue;
        } 

        if (ss.peek() != ' ' && !ss.eof())
        {
            throw std::runtime_error("Invalid separator");
        }
        ss.ignore();
        
        if (isdigit(token))
        {
            _stack.push_back(static_cast<double>(token - '0'));
        }
        else if (_validOps.find(token) != std::string::npos)
        {
            _stack.push_back(_resolveOperator(_stack, token));
        }
        else 
        {
            throw std::runtime_error("Invalid arguments");
        }
    }

    if (_stack.size() != 1)
    {
        throw std::runtime_error("Invalid expression");
    }

    return _stack.front();
}