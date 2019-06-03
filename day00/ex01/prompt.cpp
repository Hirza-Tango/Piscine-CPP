#include "prompt.hpp"

std::string getInput(std::string prompt){
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
	}
	return std::string(input);
}
