#include "Zombie.hpp"

Zombie  *newZombie(std::string name){
    Zombie* zombie = new Zombie(name);
    return zombie;
}

/**
 * 힙에 생성 (동적 할당)
 * 재사용이 가능하도록 반환
 * delete 연산자를 통해 수동으로 메모리에서 해제해야 함
 */
