#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>
#include <sstream>

class Brain {
    public:
        Brain();
        Brain(const Brain &brain);
        Brain &operator=(const Brain &brain);
        ~Brain();
        std::string getIdea(int idx) const;
        void setIdea(int idx, std::string idea);

    private:
        std::string ideas[100];
};

#endif