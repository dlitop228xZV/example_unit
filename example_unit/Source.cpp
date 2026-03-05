#include <iostream>
#include "../module_1/Person.h"
using namespace std;

int main()
{
	Person p{ "Oleg",35,Person::MALE };

	cout << "# | Person | -" << endl
		<< "\t> NAME   : " << p.GetName() << endl
		<< "\t> AGE    : " << p.GetAge() << endl
		<< "\t> GENDER : " << p.GetGender() << endl;

	return 0;
}