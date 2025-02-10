/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:16:41 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/10 14:40:09 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

    #include "Animal.hpp"

    class Dog : public Animal
    {
        public:
            Dog();
            Dog(const Dog &other);
            ~Dog();
            Dog& operator= (const Dog &other);

            void makeSound() const;
    };