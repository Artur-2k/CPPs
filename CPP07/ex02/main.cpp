/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:40:45 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/06 10:32:09 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<char> teste;
    
    Array<char> teste2(10);
    teste2[0] = 'O';
    teste2[1] = 'l';
    teste2[2] = 'a';
    teste2[3] = '\0';

    Array<char> teste3(teste2);
    
    std::cout << "size of teste2 should be 10 (3 populated 7 0'ed): " << teste2.size() << std::endl;
    
    std::cout << "Teste2: " << teste2[0] << teste2[1] << teste2[2] << std::endl;
    std::cout << "Teste3: " << teste3[0] << teste3[1] << teste3[2] << std::endl;

    std::cout << "Changing teste2 from ola to oxa" << std::endl;
    teste2[1] = 'x';

    std::cout << "Teste2: " << teste2[0] << teste2[1] << teste2[2] << std::endl;
    std::cout << "Teste3: " << teste3[0] << teste3[1] << teste3[2] << std::endl;
    return 0;
}
