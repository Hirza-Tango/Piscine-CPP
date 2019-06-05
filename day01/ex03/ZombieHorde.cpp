#include "ZombieHorde.hpp"
#include <iostream>

ZombieHorde::ZombieHorde(size_t size){
	_size = size;
	std::cout << "Creating a hoard of size " << size << std::endl;
	zombies = new Zombie[size];
}

ZombieHorde::~ZombieHorde(){
	delete[] zombies;
}
