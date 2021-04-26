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

void User::writeInFile(const User& u)
{
	std::ofstream userFile;
	userFile.open("user.db", std::ios::binary);
	userFile << u.usernameGetter() << std::endl;
	userFile << u.emailGetter() << std::endl;
	userFile << u.passwordGetter() << std::endl;

	userFile.close();
}

std::ostream& operator<<(std::ostream& out, const User& user)
{
	out << "Username : " << user.usernameGetter() << std::endl;
	out << "Email : " << user.emailGetter() << std::endl;
	
	if (user.isValidPassword(user.password) == true) {
		out << "Password : " << user.passwordGetter() << std::endl;
	}
	else {
		out << "Inavlid password !\n";
	}
	return out;
}
