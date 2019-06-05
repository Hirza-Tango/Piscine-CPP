#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

void exit_reason(std::string reason, int code){
	std::cout << reason << std::endl;
	exit(code);
}

//Why oh why can't I use iterators *cries*
std::string find_replace(std::string input, std::string find, std::string replace){
	size_t pos = 0;
	size_t find_length = find.length();
	size_t replace_length = replace.length();
		//find returns std::string::npos if not found. npos is basically the
			//max length of a string
	while((pos = input.find(find, pos)) != std::string::npos){
		input.replace(pos, find_length, replace);
		pos += replace_length;
	}
	return input;
}

int main(int argc, char **argv){
	if (argc != 4) exit_reason("Incorrect number of arguments", 2);
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string find = std::string(argv[2]);
	std::string replace = std::string(argv[3]);
	std::string line;

	inputFile.open(argv[1]);
	outputFile.open(strcat(argv[1], ".replace"));
	if (!inputFile.is_open() || !outputFile.is_open()){
		exit_reason("Could not open files", 3);
	}
	while(std::getline(inputFile, line) && outputFile.good()){
		outputFile << find_replace(line, find, replace) << std::endl;
	}
	if (inputFile.bad() || outputFile.bad()){
		exit_reason("Read/write could not complete", 4);
	}
	inputFile.close();
	outputFile.close();
}
