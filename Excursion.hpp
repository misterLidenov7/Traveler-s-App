#ifndef EXCURSION_HPP
#define EXCURSION_HPP

#include "TimePeriod.hpp"
#include "Vector.hpp"
#include "Destination.hpp"
#include "Comment.hpp"

class Excursion{

private:
    TimePeriod start;
    TimePeriod end;
    Destination dest;
    Comment comm;

public:
    Excursion();
    Excursion(const TimePeriod _start, const TimePeriod _end, const Destination _dest, const Comment _comm);

    TimePeriod startGetter() const;
    TimePeriod endGetter() const;

    Destination destGetter() const;

    Comment getComment() const;

    friend std::ostream& operator<<(std::ostream& out, const Excursion& excur);
};

#endif // !EXCURSION_HPP
