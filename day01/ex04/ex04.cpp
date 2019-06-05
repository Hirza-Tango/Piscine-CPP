#include <string>
#include <iostream>

int main(){
	std::string brain = "HI THIS IS BRAIN";
	std::string *pointer = &brain;
	std::string &reference = brain;
	std::cout << "Pointer: " << *pointer << std::endl;
	std::cout << "Reference: " << reference << std::endl;
}
