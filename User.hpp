#ifndef USER_HPP
#define USER_HPP

#include "Vector.hpp"
#include "String.hpp"
#include <iostream>
#include <fstream>

class User {

private:
	String username;
	String password;
	String email;
	Vector<String> friends;

	// TO DO : list of friends in vector
	// и още нещо, 'дет не се сещам... за сега

public:
	User();
	User(const String, const String, const String);

	String usernameGetter() const;
	String passwordGetter() const;
	String emailGetter() const;
	Vector<String> friendsGetter() const;

	void addFriend(const String);
	bool isValidPassword(const String) const;
	
	friend std::ostream& operator<<(std::ostream&, const User&);
	void writeInFile(const User&); // this is just tester

};
#endif // !USER_HPP
