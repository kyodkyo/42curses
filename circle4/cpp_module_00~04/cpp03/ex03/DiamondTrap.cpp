#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
    this->name = "Default";
    ClapTrap::name = "Default_clap_name";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = 50; //ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;

    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name){
    this->name = _name;
    ClapTrap::name = _name + "_clap_name";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = 50; //ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;

    std::cout << "DiamondTrap Name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(), ScavTrap(), FragTrap() {
    *this = diamondTrap;
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap){
    if (this != &diamondTrap){
        this->name = diamondTrap.getName();
        this->hitPoints = diamondTrap.getHitPoints();
        this->energyPoints = diamondTrap.getEnergyPoints();
        this->attackDamage = diamondTrap.getAttackDamage();
    }

    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap name is " << this->name << std::endl;
    std::cout << "ClapTrap name is " << ClapTrap::name << std::endl;
}
