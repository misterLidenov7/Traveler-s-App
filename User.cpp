#include "User.hpp"

User::User() : username(""), password(""), email(""){}

User::User(const String _username, const String _password, const String _email)
{
	username = _username;
	password = _password;
	email = _email;
}

String User::usernameGetter() const
{
	return username;
}

String User::passwordGetter() const
{
	return password;
}

String User::emailGetter() const
{
	return email;
}

Vector<String> User::friendsGetter() const
{
	return friends;
}

void User::usernameSetter(const String _username)
{
	if (isValidUsername(_username) == true) {
		username = _username;
	}
}

void User::passwordSetter(const String pass)
{
	if (isValidPassword(pass) == true) {
		password = pass;
	}
}

void User::emailSetter(const String _email)
{
	email = _email;
}

void User::addFriend(const String addFriend)
{
	friends.pushBack(addFriend);
}

bool User::isValidPassword(const String password) const
{
	bool isCapital = false, isLower = false, isDigit = false, isSpecial = false;
	bool isInRange = password.myLen() >= 8 && password.myLen() < 17;

	for (int i = 0; i < password.myLen(); i++)
	{
		if (password[i] >='0' && password[i] <= '9'){
			isDigit = true;
		}
		else if (password[i] >= 'a' && password[i] <= 'z') {
			isLower = true;
		}
		else if(password[i] >= 'A' && password[i] <= 'Z') {
			isCapital = true;
		}
		else if (password[i] == '$' || password[i] == '*' || password[i] == '#' || password[i] == '@') {
			isSpecial = true;
		}
	}
	return (isCapital && isLower && isSpecial && isDigit && isInRange);
}

bool User::isValidUsername(const String name) const
{
	bool isInRange = name.myLen() > 7 && name.myLen() < 13;
	bool isCapital = false, isSmall = false;

	for (size_t i = 0; name[i] != '\0'; ++i) {

		if (name[i] >= 'a' && name[i] <= 'z') {
			isSmall = true;
		}

		else if (name[i] >= 'A' && name[i] <= 'Z') {
			isCapital = true;
		}
	}
	return (isInRange && isCapital && isSmall);
}

String User::encryption(String msg) const
{
	for (int i = 0; msg[i] != '\0'; i++) {
		msg[i] += i;
	}
	return msg;
}

String User::decryption(String msg) const
{
	for (int i = 0; msg[i] != '\0'; i++) {
		msg[i] -= i;
	}
	return msg;
}

void User::writeInFile(const User& u)
{
	//String user_db = u.usernameGetter() + ".db";

	std::ofstream userFile;
	userFile.open("user.db", std::ios::out);

	if (!userFile.is_open())
	{
		std::cout << "Your fail didn't work !\n";
	}
	else {

		if (isValidUsername(u.username) == true) {
			userFile << encryption(u.usernameGetter()) << std::endl;
		}
		else {
			std::cout << "Invalid username!\n";
		}

		if (isValidPassword(u.password) == true) {
			userFile << encryption(u.passwordGetter()) << std::endl;
		}
		else {
			std::cout << "Invalid password!\n";
		}
		userFile << encryption(u.emailGetter()) << std::endl;
	}

	userFile.close();
}

void User::readInFile(User& u)
{
	std::ifstream userFile;
	userFile.open("user.db", std::ios::in);

	if (userFile.fail()) 
	{
		std::cout << "Your fail didn't work !\n";
	}
	else
	{
		String info;
		while (userFile >> info)
		{
			std::cout << decryption(info) << '\n';
		}
	}
	userFile.close();
}

std::ostream& operator<<(std::ostream& out, const User& user)
{
	if (user.isValidUsername(user.username) == true) {
		out << "Username : " << user.usernameGetter() << std::endl;
	}
	else {
		out << "Inavlid username !\n";
		exit(1);
	}

	if (user.isValidPassword(user.password) == true) {
		out << "Password : " << user.passwordGetter() << std::endl;
	}
	else {
		out << "Inavlid password !\n";
		exit(1);
	}

	out << "Email : " << user.emailGetter() << std::endl;
	return out;
}

std::istream& operator>>(std::istream& input, User& u)
{
	std::cout << "Enter username : ";
	input >> u.username;

	std::cout << "Enter password : ";
	input >> u.password;

	std::cout << "Enter email : ";
	input >> u.email;

	return input;
}
