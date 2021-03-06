#include <iostream>
#include "test.h"

using namespace std;

#define TEST(fun) \
do \
{ \
	cout << "***** " #fun " *****" << endl; \
	fun(); \
	cout << endl; \
} while (false)


int main()
{
	try
	{
		TEST(TestVector);
		TEST(TestLinkVector);
		TEST(TestStack);
		TEST(TestQueue);
	}
	catch(const std::exception& e)
	{
		std::cerr << "[ERROR] " << e.what() << '\n';
	}

	return 0;
}