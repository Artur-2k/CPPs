/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:00:41 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:00:42 by artuda-s         ###   ########.fr       */
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
        Zombie( void );
        Zombie(std::string& n);
        ~Zombie();

    void    announce( void );
    void    set_name(std::string& n);
};

Zombie* zombieHorde( int N, std::string _name );