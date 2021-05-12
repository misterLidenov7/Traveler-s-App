#include "String.hpp"

void String::copy(const String& other)
{
	string = new char[strlen(other.string) + 1];
	strcpy(string, other.string);
}

void String::destroy()
{
	delete[] this->string;
	this->string = nullptr;
}

String::String(): string(nullptr){}

String::String(const char* str)
{
	string = new char[strlen(str) + 1];
	strcpy(string, str);
}

String::String(const String& other)
{
	copy(other);
}

String::~String()
{
	destroy();
}

char* String::strGetter() const
{
	return this->string;
}

void String::strSetter(const char* str){

	string = new char[strlen(str) + 1];
	strcpy(string, str);
}

int String::myLen() const
{
	return strlen(string);
}

String& String::operator=(const String& other)
{
	if (this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}

String String::operator+(const String& other)
{
	char *result = new char[strlen(string) + strlen(other.string) + 1];
	strcpy(result, string);
	strcat(result, other.string);

	String help(result);
	delete[] result;

	return help;
}

bool String::operator==(const String& other)
{
	return strcmp(string, other.string) == 0;
}

bool String::operator!=(const String& other)
{
	return !strcmp(string, other.string) == 0;
}

bool String::operator>(const String& other)
{
	for (int i = 0; i < std::min<int>(strlen(string), strlen(other.string)); ++i) {
		if (string[i] > other.string[i]) {
			return true;
		}
	}
	return false;
}

bool String::operator<(const String& other)
{
	for (int i = 0; i < std::min<int>(strlen(string), strlen(other.string)); i++) {
		if (string[i] < other.string[i]) {
			return true;
		}
	}
	return false;
}

char& String::operator[](const int i) const
{
	
	return string[i];

}

String String::encryption(String msg)
{
	for (size_t i = 0; i < msg.myLen(); i++) {
		msg[i] = msg[i] + i;
	}
	return msg;
}

String String::decryption(String msg)
{

	for (size_t i = 0; i < msg.myLen(); i++) {
		msg[i] = msg[i] - i;
	}
	return msg;
}

std::ostream& operator<<(std::ostream& out, const String& obj)
{
	out << obj.string;
	return out;
}

std::istream& operator>>(std::istream& input, String& obj)
{
	char* buff = new char[100];
	input.getline(buff, 100);
	obj = String(buff);
	delete[] buff;

	return input;
}