#include "Brain.hpp"

Brain::Brain(){
    for(int i=0; i<100; i++){
        std::stringstream ss;
        ss << "idea" << i;
        this->ideas[i] = ss.str();
    }
    std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain){
    *this = brain;
    std::cout << "Brain Copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain){
    if (this != &brain){
        for(int i=0; i<100; i++)
            this->ideas[i] = brain.getIdea(i);
    }

    std::cout << "Brain Copy assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain Destructor called" << std::endl;
}

std::string Brain::getIdea(int idx) const {
    if (idx < 0 || 100 <= idx){
        std::cout << "Index out of range" << std::endl;
        return "";
    }

    return this->ideas[idx];
}

void Brain::setIdea(int idx, std::string idea){
    if (idx < 0 || 100 <= idx){
        std::cout << "Index out of range" << std::endl;
        return;
    }
    this->ideas[idx] = idea;
}
