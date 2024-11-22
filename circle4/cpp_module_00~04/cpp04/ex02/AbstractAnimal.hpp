#ifndef ABSTRACTANIMAL_HPP
# define ABSTRACTANIMAL_HPP

#include <string>
#include <iostream>

class AbstractAnimal{
    public:
        AbstractAnimal();
        AbstractAnimal(const AbstractAnimal &copy);
        AbstractAnimal &operator=(const AbstractAnimal &copy);
        virtual ~AbstractAnimal();
        virtual void makeSound() const = 0;
        std::string getType() const;
    
    protected:
        std::string type;
};

#endif