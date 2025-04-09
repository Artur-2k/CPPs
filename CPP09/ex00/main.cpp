/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:43:25 by artuda-s          #+#    #+#             */
/*   Updated: 2025/04/09 21:12:11 by fang             ###   ########.fr       */
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
    BitcoinExchange bex(argv[1]);
    (void)argc;
    

    return 0;
}
