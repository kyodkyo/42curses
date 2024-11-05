#include <string>
#include <iostream>

int main(void){
    std::string str = "HI THIS IS BRAIN";
    std::string *strPTR = &str;
    std::string &strREF = str;

    std::cout << "----- Memory address -----" << std::endl;
    std::cout << "[      string      ] : " << &str << std::endl;
    std::cout << "[  string pointer  ] : " << strPTR << std::endl;
    std::cout << "[ string reference ] : " << &strREF << std::endl;

    std::cout << std::endl << "--------- Value ---------" << std::endl;
    std::cout << "[      string      ] : " << str << std::endl;
    std::cout << "[  string pointer  ] : " << *strPTR << std::endl;
    std::cout << "[ string reference ] : " << strREF << std::endl;
}
