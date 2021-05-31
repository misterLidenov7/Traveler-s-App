#include "Excursion.hpp"

Excursion::Excursion()
{
    start = TimePeriod();
    end = TimePeriod(1999, 1, 2);
    dest  = Destination();
    comm  = Comment();
}

Excursion::Excursion(const TimePeriod _start, const TimePeriod _end, const Destination _dest, const Comment _comm):
    start(_start), end(_end) , dest(_dest), comm(_comm)
{}

TimePeriod Excursion::startGetter() const
{
    return start;
}

TimePeriod Excursion::endGetter() const
{
    return end;
}

Destination Excursion::destGetter() const
{
    return dest; }

Comment Excursion::getComment() const
{
    return comm;
}

std::ostream& operator<<(std::ostream& out, const Excursion& excur)
{
    out << "Destination : " << excur.destGetter().getCity() << ", "
        << excur.destGetter().getCountry();

    if(excur.startGetter() < excur.endGetter())
    {
        out << "\nArrive date : " << excur.startGetter()
            << "\nEnd date : " << excur.endGetter();
    }
    else
    {
        out << "\nArrive date must be before end date !\n";
    }

    out << "\nComment : " << excur.getComment().commentGetter() << "\n";

    return out;
}
