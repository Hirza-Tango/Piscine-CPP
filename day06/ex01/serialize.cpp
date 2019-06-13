#include <string>
#include <stdlib.h>
#include <time.h>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};


char random_alnum(){
    static const char chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	return rand() % (sizeof(chars - 1));
}

void * serialize( void ){
	srand(time(NULL));
	char *area = new char[16 + sizeof(int)];
	for (int i = 0; i < 8; i++){
		area[i] = random_alnum();
	}
	*reinterpret_cast<int *>(area + 8) = rand();
	for (int i = 0; i < 8 ; i++){
		area[i + 8 + sizeof(int)] = random_alnum();
	}
	return reinterpret_cast<void *>(area);
}

Data * deserialize( void * raw ){
	Data *ret = new Data;
	ret->s1 = std::string(reinterpret_cast<char *>(raw), 8);
	ret->n = *reinterpret_cast<int *>(raw + 8);
	ret->s2 = std::string(reinterpret_cast<char *>(raw + 8 + sizeof(int)), 8);
	return ret;
}
