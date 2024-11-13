#include "Phonebook.hpp"

int main()
{
    PhoneBook ph;
    std::string cmd;

    while(true)
    {
        std::cout <<  "please enter command: [ADD, SEARCH, EXIT]" << std::endl;
        std::getline(std::cin, cmd);
        if (std::cin.eof())
            break;
        if (cmd == "ADD")
            ph.Add();
        else if (cmd == "SEARCH")
            ph.Search();
        else if (cmd == "EXIT")
            break;
        else
            std::cout << std::endl << "Wrong command!" << std::endl;
    }
    return (0);
}