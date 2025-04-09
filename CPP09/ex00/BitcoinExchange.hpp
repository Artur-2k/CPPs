/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:43:39 by artuda-s          #+#    #+#             */
/*   Updated: 2025/04/09 21:22:17 by fang             ###   ########.fr       */
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
#include <limits>
class BitcoinExchange
{
private:
    std::map<std::string, double> data;
    static const char *datacsv;
    std::string input;
    
    void _loadData();
    
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator= (const BitcoinExchange& other);
public:
    BitcoinExchange(std::string filename);
    ~BitcoinExchange();
    

    
};
