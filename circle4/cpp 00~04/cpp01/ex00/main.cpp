#include "Zombie.hpp"

int main(void)
{
    Zombie stackZombie = Zombie("stackZombie");
    stackZombie.announce();

    Zombie *heapZombie = newZombie("heapZombie");
    heapZombie->announce();

    randomChump("randomChumpStackZombie");

    delete heapZombie;
    return (0);
}
