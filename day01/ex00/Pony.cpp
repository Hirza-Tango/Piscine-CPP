#include "Pony.hpp"
#include <iostream>

Pony::Pony(std::string breed, t_sex sex, size_t height){
	_breed = breed;
	_sex = sex;
	_height = height;
	std::cout << "A pony has been created" << std::endl;
}

Pony::~Pony(){
	std::cout << "A pony has been destroyed" << std::endl;
}

void Pony::showPony(){
	std::cout << "This is a " <<  (_sex == male ? "male" : "female") << " "
		<< _breed << " pony with a height of " << _height << " centimeters\n";
}

void ponyOnTheHeap(std::string breed, t_sex sex, size_t height){
	Pony *pony = new Pony(breed, sex, height);
	pony->showPony();
	delete pony;
}

void ponyOnTheStack(std::string breed, t_sex sex, size_t height){
	Pony pony = Pony(breed, sex, height);
	pony.showPony();
}
