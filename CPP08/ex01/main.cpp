/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:29:49 by artuda-s          #+#    #+#             */
/*   Updated: 2025/04/07 12:22:10 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main()
{
    Span span(10);
    try
    {
        span.addNumber(4);    
        span.addNumber(18);    
        span.addNumber(17);    
        span.addNumber(-11);    
        span.addNumber(-12);
        
        std::cout << "min span: " << span.shortestSpan() << std::endl;
        std::cout << "max span: " << span.longestSpan() << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::vector<int> vec(3, 6);
        span.addNumber(vec.begin(), vec.end());
    
        span.print();
        std::cout << "min span: " << span.shortestSpan() << std::endl;
        std::cout << "max span: " << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}