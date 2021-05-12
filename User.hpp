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

public:
	User();
	User(const String, const String, const String);

	String usernameGetter() const;
	String passwordGetter() const;
	String emailGetter() const;
	Vector<String> friendsGetter() const;

	void usernameSetter(const String);
	void passwordSetter(const String);
	void emailSetter(const String);

	void addFriend(const String);
	bool isValidPassword(const String) const;
	bool isValidUsername(const String) const;

	String encryption(String) const;
	//This will be used for files, for that they can not be read by people

	String decryption(String) const;
	//This will be used for files, in case we need readable information

	void writeInFile(const User&);
	void readInFile(User&);

	friend std::ostream& operator<<(std::ostream&, const User&);
	friend std::istream& operator>>(std::istream&, User&);
	//TO DO : Writing password in hidden form.
};
#endif // !USER_HPP
