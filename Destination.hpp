#ifndef DESTINATION_HPP
#define DESTINATION_HPP

#include "String.hpp"
#include <fstream>
#include <iostream>

class Destination {

private:
	double avgRating;
	int countVisitors;
	String city;
	String country;

public:
	Destination();
	Destination(const double, const int, const String, const String);

	String getCity() const;
	String getCountry() const;
	double avgRatingGetter() const;
	int visitorsGetter() const;
	
	void citySetter(const String);
	void coutrySetter(const String);
	void visitsSetter(const int);
	void addVisit(int);
	bool isValidRating(int);

	friend std::ostream& operator<<(std::ostream&, const Destination&);
	friend std::istream& operator>>(std::istream&, Destination&);

};

#endif // !DESTINATION_HPP
