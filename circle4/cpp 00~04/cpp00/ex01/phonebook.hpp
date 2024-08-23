#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook{
    private:
        Contact contacts[8];
        int idx;
        int size;

    public:
        PhoneBook();
        void Add();
        void Search();

};

#endif