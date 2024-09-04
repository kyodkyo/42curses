#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook{
    private:
        Contact contacts[8];
        int idx;
        int size;

    public:
        PhoneBook();
        void Add();
        void Search();
        void PrintContact(int index);
        std::string GetTenStr(std::string str);
};

#endif