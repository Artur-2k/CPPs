#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon *_wpn;

    public:
        HumanB(std::string name);
        ~HumanB();
        
        void setWeapon(Weapon &wpn);
        void attack() const;
};
