/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:34:04 by fang              #+#    #+#             */
/*   Updated: 2025/05/12 11:32:46 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // srand, rand
#include <ctime> // time
#include <iostream> // cout, endl
#include <exception> // exceptions


// Returns a random class that needs to be freed!
Base* generate(void)
{
    srand(time(NULL));
    switch ((rand() % 3))
    {
        case 0:
            std::cout << "A generated" << std::endl;
            return (new A);
        case 1:
            std::cout << "B generated" << std::endl;
            return (new B);
        case 2:
            std::cout << "C generated" << std::endl;
            return (new C);
    }
    return NULL;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "It's a A class" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "It's a B class" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "It's a C class" << std::endl;
    else
        std::cerr << "wtf are you doing aah class" << std::endl;
    return ;
}

void identify(Base &p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "It's a A class" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "It's a B class" << std::endl;
        } 
        catch (std::exception &e)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "It's a C class" << std::endl; 
            }
            catch(std::exception &e)
            {
                std::cerr << "wtf are you doing aah class" << std::endl;
            }
        }
    }
}

int main()
{
    Base *p = generate();
    Base &r = *p;
    
    identify(p);
    identify(r);

    delete p;
    return 0;
}
