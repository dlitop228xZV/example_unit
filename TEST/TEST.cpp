#include "pch.h"
#include "CppUnitTest.h"
#include "../module_1/Person.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TEST
{
	TEST_CLASS(MODULE_1_PERSON)
	{
	public:

		TEST_METHOD(MAX_LENGTH_NAME)
		{
			std::string name(50, 'a');

			Person person{ name };

			std::string expected(40, 'a');

			Assert::AreEqual(expected, person.GetName());
		}


		TEST_METHOD(NORMAL_NAME)
		{
			std::string name = "Oleg";
			Person person{ name };
			Assert::AreEqual(name, person.GetName());
		}


		TEST_METHOD(NAME_EMPTY_NONAME)
		{
			std::string name = "";
			Person person{ name };
			std::string expected = "NoName";
			Assert::AreEqual(expected, person.GetName());
		}

	};
}
