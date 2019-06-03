#include <string>
#include <iostream>
#include "PhoneBook.hpp"
#include "prompt.hpp"

int main(){
	std::string command;
	PhoneBook phonebook;
	do {
		command = getInput("PHONEBOOK> ");
		if (std::cin.eof()){
			std::cout << std::endl;
			break;
		}
		if (command == "ADD"){
			phonebook.add();
		} else if (command == "SEARCH") {
			phonebook.search();
		} else if (command == "") {
			continue;
		} else if (command != "EXIT"){
			std::cout << "ERROR: Unrecognized command" << std::endl;
		}
	} while (command != "EXIT");
	std::cout << "Goodbye!" << std::endl;
}
