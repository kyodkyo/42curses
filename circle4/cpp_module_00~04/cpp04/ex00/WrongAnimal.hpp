#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &wrongAnimal);
        WrongAnimal &operator=(const WrongAnimal &wrongAnimal);
        virtual ~WrongAnimal();
        void makeSound() const;
        std::string getType() const;

    protected:
        std::string type;
};

#endif