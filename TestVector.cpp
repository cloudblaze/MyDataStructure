#include <iostream>
#include "Vector.h"

#define CREATE(vector) \
do \
{ \
	std::cout << "Created " << #vector << std::endl; \
} while (false)


void TestVector()
{
	hy::Vector<int> vector1;
	CREATE(vector1);
	hy::Vector<int> vector2(100);
	CREATE(vector2);
	hy::Vector<int> vector3(vector2);
	CREATE(vector3);
	hy::Vector<int> vector4 = vector3;
	CREATE(vector4);
	hy::Vector<int> vector5;
	vector5 = vector4;
	CREATE(vector5);

	std::cout << "Now, vector5: " << vector5 << std::endl;

	vector5[13] = 88;
	std::cout << "Set vector5[13] with 88, vector5: " << vector5 << std::endl;

	vector5.Resize(10);
	std::cout << "Resize to " << 10 << ", vector5: " << vector5 << std::endl;

	vector5[3] = 99;
	std::cout << "Set vector5[3] with 99, vector5: " << vector5 << std::endl;

	std::cout << "Size of vector5[3]: " << vector5.Size() << std::endl;

#ifdef DEBUG_INFO
	std::cout << "Info of vector5: ";
	vector5.PrintInfo(std::cout) << std::endl;
#endif
}