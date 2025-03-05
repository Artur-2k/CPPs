/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:47:40 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/05 13:12:20 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <class T>
void print(T a)
{
    std::cout << a << " ";
}

int main()
{
    char x[] = "Hello World";
    int  y[] = {1, 2, 3, 4, 5};
    double  z[] = {1.2, 2.3, 3.4, 4.5, 5.6};

    std::cout << "Iter through char array:" << std::endl;

    iter(x, 12, print<char>);


    std::cout << std::endl;
    std::cout << "Iter through int array:" << std::endl;

    iter(y, 5, print<int>);
    
    
    std::cout << std::endl;
    std::cout << "Iter through double array:" << std::endl;
    
    iter(z, 5, print<double>);
    
    return 0;
}
