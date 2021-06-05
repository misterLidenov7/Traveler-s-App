#ifndef LOGIN_MANAGER_HPP
#define LOGIN_MANAGER_HPP

#include "Excursion.hpp"
#include "Vector.hpp"
#include "User.hpp"


class LoginManager {

private:
	User* current;
	Vector<User> allUsers;

public:
	LoginManager();
	~LoginManager();

	User* getCurrent() const;
	Vector<User> getAllUsers() const;

	User* isNameTaken(const User& _user) const;

};


LoginManager::LoginManager()
{
	this->current = nullptr;
}

LoginManager::~LoginManager()
{
	delete[] this->current;
}

User* LoginManager::getCurrent() const
{
	return this->current;
}

Vector<User> LoginManager::getAllUsers() const
{
	return allUsers;
}

User* LoginManager::isNameTaken(const User& _user) const
{
	if (allUsers.isEmpty()) {
		return nullptr;
	}

	for (size_t i = 0; i < allUsers.sizeGetter(); ++i) {

		if (allUsers[i].usernameGetter() == _user.usernameGetter()) {
			return &(allUsers[i]);
		}
	}
	return nullptr;
}

#endif // !LOGIN_MANAGER_HPP
