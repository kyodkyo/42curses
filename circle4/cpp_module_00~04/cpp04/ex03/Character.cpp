#include "Character.hpp"

Character::Character(){
    this->name = "Default";
    for(int i=0; i<4; i++)
        this->inventory[i] = NULL;

    std::cout << "Character Default constructor called" << std::endl;
}

Character::Character(std::string name){
    this->name = name;
    for(int i=0; i<4; i++)
        this->inventory[i] = NULL;

    std::cout << "Character Name constructor called" << std::endl;
}

Character::Character(const Character &copy) : ICharacter() {
    *this = copy;
    std::cout << "Character Copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &copy){
    if (this != &copy){
        this->name = copy.name;

        for(int i=0; i<4; i++){
            delete this->inventory[i];

            if (copy.inventory[i])
                this->inventory[i] = copy.inventory[i];
            else
                this->inventory[i] = NULL;
        }
    }

    std::cout << "Character Copy assignment operator called" << std::endl;
    return *this;
}

Character::~Character(){
    for(int i=0; i<4; i++)
        delete inventory[i];

    std::cout << "Character Destructor called" << std::endl;
}

void Character::printInventory() const {
    for(int i=0; i<4; i++){
        std::cout << "inventory[" << i << "] : " << this->inventory[i] << std::endl; 
    }
}

std::string const &Character::getName() const {
    return this->name;
}

void Character::equip(AMateria *materia){
    for(int i=0; i<4; i++){
        if (!this->inventory[i]){
            this->inventory[i] = materia->clone();
            break;
        }
    }
}

void Character::unequip(int idx){
    if (0 <= idx && idx < 4)
        this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target){
    if (0 <= idx && idx < 4 && this->inventory[idx])
        this->inventory[idx]->use(target);
}
