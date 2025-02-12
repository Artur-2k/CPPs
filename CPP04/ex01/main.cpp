/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:12:52 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/12 12:01:19 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main()
{
    // Dog
    {
    std::cout << GREEN << "Creation of wte with default constructor" << RESET <<  std::endl;

    Dog wte;
    wte.getType();
    std::string idea = "Boots, boots, boots, boots";
    wte.getBrain()->append(idea, 0);
    std::cout << RED;
    wte.getBrain()->printIdea(0);
    std::cout << RESET << std::endl;
    

    std::cout<< GREEN  << "Creation of etw with param constructor" << RESET << std::endl;

    Dog etw(wte);
    idea = "Movin' up an' down again";
    etw.getBrain()->append(idea, 1);
    etw.getBrain()->printIdea(0);
    etw.getBrain()->printIdea(1);
    std::cout << RESET << std::endl;

    std::cout <<GREEN  << "Creation of foo and = etw" << RESET << std::endl;
    Dog foo;
    foo = etw;
    std::cout << RED;
    foo.getBrain()->printIdea(0);
    foo.getBrain()->printIdea(1);
    std::cout << RESET << std::endl;
    }

    // Cat
    {
    std::cout << GREEN << "\n\nCreation of wte with default constructor" << RESET <<  std::endl;
    
    Cat wte;
    std::cout << wte.getType() << std::endl;
    std::string idea = "Boots, boots, boots, boots, movin' up an' down again";
    wte.getBrain()->append(idea, 0);
    std::cout << RED;
    wte.getBrain()->printIdea(0);
    std::cout << RESET << std::endl;
    

    std::cout<< GREEN  << "Creation of etw with param constructor" << RESET << std::endl;

    Cat etw(wte);
    idea = "Men, men, men, men, men go mad with watchin' em,";
    etw.getBrain()->append(idea, 1);
    std::cout << RED;
    etw.getBrain()->printIdea(0);
    etw.getBrain()->printIdea(1);
    std::cout << RESET << std::endl;

    std::cout <<GREEN  << "Creation of foo and = etw" << RESET << std::endl;
    Cat foo;
    foo = etw;
    std::cout << RED;
    foo.getBrain()->printIdea(0);
    foo.getBrain()->printIdea(1);
    std::cout << RESET << std::endl;
    }

    // Virtual destructors
    {
        std::cout << GREEN << "\n\nAnimal Arrays" << RESET <<  std::endl;

        Animal *array[10];
        std::string dogIdea = "Oh, my, God, keep me from goin' lunatic!";
        std::string catIdea = "There's no discharge in the war!";
        
        for (int i = 0; i < 10; i++)
        {
            if (i < 5) // dogs
                array[i] = new Dog();   
            else // cats
                array[i] = new Cat();
        }

        std::cout << GREEN << "\n\nSounds" << RESET <<  std::endl;
        for (int i = 0; i < 10; i++)
            array[i]->makeSound();


        std::cout << GREEN << "\n\nFree" << RESET <<  std::endl;
        for (int i = 0; i < 10; i++)
            delete array[i];   
    }
    return 0;
}
