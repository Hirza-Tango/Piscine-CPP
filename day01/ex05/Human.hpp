#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human{
public:
	Human();
	const Brain getBrain();
	std::string identify();
private:
	const Brain _brain;
};

#endif
