#include "Destination.hpp"

Destination::Destination(): avgRating(0.0), city(""), country(""), countVisitors(0){}

Destination::Destination(const double _avgRating, const int visitors, const String _city, const String _country)
{
	avgRating = _avgRating;
	countVisitors = visitors;
	city = _city;
	country = _country;
}

String Destination::getCity() const
{
	return city;
}

String Destination::getCountry() const
{
	return country;
}

double Destination::avgRatingGetter() const
{
	if (countVisitors <= 0) {
		return 0.0;
	}

	return avgRating / countVisitors;
}


int Destination::visitorsGetter() const
{
	return countVisitors;
}

void Destination::citySetter(const String _city)
{
	city = _city;
}

void Destination::coutrySetter(const String _country)
{
	country = _country;
}

void Destination::visitsSetter(const int visits)
{
	if (visits >= 1) {
		countVisitors = visits;
	}
}

void Destination::addVisit(int rating)
{
	if (isValidRating(rating) == true) {

		avgRating += rating;
		countVisitors += 1;
	}
}

bool Destination::isValidRating(int rating)
{
	return (rating >= 1 && rating <= 5);
}

std::ostream& operator<<(std::ostream& out, const Destination& dest)
{
	out << "Place : " << dest.getCity() << ", " << dest.getCountry() << "\n";
	out << "Number of visitors : " << dest.visitorsGetter() << "\n";
	out << "Average rating : " << dest.avgRatingGetter() << "\n";

	return out;
}

std::istream& operator>>(std::istream& input, Destination& dest)
{
	std::cout << "Enter the city : ";
	input >> dest.city;

	std::cout << "Ener the coutry : ";
	input >> dest.country;

	return input;
}