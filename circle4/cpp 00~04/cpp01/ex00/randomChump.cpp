#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie zombie(name); 
    zombie.announce();
}

/**
 * 스택에 생성
 * 함수 블록을 벗어나면 소멸
 * 자동으로 메모리에서 해제됨
 */
