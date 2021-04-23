#ifndef COMMENT_HPP
#define COMMENT_HPP

#include <fstream>
#include <iostream>
#include "String.hpp"
//#include "User.hpp"

class Comment {

private:
	String from; // user
	String comment;

public:
	Comment();
	Comment(const String, const String);

	String commentGetter() const;
	String fromUserGetter() const;
	// TO DO : read & writes in files;

};
#endif // !COMMENT_HPP
