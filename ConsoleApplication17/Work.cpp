
#include "Work.h"
using namespace std;

istream& operator>>(istream& ist, Work& work)
{
	string name;

	ist >> work.data;
	ist >> work.time;
	ist >> name;
	
	if (ist.fail()) {
		throw std::runtime_error("read from stream failed");
	}

	if (!Work::is_valid(name)) {
		throw std::runtime_error("time is invalid");
	}

	work.owner = name;
	return ist;
};
ostream& operator<<(ostream& ost, const Work&work)
{
	ost << work.data << " " << work.time << " " << work.owner << endl;
	return ost;
}

bool Work::is_valid() const
{
	return is_valid(owner);
}
bool Work::is_valid(string name)
{
	if (!isupper(name[0])) // встроенная функция для проверки заглавной букы
	{
		throw std::runtime_error("The name does not start with a capital letteк(ne s zaglavnoi bykvi)");
	}

	for (size_t i = 1; i < name.length(); ++i) {
		if (!islower(name[i])) // встроенная функция для проверки имени, чтобы после заглавной шли только строчные буквы
		{
			throw std::runtime_error("The name does not continue from lowercase letters(ne iz strochnix)");
		}
	}

}