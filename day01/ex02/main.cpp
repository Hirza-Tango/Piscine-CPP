#include "ZombieEvent.hpp"
#include <iostream>
int main(){
	ZombieEvent event;
	std::cout << "Creating Zombie event" << std::endl;
	std::cout << "Setting Zombie type to boomer" << std::endl;
	event.setZombieType("Boomer");
	std::cout << "Here's a random zombie" << std::endl;
	Zombie zombieA = event.randomChump();
	std::cout << "Sorry, didn't hear that..." << std::endl;
	zombieA.announce();
	std::cout << "Here's a new zombie named Charles" << std::endl;
	Zombie* zomB = event.newZombie("Charles");
	std::cout << "He's a bit shy. Say hi!" << std::endl;
	zomB->announce();
	std::cout << "Random zombie will die on his own." << std::endl;
	std::cout << "Let's clean up ZomB" << std::endl;
	delete zomB;
}
