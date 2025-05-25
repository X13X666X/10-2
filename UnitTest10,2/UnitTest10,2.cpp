#include "pch.h"
#include "CppUnitTest.h"
#include "../10,2/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102
{
	TEST_CLASS(UnitTest102)
	{
	public:

		TEST_METHOD(Test_FilterLettersBeforeSpace)
		{
			std::string input = "123Hel!lo Wo*rld this is a test";
			std::string expected = "Hello";
			std::string actual = FilterLettersBeforeSpace(input);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test_NoLettersBeforeSpace)
		{
			std::string input = "1234!@#$ %Hello";
			std::string expected = "";
			std::string actual = FilterLettersBeforeSpace(input);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test_AllLettersNoSpace)
		{
			std::string input = "HelloWorld";
			std::string expected = "HelloWorld";
			std::string actual = FilterLettersBeforeSpace(input);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Test_EmptyString)
		{
			std::string input = "";
			std::string expected = "";
			std::string actual = FilterLettersBeforeSpace(input);
			Assert::AreEqual(expected, actual);
		}
	};
}
