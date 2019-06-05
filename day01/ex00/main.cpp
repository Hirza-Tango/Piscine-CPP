#include "Pony.hpp"
#include <iostream>
int main(void){
	std::cout << "Allocating a pony on the stack..." << std::endl;
	ponyOnTheStack("Lancastreshire", male, 180);
	std::cout << "Allocating a pony on the heap..." << std::endl;
	ponyOnTheHeap("WLANcastreshire", female, 160);
}
