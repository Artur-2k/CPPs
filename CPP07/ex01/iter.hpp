/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:48:10 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/05 13:12:39 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T, class Func>
void iter(T *array, unsigned int N, Func fun)
{
    for (unsigned int i = 0; i < N; i++)
        fun(array[i]);
    return ;
}
