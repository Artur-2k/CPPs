/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:01:14 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:01:15 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon
{
    private:
        std::string _type;

    public:
        Weapon(std::string type);

        const std::string& getType() const;
        void setType(const std::string newType);

        Weapon& operator=(const Weapon &other);
};