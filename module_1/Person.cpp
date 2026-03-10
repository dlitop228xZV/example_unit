#include "Person.h"
 
Person::Person(string n, int a, Gender g)
    : name{ n }, age{ a }, gender{ g }
{
    if (name.empty())
        name = "NoName";

    if (name.size() > 40)
        name.resize(40);

    if (age < 0 || age > 100)
        age = 0;

    if (gender < UNDEF || gender > FEMALE)
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
