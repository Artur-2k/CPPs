/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:11:38 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/10 15:12:01 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
        
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        ~WrongAnimal();

        WrongAnimal& operator= (const WrongAnimal& other);

        std::string getType() const;
        void makeSound() const;
};