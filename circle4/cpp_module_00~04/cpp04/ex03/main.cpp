#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(){
    IMateriaSource* iMaterialSource = new MateriaSource();
    iMaterialSource->printStore();
    std::cout << std::endl;

    iMaterialSource->learnMateria(new Ice());
    iMaterialSource->learnMateria(new Cure());
    iMaterialSource->printStore();
    std::cout << std::endl;

    ICharacter* me = new Character("me");
    AMateria* tmp;
    std::cout << std::endl;

    tmp = iMaterialSource->createMateria("ice");
    me->equip(tmp);
    me->printInventory();

    tmp = iMaterialSource->createMateria("cure");
    me->equip(tmp);
    me->printInventory();
    std::cout << std::endl;
    
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << std::endl;

    delete bob;
    delete me;
    delete iMaterialSource;

    return 0;
}