#include <iostream>
#include "passgen.h"

#ifdef _WIN32
#define clear system("cls");
#elif defined __unix__
#define clear system("clear");
#elif defined __APPLE__
#define clear system("clear");
#endif

int main()
{
	std::cout << GenPass(32);
}