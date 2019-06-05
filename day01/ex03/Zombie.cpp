#include "Zombie.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

const std::string zombieNames[] = {
	"ZombieA", "ZomB", "ZomC", "ZombieD", "ZombE", "ZombieF", "ZomG", "ZombieH",
	"ZombII", "ZombieJ", "ZombieK", "ZombieL", "Mombie", "Nombie", "Ombie"
	};

Zombie::Zombie(std::string name, std::string type){
	_name = name;
	_type = type;
}

Zombie::Zombie(){
	std::string name = zombieNames[rand() % 15];
	std::cout << "Created a zombie named " << name << std::endl;
	_name = name;
	_type = "Normal";
}

void Zombie::announce(void){
	std::cout << "<" << _name << " (" << _type <<")> Braiiiiiiins" << std::endl;
}
