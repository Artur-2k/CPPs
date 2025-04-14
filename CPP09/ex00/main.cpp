/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:43:25 by artuda-s          #+#    #+#             */
/*   Updated: 2025/04/10 22:30:53 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// btc input.txt
// yyyy-mm-dd | value
// 2009-01-02,0
// 2045 -> will use the lower bound date
// value must be between 0 and 1000 inclusive

#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
    try
    {
        if (argc != 2) throw std::runtime_error("Error: invalid program arguments");
        BitcoinExchange bex;
        
        bex.exchange(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
