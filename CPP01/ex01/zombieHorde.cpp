/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:00:47 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:00:48 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string _name )
{
    Zombie *z = new Zombie[N];

    for (int i = 0; i < N; i++)
        z[i].set_name(_name);
    return z;
}