/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:02:00 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:02:01 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H 
#define PHONEBOOK_H

#include <iostream> // cin cout
#include <string> // string
#include <cstdlib> // exit


void printIntro();
bool isAllDigits(const std::string &input);
bool isAllSpaces(const std::string &input);
void replaceWStoSpaces(std::string &input);
std::string readInput(const std::string &prompt);

#endif