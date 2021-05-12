#include "Comment.hpp"

Comment::Comment()
{ 
	from.usernameSetter("");
	comment = "";
}

Comment::Comment(const String _comment)
{
	comment = _comment;
}

String Comment::commentGetter() const
{
	return comment;
}

User Comment::fromUserGetter() const
{
	return from;
}

std::ostream& operator<<(std::ostream& out, const Comment& comm)
{
	out << comm.commentGetter();

	return out;
}

std::istream& operator>>(std::istream& input , Comment& com)
{
	input >> com.comment;

	return input;
}
