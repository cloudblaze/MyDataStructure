#include <iostream>
#include "Stack.h"

#define PUSH(item) \
do \
{ \
	std::cout << "Push " << item << " into stack: "; \
	stack.Push(item); \
	std::cout << stack << std::endl; \
} while (false)

#define Pop() \
do \
{ \
	std::cout << "Pop the top item from stack: "; \
	stack.Pop(); \
	std::cout << stack << std::endl; \
} while (false)

#define PRINT(stack) std::cout << #stack << ": " << stack << std::endl

void TestStack()
{
	try
	{
		std::cout << "Create stack: ";
		hy::Stack<int> stack;
		std::cout << "OK" << std::endl;
		
		PUSH(1);
		PUSH(3);
		PUSH(5);
		PUSH(7);
		PUSH(9);

		Pop();
		Pop();
		Pop();
		Pop();
		Pop();
		Pop();
	}
	catch(const std::exception& e)
	{
		std::cerr << "[Error]" << e.what() << '\n';
	}
}