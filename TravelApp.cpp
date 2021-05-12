#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include "TimePeriod.hpp"
#include "String.hpp"
#include "Vector.hpp"
#include "User.hpp"
#include "Comment.hpp"
#include "Destination.hpp"


int main() {

	system("Color 0A"); // black background & green text 

	User az;
	
	std::cin >> az;

	az.writeInFile(az);
	az.readInFile(az);

	return 0;
}
