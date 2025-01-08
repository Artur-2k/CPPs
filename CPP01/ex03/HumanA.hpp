#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon &_wpn;

    public:
        HumanA(std::string name, Weapon &wpn);
        ~HumanA();
        
        void attack() const;
};