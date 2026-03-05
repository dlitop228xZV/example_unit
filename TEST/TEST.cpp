#include "pch.h"
#include "CppUnitTest.h"
#include "../module_1/Person.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TEST
{
    TEST_CLASS(MODULE_1_PERSON)
    {
    public:

#pragma region NAME
        TEST_METHOD(MAX_LENGTH_NAME)
        {
            std::string name(50, 'a');
            Person person{ name };

            std::string expected(40, 'a');
            Assert::AreEqual(expected.c_str(), person.GetName().c_str());
        }

        TEST_METHOD(NORMAL_NAME)
        {
            std::string name = "Oleg";
            Person person{ name };
            Assert::AreEqual(name.c_str(), person.GetName().c_str());
        }

        TEST_METHOD(NAME_EMPTY_NONAME)
        {
            std::string name = "";
            Person person{ name };

            std::string expected = "NoName";
            Assert::AreEqual(expected.c_str(), person.GetName().c_str());
        }
#pragma endregion

#pragma region AGE
        TEST_METHOD(AGE_DEFAULT_IS_ZERO_WHEN_ONLY_NAME)
        {
            Person person{ std::string("Oleg") };
            Assert::AreEqual(0, person.GetAge());
        }

        TEST_METHOD(AGE_NEGATIVE_BECOMES_ZERO)
        {
            Person person{ std::string("Oleg"), -5 };
            Assert::AreEqual(0, person.GetAge());
        }

        TEST_METHOD(AGE_TOO_BIG_BECOMES_ZERO)
        {
            Person person{ std::string("Oleg"), 150 };
            Assert::AreEqual(0, person.GetAge());
        }

        TEST_METHOD(AGE_MIN_BORDER_0_OK)
        {
            Person person{ std::string("Oleg"), 0 };
            Assert::AreEqual(0, person.GetAge());
        }

        TEST_METHOD(AGE_MAX_BORDER_100_OK)
        {
            Person person{ std::string("Oleg"), 100 };
            Assert::AreEqual(100, person.GetAge());
        }

        TEST_METHOD(AGE_CONSTRUCTOR_INT_ONLY_OK)
        {
            Person person{ 25 };
            Assert::AreEqual(25, person.GetAge());
            Assert::AreEqual("NoName", person.GetName().c_str());
            Assert::AreEqual((int)Person::UNDEF, (int)person.GetGender());
        }
#pragma endregion

#pragma region GENDER
        TEST_METHOD(GENDER_DEFAULT_UNDEF_WHEN_ONLY_NAME)
        {
            Person person{ std::string("Oleg") };
            Assert::AreEqual((int)Person::UNDEF, (int)person.GetGender());
        }

        TEST_METHOD(GENDER_MALE_OK)
        {
            Person person{ std::string("Oleg"), Person::MALE };
            Assert::AreEqual((int)Person::MALE, (int)person.GetGender());
            Assert::AreEqual(0, person.GetAge());
        }

        TEST_METHOD(GENDER_FEMALE_OK)
        {
            Person person{ std::string("Anna"), Person::FEMALE };
            Assert::AreEqual((int)Person::FEMALE, (int)person.GetGender());
        }

        TEST_METHOD(GENDER_INVALID_LOW_BECOMES_UNDEF)
        {
            auto bad = (Person::Gender)-100;
            Person person{ std::string("Oleg"), 20, bad };
            Assert::AreEqual((int)Person::UNDEF, (int)person.GetGender());
        }

        TEST_METHOD(GENDER_INVALID_HIGH_BECOMES_UNDEF)
        {
            auto bad = (Person::Gender)100;
            Person person{ std::string("Oleg"), 20, bad };
            Assert::AreEqual((int)Person::UNDEF, (int)person.GetGender());
        }

        TEST_METHOD(GENDER_CONSTRUCTOR_ONLY_GENDER_OK)
        {
            Person person{ Person::FEMALE };
            Assert::AreEqual("NoName", person.GetName().c_str());
            Assert::AreEqual(0, person.GetAge());
            Assert::AreEqual((int)Person::FEMALE, (int)person.GetGender());
        }
#pragma endregion

    };
}
