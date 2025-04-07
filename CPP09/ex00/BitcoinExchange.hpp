/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:43:39 by artuda-s          #+#    #+#             */
/*   Updated: 2025/04/07 17:59:24 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>

class BitcoinExchange
{
private:
    std::map<std::string, float> _map;
    std::ifstream _file;
    std::string _validateDate(std::stringstream& ss);
    std::string _validateValue(std::stringstream& ss);
    float _findExchangeRate(std::string& date, std::string& value);
public:
    BitcoinExchange(/* args */);
    BitcoinExchange(std::string& file); // open file?
    ~BitcoinExchange(); // close everything 

    void printExchangeValue();
    
};


std::string BitcoinExchange::_validateDate(std::stringstream& ss)
{
    int year, month, day;
    char dash1, dash2;

    ss >> year >> dash1 >> month >> dash2 >> day;
    
    /**
     * This will try to read int,char,int,char,int and will always stop when the non digit starts
     * and if it failed the conversion .fail() will be true and therefore we have an invalid date format
    */
    if (ss.fail() || dash1 != '-' || dash2 != '-')
        throw std::runtime_error("Error: Invalid date format");
    
    // rebuilding again to return
    std::ostringstream os;
    os << year << dash1 << month << dash2 << day;
    return os.str();
}

std::string BitcoinExchange::_validateValue(std::stringstream& ss)
{
    float rate;
    
    ss >> rate;

    if (ss.fail())
        throw std::runtime_error("Error: Bad value");
    if ( !ss.eof())
        throw std::runtime_error("Error: Bad format");

    if (rate < 0 || rate > 1000)
        throw std::runtime_error("Error: Bad value");

    std::ostringstream os;
    os << rate;
    return os.str();
}


void BitcoinExchange::printExchangeValue()
{
    std::string line;
    
    while (getline(_file, line))
    {
        try
        {
            std::stringstream ss(line);
            
            // Parse date. Throws excpt on error
            std::string date = _validateDate(ss);
            
            if (ss.str().substr(0, 3) != " ! ")
                throw std::runtime_error("Error: Bad format");

            std::string value = _validateValue(ss);

            float exchangeRate = _findExchangeRate(date, value);
            
            std::cout << date << " | " << value << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
