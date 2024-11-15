#include "FragTrap.hpp"

FragTrap::FragTrap(){
    this->name = "Default";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name){
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap){
    *this = fragTrap;
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap){
    if (this != &fragTrap){
        this->name = fragTrap.getName();
        this->hitPoints = fragTrap.getHitPoints();
        this->energyPoints = fragTrap.getEnergyPoints();
        this->attackDamage = fragTrap.getAttackDamage();
    }
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap(){

    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(){
    if (!this->hitPoints)
        std::cout << "FragTap " << this->name << " has no power to high five" << std::endl;
    else
        std::cout << "FragTrap " << this->name << " is asking for a high five!" << std::endl;
}