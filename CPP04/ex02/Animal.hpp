/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:50:34 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/11 10:02:37 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal
{
    protected:
        std::string type;
        
    public:
        Animal();
        Animal(const Animal &other);
        virtual ~Animal();
        Animal& operator= (const Animal& other);

        std::string getType() const;
        virtual void makeSound() const;
};