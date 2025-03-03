/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:56:24 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/03 23:05:51 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// these don't do anything
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator= (const ScalarConverter &other) {(void)other; return *this;}

// Hard code check for what they ask lol
bool ScalarConverter::isPseudo(const std::string &literal)
{
    if (literal == "+inff" || literal == "+inf" ||
        literal == "-inff" || literal == "-inf" ||
        literal == "nan" || literal == "nanf")
        return true;
    return false;
}

// Prints the appropriate messages
void ScalarConverter::handlePseudo(const std::string &literal)
{
    std::cout << "Char: Impossible" << std::endl;
    std::cout << "Int: Impossible" << std::endl;
    
    if (literal == "+inff" || literal == "+inf")
    {
        std::cout << "Float: +inff" << std::endl;
        std::cout << "Double: +inf" << std::endl;
    }
    else if (literal == "-inff" || literal == "-inf")   
    {
        std::cout << "Float: -inff" << std::endl;
        std::cout << "Double: -inf" << std::endl;
    }
    else if (literal == "nan" || literal == "nanf")
    {
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
    }
    return ;    
}

// Returns true if there is a string 'c' where c is a char
bool ScalarConverter::isChar(const std::string &literal)
{
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return true;
    return false;
}

// Returns true if looks like an int. doesnt check for overflows
bool ScalarConverter::isInt(const std::string &literal)
{
    size_t i = 0;
    if ((literal[i] == '-' || literal[i] == '+') && literal.length() != 1)
        i++;
    
    while (i < literal.length())
    {
        if (!isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

// returns true if looks like a float. doesnt check for overflows
bool ScalarConverter::isFloat(const std::string &literal)
{
    // ends in f, must have one and only one '.' and only digits
    // 12.34f 
    if (*(literal.end() - 1) != 'f')
        return false;
        
    size_t i = 0;
    // +12.34f
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (!isdigit(literal[i])) //+.f invalid
        return false;
    
    bool fp = false;
    while (i < literal.length() - 1)
    {
        if (literal[i] == '.')
        {
            if (fp) // two '.'
                return false;
            fp = true;
        }
        else if (!isdigit(literal[i]))
            return false;
        i++;
    }
    return fp; // must have one '.'
}

// returns true if looks like a double. doesnt check for overflows
bool ScalarConverter::isDouble(const std::string &literal)
{
    // must have one and only one '.' and only digits
    size_t i = 0;
    // +12.34f
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (!isdigit(literal[i])) //+. invalid
        return false;
    
    bool fp = false;
    while (i < literal.length())
    {
        if (literal[i] == '.')
        {
            if (fp) // two '.'
                return false;
            fp = true;
        }
        else if (!isdigit(literal[i]))
            return false;
        i++;
    }
    return fp; // must have one '.'
}

void ScalarConverter::handleConvert(const std::string &literal)
{
    char c;
    int  i;
    float f;
    double d;

    // Promotions from char to double
    if (isChar(literal))
    {
        c = literal[1];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (isInt(literal))
    {
        errno = 0;
        long l = std::strtol(literal.c_str(), NULL, 10);
        // errno for over / under flows and check if INT MIN and MAX were reached.
        if (errno || l > INT_MAX || l < INT_MIN)
        {
            std::cout << "Char: Impossible" << std::endl;
            std::cout << "Int: Impossible" << std::endl;
            std::cout << "Float: Impossible" << std::endl;
            std::cout << "Double: Impossible" << std::endl;
            return;
        }
        
        i = static_cast<int>(l);
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (isDouble(literal))
    {
        errno = 0;
        d = std::strtod(literal.c_str(), NULL);
        // using errno to check for possible errors on conversion
        if (errno)
        {
            std::cout << "Char: Impossible" << std::endl;
            std::cout << "Int: Impossible" << std::endl;
            std::cout << "Float: Impossible" << std::endl;
            std::cout << "Double: Impossible" << std::endl;
            return;
        }
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    }
    else if (isFloat(literal))
    {
        errno = 0;
        f = std::strtof(literal.c_str(), NULL);
        // using errno to check for possible errors on conversion
        if (errno)
        {
            std::cout << "Char: Impossible" << std::endl;
            std::cout << "Int: Impossible" << std::endl;
            std::cout << "Float: Impossible" << std::endl;
            std::cout << "Double: Impossible" << std::endl;
            return;
        }
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    }
    else // anything else but a number and what they were asking
    {
        std::cerr << "Error: bad convertion" << std::endl;
        return ;
    }
    

    // OUTPUT AND FORMATTING
    // Printable chars
    std::cout << "char: ";
    if (isprint(static_cast<int>(c)))
        std::cout << c << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    // All other checks have been made by this point
    std::cout << "int: " << i << std::endl;

    // Just have to check if the number has been truncated when it's 0
    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << d;
    if (d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty())
    {
        std::cout << "Error: empty" << std::endl;
        return ;
    }
    if (isPseudo(literal))
        handlePseudo(literal);
    else
        handleConvert(literal);
    
    return ;
}