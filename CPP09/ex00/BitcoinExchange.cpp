/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:44:10 by artuda-s          #+#    #+#             */
/*   Updated: 2025/04/09 21:24:30 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Private constructors to prevent unintended usage
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { (void)other;}
BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& other){ (void)other; return *this;}

const char* BitcoinExchange::datacsv = "data.csv";

// Only constructor
BitcoinExchange::BitcoinExchange(std::string filename)
{
    (void)filename;
    _loadData();
}

BitcoinExchange::~BitcoinExchange() 
{} 

/**
 * @brief Given a string, checks if it all made of digits (0-9).
 * @param str String to check
 * @return True if string is only made of digits false if there's anything else
 */
bool strIsAllNumeric(const std::string& str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (! std::isdigit(*it))
            return false;
    }    
    return true;
}

/**
* @brief Validates if a year is within a given range.
* @param year Year to validate
* @param min Minimum valid year
* @param max Maximum valid year
* @return True if valid, false otherwise
*/
bool isYearValid(int year, int min, int max)
{
    return year >= min && year <= max;
}

/**
 * @brief Given a month checks if it's in the range of 1 and 12.
 * @param month Month to check
 * @return True if valid false if invalid month
 */
bool isMonthValid(int month)
{
    return month >= 1 && month <=12; 
}

/**
 * @brief Validates if a day is valid for a given year and month.
 * Takes in consideration leap years and february.
 * Thanks Hugo :)
 * @param year Year of the day to check
 * @param month Month of the day to check
 * @param day Day to check
 * @return True if valid false if invalid day
 */
bool isDayValid(int year, int month, int day)
{
    if (day < 1 || day > 31)    return false;
    
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;   
    }
    else if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && (year % 100 == 0 || year % 400 == 0));
        return day <= (isLeapYear ? 28 : 29);
    }
    return true;
}

int convertToInt(std::stringstream& ss, const std::string& errorMessage)
{
    int value;
    ss >> value;
    if (ss.fail()) throw std::runtime_error(errorMessage);
    return value;
}

void BitcoinExchange::_loadData()
{
    // opening file
    std::ifstream dataFile(datacsv);
    if ( ! dataFile )
        throw std::runtime_error("Error opening input file"); 
    
        
    // header line must be "date,exchange_rate"
    std::string line;
    getline(dataFile, line);
    if (line != "date,exchange_rate") throw std::runtime_error("Error on data title. Cant read it");
    
    while (std::getline(dataFile, line))
    {
        // 2009-03-31,0 
        if (line.size() < 12)
            throw std::runtime_error("Error: invalid format -> " + line);

        if (line[4] != '-' || line[7] != '-' || line[10] != ',')
            throw std::runtime_error("Error: invalid format -> " + line);
            
        // 2009-03-31,0     
        std::stringstream ss(line);

        // popped 2009
        int year = convertToInt(ss, "Error: invalid date ->" + line);
        if (!isYearValid(year, 2009, 2050)) throw std::runtime_error("Error: invalid date ->" + line);

        // popped -
        ss.get(); 
        
        // popped 03
        int month = convertToInt(ss, "Error: invalid date ->" + line);
        if (!isMonthValid(month)) throw std::runtime_error("Error: invalid date ->" + line);
        
        // popped -
        ss.get(); // pop second -
        
        // popped 31
        int day = convertToInt(ss, "Error: invalid date ->" + line);
        if (!isDayValid(year, month, day)) throw std::runtime_error("Error: invalid date ->" + line);

        // popped ,
        ss.get();

        // popped 0
        double value;
        ss >> value;
        ss.precision(std::numeric_limits<double>::digits10 + 1); // Ensure full precision
        if (ss.fail()) throw std::runtime_error("Error: invalid value-> " + line);
        if (value < 0.0f) throw std::runtime_error("Error: invalid value-> " + line);

        // saving the data on the map
        std::ostringstream date;
        date << year << "-" 
             << std::setfill('0') << std::setw(2) <<  month << "-"
             <<  std::setfill('0') << std::setw(2) << day;
        
        std::cout << "-------------------------------------\n\n\n" <<value << "-------------------------------------\n\n\n" << std::endl;
        // map.isert returns a pair with the map<type>::iterator that would be
        // on the desired position and a bool that indicates if the operation was successefull or not.
        // maps cant have two equal keys
        std::pair<std::map<std::string, double>::iterator, bool> result = data.insert(std::make_pair(date.str(), value));
        if (result.second == false)
            throw std::runtime_error("Error: double date entry conflict");
    }
    dataFile.close(); // wont be needed anymore

    for (std::map<std::string, double>::iterator it = data.begin() ; it != data.end(); ++it)
    {
        std::cout << it->first << "," << it->second << std::endl;
    }
}


