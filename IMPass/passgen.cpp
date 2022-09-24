/*
Copyright(C) 2022 viwas45hu978ot

This program is free software; you can redistribute itand /or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, see http ://www.gnu.org/licenses/gpl-3.0
*/

#include "passgen.h"
#include "uptime.h"
#include <iostream>
#include <chrono>

long long int seed;
std::string pass;

const int arrSize = 73;
char charArray[arrSize] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0','!','"','#','%','&','/','(',')','=','?','+' };

long long int timeSinceEpochNanosec() {
	using namespace std::chrono;
	return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
}

int CalcSeed()
{
	seed = timeSinceEpochNanosec() - getUptime();
	std::cout << seed << std::endl;
	return seed;
}

std::string GenPass(int length)
{
	pass = "";
	for (int i = 0; i < length; i++)
	{
		srand(CalcSeed());
		pass = pass + charArray[rand() % arrSize];
	}
	return pass;
}