/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:50:34 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/11 11:35:41 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class AAnimal
{
    protected:
        std::string type;
        
    public:
        AAnimal();
        AAnimal(const AAnimal &other);
        virtual ~AAnimal();
        AAnimal& operator= (const AAnimal& other);

        std::string getType() const;
        virtual void makeSound() const = 0;
};