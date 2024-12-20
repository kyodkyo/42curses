#include "Phonebook.hpp"

PhoneBook::PhoneBook() : idx(0), size(0) {}

void PhoneBook::Add(void)
{
    this->contacts[idx].setFirstName();
    this->contacts[idx].setLastName();
    this->contacts[idx].setNickName();
    this->contacts[idx].setPhoneNum();
    this->contacts[idx].setDarkestSecret();
    std::cout << "Saved successfully!" << std::endl << std::endl;
    this->idx = ++idx % 8;
    size += (size < 8);
}

void PhoneBook::Search(void)
{
    if (this->size)
    {
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        std::cout << "|" << std::setw(10) << "index"
                << "|" << std::setw(10) << "first name"
                << "|" << std::setw(10) << "last name"
                << "|" << std::setw(10) << "nick name"
                << "|" << std::endl;
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        
        for(int i=0; i<this->size; i++)
        {
            std::string first_name = this->contacts[i].getFirstName();
            std::string last_name = this->contacts[i].getLastName();
            std::string nick_name = this->contacts[i].getNickName();
            std::cout << "|" << std::setw(10) << i
                    << "|" << std::setw(10) << GetTenStr(first_name)
                    << "|" << std::setw(10) << GetTenStr(last_name)
                    << "|" << std::setw(10) << GetTenStr(nick_name)
                    << "|" << std::endl;
        }
        std::cout << std::endl << "---------------------------------------------" << std::endl;

        std::string index;
        std::cout << std::endl << "pleasr enter index: ";
        std::getline(std::cin, index);
        if (std::cin.eof())
            exit(0);
        if (index.size() != 1 || index[0] >= '0' + size || index[0] < '0')
            std::cout << std::endl << "Wrong index!" << std::endl;
        else
            PrintContact(index[0] - '0');
    }
    else
        std::cout << std::endl << "PhoneBook is empty" << std::endl;
}

void PhoneBook::PrintContact(int index)
{
    std::cout << std::endl << "--------- Information --------" << std::endl;
    std::cout << "first name: " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "last name: " << this->contacts[index].getLastName() << std::endl;
    std::cout << "nick name: " << this->contacts[index].getNickName() << std::endl;
    std::cout << "phone number: " << this->contacts[index].getPhoneNum() << std::endl;
    std::cout << "darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
    std::cout << std::endl << "------------------------------" << std::endl;
}

std::string PhoneBook::GetTenStr(std::string str)
{
    if (str.size() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}
