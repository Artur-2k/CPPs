/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:57:33 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/03 18:56:24 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//todo nan e infs nao estao a sair direito
//todo testar e go on


int main(int ac, char *av[])
{
    ScalarConverter::convert(av[1]);
    return 0;
}