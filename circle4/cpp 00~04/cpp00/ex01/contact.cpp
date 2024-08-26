#include "contact.hpp"

std::string Contact::getFirstName() const
{
    return this->first_name;
}

std::string Contact::getLastName() const
{
    return this->last_name;
}

std::string Contact::getNickName() const
{
    return this->nickname;
}

std::string Contact::getPhoneNum() const
{
    return this->phone_num;
}

void Contact::setFirstName()
{
    while(true){
        std::cout << std::endl << "First Name: ";
        std::getline(std::cin, first_name);
        if (std::cin.eof())
            exit(0);
        if (first_name.size() != 0)
            break;
        std::cout << "please enter information!" << std::endl;
    }
}

