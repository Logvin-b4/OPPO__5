
#include "Work.h"


using namespace std;
void input(ifstream& ist, vector <Work>& works) {
	while (false == ist.eof()) {
		Work work;
		ist >> work;
		work.push_back(work);
	}
}

void output(const <Work>& works) {
	for (Work work : works) {
		cout << work;
	}
}



int main()
{
	setlocale(0, "Rus");
	ifstream ist("in.txt");
	const <Work> works;
	try {
		input(ist, works);
		output(works);
	}
	catch (std::runtime_error& err) {
		std::cerr << err.what();
	}

	return 0;
}