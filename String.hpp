#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>

class String {

private:
	char* string;

private:
	void copy(const String&);
	void destroy();

public:
	String();
	String(const char*);
	String(const String&);
	~String();

	char* strGetter() const;
	void strSetter(const char*);
	int myLen() const;

	String& operator=(const String&);
	String operator+(const String&);
	bool operator==(const String&);
	bool operator!=(const String&);
	bool operator>(const String&);
	bool operator<(const String&);
	char& operator[](const int) const;
	//TO DO : write in files
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);
};