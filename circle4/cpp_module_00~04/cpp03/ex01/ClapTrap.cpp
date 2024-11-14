#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    this->name = "Default";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name) {
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
    *this = clapTrap;    
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap){
    if (this != &clapTrap) {
        this->name = clapTrap.getName();
        this->hitPoints = clapTrap.getHitPoints();
        this->energyPoints = clapTrap.getEnergyPoints();
        this->attackDamage = clapTrap.getAttackDamage();
    }
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called" << std::endl;
}

std::string ClapTrap::getName() const {
    return this->name;
}

unsigned int ClapTrap::getHitPoints() const {
    return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return this->energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
    return this->attackDamage;
}

void ClapTrap::attack(const std::string &target) {
    if (!this->hitPoints){
        std::cout << "ClapTrap " << this->name << " has no hit point." << std::endl;
    }
    else if (!this->energyPoints){
        std::cout << "ClapTrap " << this->name << " has no energy point." << std::endl;
    }
    else {
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (!this->hitPoints){
        std::cout << "ClapTrap " << this->name << " has no hit point." << std::endl;
    }
    else {
        if (this->hitPoints < amount)
            this->hitPoints = 0;
        else
            this->hitPoints -= amount;

        std::cout << "ClapTrap " << this->name << " has taken " << amount << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!this->hitPoints){
        std::cout << "ClapTrap " << this->name << " has no hit point." << std::endl;
    }
    else if (!this->energyPoints){
        std::cout << "ClapTrap " << this->name << " has no energy point." << std::endl;
    }
    else{
        this->hitPoints += amount;
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " has been repaired by " << amount << " points!" << std::endl;
    }
}
