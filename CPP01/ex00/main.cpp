/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:00:15 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:00:16 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *z1;

    z1= newZombie("Sonic");
    z1->announce();
    randomChump("Bachus");

    delete z1;
    return 0;
}