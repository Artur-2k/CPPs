/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:06:10 by artuda-s          #+#    #+#             */
/*   Updated: 2025/04/02 15:16:09 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>


int main()
{
{
    std::vector<int> vec(5);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try
    {
        std::cout << "Finding 3: " << easyfind(vec, 3) << std::endl;
        std::cout << "Finding 42: " << easyfind(vec, 42) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what()<< std::endl;
    }
}
///////////////////////////////////////////////////
    std::cout << std::endl;
///////////////////////////////////////////////////
{
    std::list<int> lst(5);
    for (int i = 0; i < 5; i++)
        lst.push_back(i);

    try
    {
        std::cout << "Finding 3: " << easyfind(lst, 3) << std::endl;
        std::cout << "Finding 42: " << easyfind(lst, 42) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
///////////////////////////////////////////////////
    std::cout << std::endl;
///////////////////////////////////////////////////
{
    std::deque<int> deq(5);
    for (int i = 0; i < 5; i++)
        deq.push_back(i);

    try
    {
        std::cout << "Finding 3: " << easyfind(deq, 3) << std::endl;
        std::cout << "Finding 42: " << easyfind(deq, 42) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}    
    return 0;
}
