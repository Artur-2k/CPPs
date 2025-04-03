/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:08:51 by artuda-s          #+#    #+#             */
/*   Updated: 2025/04/02 15:15:18 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <algorithm>

/**
 
 * 
*/
template <class T>
int easyfind(T& type, int target)
{
    typename T::const_iterator begin = type.begin(), end = type.end();
    typename T::const_iterator it = std::find(begin, end, target);
    if (it == end) throw std::runtime_error("Target not in container");
    return *it;
}