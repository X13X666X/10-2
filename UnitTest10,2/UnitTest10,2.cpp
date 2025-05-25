#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include <cstdio>
#include "../10,2/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102
{
	TEST_CLASS(UnitTest102)
	{
	public:

		TEST_METHOD(Test_ProcessFile_RemovesNonLettersBeforeFirstSpace)
		{
			const char* inputFile = "test_input.txt";
			const char* outputFile = "test_output.txt";

			ofstream fout(inputFile);
			fout << "123a!b@c D456ef gh!12iJKL" << endl;
			fout.close();

			ProcessFile(inputFile, outputFile);

			ifstream fin(outputFile);
			string result;
			getline(fin, result);
			fin.close();

			string expected = "abc D456ef gh!12iJKL";
			Assert::AreEqual(expected, result);

			remove(inputFile);
			remove(outputFile);
		}
	};
}
