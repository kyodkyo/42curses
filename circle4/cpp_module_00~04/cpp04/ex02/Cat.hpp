#ifndef CAT_HPP
# define CAT_HPP

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Cat : public AbstractAnimal {
    public:
        Cat();
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);
        ~Cat();
        void makeSound() const;
        std::string getCatIdea(int idx) const;
        void setCatIdea(int idx, std::string idea);

    private:
        Brain *brain;
};

#endif