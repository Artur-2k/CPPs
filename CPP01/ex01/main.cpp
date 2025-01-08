#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie *z_arr = zombieHorde(N, "Ordinary Zombie");

    for (int i = 0; i < N; i++)
        z_arr[i].announce();

    delete[] z_arr;
    return 0;
}