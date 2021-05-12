#ifndef COMMENT_HPP
#define COMMENT_HPP

#include <fstream>
#include <iostream>
#include "String.hpp"
#include "User.hpp"

class Comment {

private:
	User from; 
	String comment;

public:
	Comment();
	Comment(const String);

	String commentGetter() const;
	User fromUserGetter() const;
	// TO DO : read & writes in files;

	friend std::ostream& operator<<(std::ostream&, const Comment&);
	friend std::istream& operator>>(std::istream&, Comment&);

};
#endif // !COMMENT_HPP
