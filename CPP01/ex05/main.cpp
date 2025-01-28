/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:01:33 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:01:34 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl satan;

	std::cout << "[DEBUG]" << std::endl;
	satan.complain("DEBUG");

	std::cout << "\n[INFO]" << std::endl;
	satan.complain("INFO");

	std::cout << "\n[WARNING]" << std::endl;
	satan.complain("WARNING");

	std::cout << "\n[ERROR]" << std::endl;
	satan.complain("ERROR");

	std::cout << "\n[UNKNOWN]" << std::endl;
	satan.complain("unknown");

	return 0;
}