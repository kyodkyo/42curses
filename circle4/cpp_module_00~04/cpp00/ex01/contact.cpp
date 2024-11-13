#include "Contact.hpp"

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

std::string Contact::getDarkestSecret() const
{
    return this->darkest_secret;
}

void Contact::setFirstName()
{
    while(true)
    {
        std::cout << std::endl << "First Name: ";
        std::getline(std::cin, first_name);
        if (std::cin.eof())
            exit(0);
        if (first_name.size() != 0)
            break;
        std::cout << "please enter information!" << std::endl;
    }
}

void Contact::setLastName()
{
    while(true)
    {
        std::cout << "Last Name: ";
        std::getline(std::cin, last_name);
        if (std::cin.eof())
            exit(0);
        if (last_name.size() != 0)
            break;
        std::cout << "please enter information!" << std::endl;
    }
}

void Contact::setNickName()
{
    while(true)
    {
        std::cout << "Nick Name: ";
        std::getline(std::cin, nickname);
        if (std::cin.eof())
            exit(0);
        if (nickname.size() != 0)
            break;
        std::cout << "please enter information!" << std::endl;
    }
}

void Contact::setPhoneNum()
{
    while(true)
    {
        std::cout << "Phone Number: ";
        std::getline(std::cin, phone_num);
        if (std::cin.eof())
            exit(0);
        if (phone_num.size() != 0)
            break;
        std::cout << "please enter information!" << std::endl;
    }
}

void Contact::setDarkestSecret()
{
    while(true)
    {
        std::cout << "Darkest Secret: ";
        std::getline(std::cin, darkest_secret);
        if (std::cin.eof())
            exit(0);
        if (darkest_secret.size() != 0)
            break;
        std::cout << "please enter information!" << std::endl;
    }
}