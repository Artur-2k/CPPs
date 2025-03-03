/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:56:26 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/03 23:01:13 by fang             ###   ########.fr       */
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
        ScalarConverter& operator= (const ScalarConverter &other);

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


