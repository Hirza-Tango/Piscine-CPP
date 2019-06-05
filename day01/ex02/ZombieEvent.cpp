#include "ZombieEvent.hpp"
#include <stdlib.h>
#include <time.h>

const std::string zombieNames[] = {"John", "Mark", "Tcheench", "Randy", "Bill"};

void ZombieEvent::setZombieType(std::string type){
	_type = type;
}

// Allocated on heap because it returns a pointer. If it was on the stack,
	// The zombie would be in an undefined state upon leaving scope
Zombie* ZombieEvent::newZombie(std::string name){
	return new Zombie(name, _type);
}

// Allocated on the stack because it returns an instance. The stack instance
	// will then be passed to the calling function
Zombie ZombieEvent::randomChump(void){
	srand (time(NULL));
	Zombie zombie = Zombie(zombieNames[rand() % 3], _type);
	zombie.announce();
	return zombie;
}
