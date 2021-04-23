#include "Comment.hpp"

Comment::Comment(): from(""), comment(""){}

Comment::Comment(const String _from, const String _comment)
{
	from = _from;
	comment = _comment;
}

String Comment::commentGetter() const
{
	return comment;
}

String Comment::fromUserGetter() const
{
	return from;
}