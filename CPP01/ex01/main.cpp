/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:00:37 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:00:38 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie *z_arr = zombieHorde(N, "Ordinary Zombie");

    for (int i = 0; i < N; i++)
        z_arr[i].announce();

    delete[] z_arr;
    return 0;
}