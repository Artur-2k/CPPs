/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:12:52 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/10 15:37:54 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
    std::cout << GREEN << " Constructors:" << RESET << std::endl;

    Animal *aniptr = new Animal();
    std::cout << std::endl;
    Animal *aniDog = new Dog();
    std::cout << std::endl;
    Animal *aniCat = new Cat();
    std::cout << std::endl;
    WrongCat* wrongCat = new WrongCat();
    std::cout << std::endl;

    Animal *teste2 = aniCat;
    WrongAnimal * teste = wrongCat;
    

    std::cout << YELLOW << "Normal Tests:" << RESET << std::endl;
    
    std::cout << "Animal type: " << aniptr->getType() << std::endl;
    aniptr->makeSound();
    std::cout << std::endl;
    std::cout << "Animal type: " << aniDog->getType() << std::endl;
    aniDog->makeSound();
    std::cout << std::endl;
    std::cout << "Animal type: " << aniCat->getType() << std::endl;
    aniCat->makeSound();
    std::cout << std::endl;

    std::cout << BLUE << "POF Tests:" << RESET << std::endl;
    std::cout << MAGENTA << "First will point to cat's Animal instance which is virtual" << RESET << std::endl;
    
    std::cout << "Pointer to animal sound" << std::endl;
    teste2->makeSound();
    std::cout << std::endl;


    std::cout << MAGENTA <<"Then this will point to WrongCats WrongAnimal instance which is not virtual" << RESET << std::endl;
    std::cout << "Animal type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    std::cout << std::endl;

    std::cout << "Pointer to wronganimal sound:\n";
    teste->makeSound();
    std::cout << std::endl;

    delete aniCat;
    delete aniDog;
    delete aniptr;
    delete wrongCat;
    return 0;
}