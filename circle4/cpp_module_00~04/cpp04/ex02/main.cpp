#include "Animal.hpp"
#include "AbstractAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(){
    {
        // const Animal *meta = new Animal();
        // const AbstractAnimal *aa = new AbstractAnimal();
        // const WrongAnimal *wrongCat = new WrongCat();
        const AbstractAnimal *dog = new Dog();
        const AbstractAnimal *cat = new Cat();

        std::cout << std::endl;
        std::cout << dog->getType() << " " << std::endl;
        dog->makeSound();
        std::cout << cat->getType() << " " << std::endl;
        cat->makeSound();

        std::cout << std::endl;
        delete dog;
        delete cat;
    }
    {
        std::cout << std::endl;
        std::cout << "###### Dog Test ###### " << std::endl;

        Dog *dog = new Dog();
        std::cout << std::endl;

        std::cout << "Dog's First idea: " << dog->getDogIdea(0) << std::endl;
        std::cout << "Dog's Second idea: " << dog->getDogIdea(1) << std::endl;
        std::cout << "Dog's Last idea: " << dog->getDogIdea(99) << std::endl;
        std::cout << "Dog's 100th idea: " << dog->getDogIdea(100) << std::endl;

        Dog *copyDog = new Dog();
        std::cout << std::endl;
        
        dog->setDogIdea(99, "This is new idea");
        std::cout << "Dog's Last idea: " << dog->getDogIdea(99) << std::endl;
        std::cout << "Copy dog's Last idea: " << copyDog->getDogIdea(99) << std::endl;
        std::cout << std::endl;

        *copyDog = *dog;
        std::cout << std::endl;
        
        std::cout << "Dog's Last idea: " << dog->getDogIdea(99) << std::endl;
        std::cout << "Copy dog's Last idea: " << copyDog->getDogIdea(99) << std::endl;
        
        std::cout << std::endl;
        delete dog;
        delete copyDog;
    }
    std::cout << "-----------------------------------------";
    {
        std::cout << std::endl;
        std::cout << "###### Cat Test ###### " << std::endl;

        Cat *cat = new Cat();
        std::cout << std::endl;

        std::cout << "Cat's First idea: " << cat->getCatIdea(0) << std::endl;
        std::cout << "Cat's Second idea: " << cat->getCatIdea(1) << std::endl;
        std::cout << "Cat's Last idea: " << cat->getCatIdea(99) << std::endl;
        std::cout << "Cat's 100th idea: " << cat->getCatIdea(100) << std::endl;

        Cat *copyCat = new Cat();
        std::cout << std::endl;

        cat->setCatIdea(99, "This is new idea");
        std::cout << "Cat's Last idea: " << cat->getCatIdea(99) << std::endl;
        std::cout << "Copy cat's Last idea: " << copyCat->getCatIdea(99) << std::endl;
        std::cout << std::endl;

        *copyCat = *cat;
        std::cout << std::endl;
        
        std::cout << "Cat's Last idea: " << cat->getCatIdea(99) << std::endl;
        std::cout << "Copy cat's Last idea: " << copyCat->getCatIdea(99) << std::endl;
        
        std::cout << std::endl;
        delete cat;
        delete copyCat;
    }

    return 0;
}
