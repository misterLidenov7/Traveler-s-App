#ifndef COMMANDS_HPP
#define COMMAND_HPP

#include "String.hpp"
#include "Vector.hpp"
#include <iostream>

class Commands {

private:
	String commandName;


public:
	String commandGetter() const;
	void inputCommand();
	
};

#endif // COMMANDS_HPP
