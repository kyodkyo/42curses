#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(){
    const Animal *meta = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

    std::cout << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    meta->makeSound();
    std::cout << dog->getType() << " " << std::endl;
    dog->makeSound();
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound();

    std::cout << std::endl;
    std::cout << wrongMeta->getType() << " " << std::endl;
    wrongMeta->makeSound();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();

    std::cout << std::endl;
    delete meta;
    delete dog;
    delete cat;
    delete wrongMeta;
    delete wrongCat;

    return 0;
}
