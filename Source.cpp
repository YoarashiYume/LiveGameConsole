#include <iostream>
#include "Field.h"

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cout << "usage: <prog-name> <fieldSize> <countOfGeneration>\n";
		return 1;
	}
	int fieldSize = std::atoi(argv[1]);
	int countOfGeneration = std::atoi(argv[2]);
	Field field(fieldSize);
	field.startGame(countOfGeneration);
	return 0;
}