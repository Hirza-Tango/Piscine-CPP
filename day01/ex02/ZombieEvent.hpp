#ifndef ZOMBIE_EVENT_HPP
 #define ZOMBIE_EVENT_HPP

 #include "Zombie.hpp"
 #include <string>

class ZombieEvent
{
public:
	void setZombieType(std::string type);
	Zombie* newZombie(std::string name);
	Zombie randomChump(void);
private:
	std::string _type  = "Normal";
};
#endif
