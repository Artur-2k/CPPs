/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:55:00 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/05 11:45:37 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <algorithm>

int main()
{
    int a = -1, b = 1;
    double j = -1.1, k = 1.1;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "j: " << j << std::endl;
    std::cout << "k: " << k << std::endl;

    std::cout << "\nswap a and b:" << std::endl;    
    ::swap<int>(&a, &b);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "\nswap j and l:" << std::endl;    
    ::swap<double>(&j, &k);
    std::cout << "j: " << j << std::endl;
    std::cout << "k: " << k << std::endl;


    std::cout << "\n///////////////////////////////////////////////////\n" << std::endl;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "j: " << j << std::endl;
    std::cout << "k: " << k << std::endl;

    std::cout << "\nmin a and b:" << std::endl;    
    std::cout << "Min is: " << ::min<int>(a, b) << std::endl;

    std::cout << "\nmin j and k:" << std::endl;    
    std::cout << "Min is: " << ::min<double>(j, k) << std::endl;

    std::cout << "\n///////////////////////////////////////////////////\n" << std::endl;


    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "j: " << j << std::endl;
    std::cout << "k: " << k << std::endl;

    std::cout << "\nmax a and b:" << std::endl;    
    std::cout << "Max is: " << ::max<int>(a, b) << std::endl;

    std::cout << "\nmax j and k:" << std::endl;    
    std::cout << "Max is: " << ::max<double>(j, k) << std::endl;
    
    return 0;
}
