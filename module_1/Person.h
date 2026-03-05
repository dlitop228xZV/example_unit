#pragma once

#include <string>
using std::string;

class Person
{
public:
	enum Gender { UNDEF, MALE, FEMALE };

private:

	Gender gender;

	string name;
	int age;

public:

	Person(string n, int a, Gender g);
	Person(string n, int a);
	Person(string n, Gender g);
	Person(string n);
	Person(int a);
	Person(Gender g);
	Person();

	string GetName();
	int GetAge();
	Gender GetGender();
};