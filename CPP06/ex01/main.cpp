/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:09:55 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/04 17:16:40 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include "stdint.h"

int main()
{
    Data *d = new Data();
    d->boolean = true;
    d->num = 42;
    d->text.resize(12);
    d->text = "Hello world!";

    uintptr_t serializedData = Serializer::serialize(d);
    Data *d2 = Serializer::deserialize(serializedData);

    std::cout << "Original Data:" << std::endl;
    std::cout << "text: " << d->text << std::endl;
    std::cout << "boolean: " << (d->boolean ? "true" : "false") << std::endl;
    std::cout << "num: " << d->num << std::endl;

    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "text: " << d2->text << std::endl;
    std::cout << "boolean: " << (d2->boolean ? "true" : "false") << std::endl;
    std::cout << "num: " << d2->num << std::endl;
    
    delete d;
    return 0;
}