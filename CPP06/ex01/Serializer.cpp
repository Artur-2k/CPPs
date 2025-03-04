/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:00:34 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/04 17:24:57 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer &other) {(void)other;}
Serializer& Serializer::operator=(const Serializer &other) {(void)other; return *this;}

uintptr_t Serializer::serialize(Data* ptr)
{
    return ptr ? reinterpret_cast<uintptr_t>(ptr) : 0;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return raw ? reinterpret_cast<Data *>(raw) : nullptr;
}
