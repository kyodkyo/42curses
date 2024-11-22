#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(){
    {
        std::cout << "###### Dog Test ###### " << std::endl;

        Dog *dog = new Dog();
        std::cout << std::endl;

        std::cout << "Dog's First idea: " << dog->getDogIdea(0) << std::endl;
        std::cout << "Dog's Second idea: " << dog->getDogIdea(1) << std::endl;
        std::cout << "Dog's Last idea: " << dog->getDogIdea(99) << std::endl;
        std::cout << "Dog's 100th idea: " << dog->getDogIdea(100) << std::endl;

        Dog *copyDog = new Dog();
        *copyDog = *dog;
        std::cout << std::endl;
        
        dog->setDogIdea(99, "This is new idea");
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
        *copyCat = *cat;
        std::cout << std::endl;

        cat->setCatIdea(99, "This is new idea");
        std::cout << "Cat's Last idea: " << cat->getCatIdea(99) << std::endl;
        std::cout << "Copy cat's Last idea: " << copyCat->getCatIdea(99) << std::endl;
        
        std::cout << std::endl;
        delete cat;
        delete copyCat;
    }

    return 0;
}
