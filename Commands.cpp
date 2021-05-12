#include "Commands.hpp"

String Commands::commandGetter() const {
	return commandName;
}

void Commands::inputCommand()
{
	std::cin >> commandName;
}
