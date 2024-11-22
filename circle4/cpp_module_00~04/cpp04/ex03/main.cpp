#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(){
    // 젤 마지막에 unequip만 실행하면 leak
    // equip delete 대신 floor 구현이 필요? 어케해;;
    IMateriaSource* iMaterialSource = new MateriaSource();
    std::cout << "store state" << std::endl;
    std::cout << "store[0] : " << iMaterialSource->getStore(0) << std::endl;
    std::cout << "store[1] : " << iMaterialSource->getStore(1) << std::endl;
    std::cout << "store[2] : " << iMaterialSource->getStore(2) << std::endl;
    std::cout << "store[3] : " << iMaterialSource->getStore(3) << std::endl;
    std::cout << std::endl;

    iMaterialSource->learnMateria(new Ice());
    iMaterialSource->learnMateria(new Cure());
    std::cout << "store[0] : " << iMaterialSource->getStore(0)->getType() << std::endl;
    std::cout << "store[1] : " << iMaterialSource->getStore(1)->getType() << std::endl;
    std::cout << "store[2] : " << iMaterialSource->getStore(2) << std::endl;
    std::cout << std::endl;

    ICharacter* me = new Character("me");
    AMateria* tmp;
    std::cout << "inventory[0] : " << me->getInventory(0) << std::endl;
    std::cout << "inventory[1] : " << me->getInventory(1) << std::endl;
    std::cout << "inventory[2] : " << me->getInventory(2) << std::endl;
    std::cout << "inventory[3] : " << me->getInventory(3) << std::endl;

    std::cout << std::endl;

    tmp = iMaterialSource->createMateria("ice");
    me->equip(tmp);
    std::cout << "inventory[0] : " << me->getInventory(0)->getType() << std::endl;
    std::cout << "inventory[1] : " << me->getInventory(1) << std::endl;
    std::cout << std::endl;

    tmp = iMaterialSource->createMateria("cure");
    me->equip(tmp);
    std::cout << "inventory[0] : " << me->getInventory(0)->getType() << std::endl;
    std::cout << "inventory[1] : " << me->getInventory(1)->getType() << std::endl;
    std::cout << "inventory[2] : " << me->getInventory(2) << std::endl;
    std::cout << std::endl;
    
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    std::cout << std::endl;

    delete bob;
    delete me;
    delete iMaterialSource;

    return 0;
}