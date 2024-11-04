#include "Zombie.hpp"

int main(void)
{
    Zombie zombie("zombie1 in Stack");
    Zombie *zombie2 = newZombie("zombie2 in Heap");

    randomChump("zombie3 in Stack");

    zombie.announce();
    zombie2->announce();

    delete zombie2;
    return (0);
}
