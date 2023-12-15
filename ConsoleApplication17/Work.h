#pragma once
#include "Data.h"
#include "Time.h"

struct Work
{
	Data data;
	Time time;
	string owner;
	bool is_valid() const;

	friend std::ostream& operator<<(std::ostream& ost, Work& work);
	friend std::istream& operator>>(std::istream& ist, Work& work);

private:
	static bool is_valid(string name);

};


