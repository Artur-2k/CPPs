/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:12:52 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/26 11:23:17 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
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
    // AAnimal error; // this cannot be instanciated and will result on error
    
    Dog dog;

    AAnimal *dogAniPTR = new Dog();
    AAnimal *catAniPTR = new Cat();
    std::cout << std::endl;

    std::cout << "Animal type: " << dogAniPTR->getType() << std::endl;
    dogAniPTR->makeSound();
    std::cout << std::endl;
    std::cout << "Animal type: " << catAniPTR->getType() << std::endl;
    catAniPTR->makeSound();
    std::cout << std::endl;
    
    

    delete catAniPTR;
    delete dogAniPTR;
    return 0;
}
