#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_num;
        std::string darkest_secret;

    public:
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNum() const;
        std::string getDarkestSecret() const;
        void setFirstName();
        void setLastName();
        void setNickName();
        void setPhoneNum();
        void setDarkestSecret();
};

#endif