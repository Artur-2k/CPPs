/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:37:36 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/05 10:54:50 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T>
void swap(T *a, T *b)
{
    T temp = *a; *a = *b; *b = temp;
}

template <class T>
T min(T a, T b)
{
    return (a > b ? b : a);
}

template <class T>
T max(T a, T b)
{
    return (a > b ? a : b);
}
