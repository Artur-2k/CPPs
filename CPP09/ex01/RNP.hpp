#pragma once

#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <cctype>
#include <exception>
#include <cstdlib>

class RNP
{
private:
    RNP();
    RNP(RNP &other);
    RNP operator=(const RNP &other);
    ~RNP();
    
    static std::string _validOps;
    
    static double _resolveOperator(std::deque<double>& stack, char op);
public:
    static double calculate(std::string& expression);
};