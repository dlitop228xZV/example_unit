#include "Person.h"

#define MAX_NAME_SIZE 40
#define CHECK_NAME_SIZE name.size() > MAX_NAME_SIZE
#define CHECK_AGE age < 0 || age > 100
#define CHECK_GENDER gender < UNDEF || gender > FEMALE

Person::Person(string n, int a, Gender g) : name{ n }, age{ a }, gender{ g }
{
	if (CHECK_NAME_SIZE)
		name.resize(MAX_NAME_SIZE);
	
	if (CHECK_AGE)
		age = 0;

	if (CHECK_GENDER)
		gender = UNDEF;
}

Person::Person(string n, int a) : Person(n,a,Person::UNDEF)
{
}

Person::Person(string n, Gender g) : Person(n,0,g)
{
}

Person::Person(string n) : Person(n,0,Person::UNDEF)
{
}

Person::Person(int a) : Person("NoName",a, Person::UNDEF)
{
}

Person::Person(Gender g) : Person("NoName", 0, g)
{
}

Person::Person() : Person("NoName", 0, Person::UNDEF)
{
}

string Person::GetName()
{
	return name;
}

int Person::GetAge()
{
	return age;
}

Person::Gender Person::GetGender()
{
	return gender;
}
