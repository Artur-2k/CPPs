/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:43:39 by artuda-s          #+#    #+#             */
/*   Updated: 2025/04/10 22:31:21 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cstdlib> //strtof
#include <cctype>   //isdigit
#include <iomanip> // setfill setw
#include <limits> // numeric limits
#include <cerrno> // errno
#include <algorithm> // for lowerbound
class BitcoinExchange
{
private:
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator= (const BitcoinExchange& other);
    
    
    std::map<std::string, double> data;
    static const char *datacsv;
    
    
    void _loadData();
    public:
    BitcoinExchange();
    ~BitcoinExchange();
    
    void exchange(std::string inputFilePath) const;
    double getValueOnDate(std::string& date) const;
};
