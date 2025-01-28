/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:00:31 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:00:32 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie(std::string n);
        ~Zombie();

        void    announce( void );
};

Zombie* newZombie( std::string _name );
void randomChump( std::string _name );
