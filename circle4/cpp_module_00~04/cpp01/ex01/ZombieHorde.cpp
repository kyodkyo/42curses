#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name){
    if (N <= 0){
        std::cout << "Invalid number" << std::endl;
        return (NULL);
    }

    Zombie  *zombies = new Zombie[N];
    std::stringstream   ss;

    for(int i=0; i<N; i++){
        ss.str(std::string());
        ss << " " << i+1;
        zombies[i].setName(name + ss.str());
        std::cout << "Zombie " << i+1 << " created" << std::endl; 
    }
    return zombies;
}
