/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:56:26 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/03 18:55:19 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cctype>
#include <string>
#include <iostream>
#include <cerrno> //errno
#include <cstdlib> // strtol, strtod
#include <climits> // MAX MIN

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        // ScalarConverter& operator= (const ScalarConverter &other);

        static bool isPseudo(const std::string &literal);
        static void handlePseudo(const std::string &literal);
        static void handleConvert(const std::string &literal);

        static bool isChar(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isDouble(const std::string &literal);
        static bool isFloat(const std::string &literal);

    public:
        
        static void convert(const std::string &literal);
};

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {}

ScalarConverter::~ScalarConverter() {}

// ScalarConverter& ScalarConverter::operator= (const ScalarConverter &other) {}


bool ScalarConverter::isPseudo(const std::string &literal)
{
    if (literal == "+inff" || literal == "+inf" ||
        literal == "-inff" || literal == "-inf" ||
        literal == "nan" || literal == "nanf")
        return true;
    return false;
}

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

bool ScalarConverter::isChar(const std::string &literal)
{
    if (literal.length() != 1)
        return false;
    return true;
}

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

    if (isChar(literal))
    {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (isInt(literal))
    {
        errno = 0;
        long l = std::strtol(literal.c_str(), NULL, 10);
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
    else
        std::cerr << "Error: bad convertion" << std::endl;
    
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
                                
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
