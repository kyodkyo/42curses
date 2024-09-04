#include "phonebook.hpp"

PhoneBook::PhoneBook() : idx(0), size(0) {}

void PhoneBook::Add(void)
{
    this->contacts[idx].setFirstName();
    this->contacts[idx].setLastName();
    this->contacts[idx].setNickName();
    this->contacts[idx].setPhoneNum();
    std::cout << "Saved successfully!" << std::endl << std::endl;
    this->idx = ++idx % 8;
    size += (size < 8);
}

void PhoneBook::Search(void)
{
    if (this->size)
    {
        std::cout << std::endl << "-----------------------------------" << std::endl;
        std::cout << "|" << std::setw(10) << "index"
                << "|" << std::setw(10) << "first name"
                << "|" << std::setw(10) << "last name"
                << "|" << std::setw(10) << "nick name"
                << "|" << std::endl;
        std::cout << std::endl << "-----------------------------------" << std::endl;
        
        for(int i=0; i<this->size; i++)
        {
            std::string first_name = this->contacts[i].getFirstName();
            std::string last_name = this->contacts[i].getLastName();
            std::string nick_name = this->contacts[i].getNickName();
        }
    }
}

void PhoneBook::PrintContact(int index)
{

}

std::string PhoneBook::GetTenStr(std::string str)
{
    if (str.size() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}
