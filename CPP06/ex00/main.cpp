/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:57:33 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/03 23:08:41 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//todo nan e infs nao estao a sair direito
//todo testar e go on


int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "One arg pls" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}