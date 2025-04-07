/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:32:59 by fang              #+#    #+#             */
/*   Updated: 2025/04/03 20:42:00 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <string>
#include <iostream>

#include "colors.hpp"

template <typename T>
void print(MutantStack<T> &stack)
{
    for (typename MutantStack<T>::iterator it = stack.begin(); it != stack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return ;
}

int main()
{
    std::cout << BLU"//////////////////////////////////////////////////////////////" RST << std::endl; 
    std::cout << GRN "INT MUTANT STACK" RST << std::endl;
    std::cout << YEL "print uses iterators btw" RST << std::endl;
    std::cout << BLU"//////////////////////////////////////////////////////////////" RST << std::endl; 
    {
        MutantStack<int> mstack1;
        for (int i = 1; i <= 5; i++)
            mstack1.push(i);

        std::cout << "Initial stack after initialization:\n" << std::endl;
        print(mstack1);
        std::cout << RED "\nPop twice\n" RST << std::endl;
        mstack1.pop();
        mstack1.pop();
        std::cout << "Now:" << std::endl;
        print(mstack1);        
    }
    std::cout << BLU"//////////////////////////////////////////////////////////////" RST << std::endl; 
    std::cout << GRN "FLOAT MUTANT STACK" RST << std::endl;
    std::cout << YEL "print uses iterators btw" RST << std::endl;
    std::cout << BLU "//////////////////////////////////////////////////////////////" RST << std::endl; 
    {
        MutantStack<float> mstack2;
        for (int i = 1; i <= 5; i++)
            mstack2.push(i + 0.5f);

        std::cout << "Initial stack after initialization:\n" << std::endl;
        print(mstack2);
        std::cout << RED "\nPop twice\n" RST << std::endl;
        mstack2.pop();
        mstack2.pop();
        std::cout << "Now:" << std::endl;
        print(mstack2);   
    }
    std::cout << BLU"//////////////////////////////////////////////////////////////" RST << std::endl; 
    std::cout << GRN "STRING MUTANT STACK" RST << std::endl;
    std::cout << YEL "print uses iterators btw" RST << std::endl;
    std::cout << BLU"//////////////////////////////////////////////////////////////" RST << std::endl; 

    {
        MutantStack<std::string> mstack3;
        
        mstack3.push(std::string("one"));
        mstack3.push(std::string("two"));
        mstack3.push(std::string("three"));
        mstack3.push(std::string("four"));
        mstack3.push(std::string("five"));

        std::cout << "Initial stack after initialization:\n" << std::endl;
        print(mstack3);
        std::cout << RED "\nPop twice\n" RST << std::endl;
        mstack3.pop();
        mstack3.pop();
        std::cout << "Now:" << std::endl;
        print(mstack3); 
    }

    
    



    
    return 0;
}
