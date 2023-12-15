
#include "Time.h"
using namespace std;

istream& operator>>(istream& ist, Time& time)
{
	int hh, minut; // hh:mm
	char dvoetoch[1];
	ist >> hh;
	dvoetoch [0] = ist.get();
	ist >> minut;

	if (ist.fail()) {
		throw std::runtime_error("read from stream failed 7");
	}
	if (dvoetoch[0] != ':') {
		throw std::runtime_error("dot not found");
	}

	if (!Time::is_valid(hh, minut)) {
		throw std::runtime_error("time is invalid");
	}

	time.hour = hh;
	time.minute = minut;

	return ist;
};
ostream& operator<<(ostream& ost, const Time& time)
{
	ost << time.hour << ":" << time.minute;
	return ost;
}
bool Time::is_valid() const
{
	return is_valid(hour, minute);
}
bool Time::is_valid(int hh, int minut)
{
	if (hh < 0 || hh > 23)
	{
		throw std::runtime_error("time is invalid hour ");
	}

	if (minut < 0 || minut > 59)
	{
		throw std::runtime_error("time is invalid minut");
	}
return ;
}