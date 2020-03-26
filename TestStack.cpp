#include <iostream>
#include "Stack.h"

#define PUSH(item) \
do \
{ \
	stack.Push(item); \
	std::cout << "Push " << item << " into stack, and now: " << stack << std::endl; \
} while (false)

#define POP() \
do \
{ \
	std::cout << "Pop the top item " << stack.Pop() << " from stack, and now: " << stack << std::endl; \
} while (false)

#define TOP() \
do \
{ \
	std::cout << "Get the top item from stack: " << stack.Top() << std::endl; \
} while (false);


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

		TOP();

		POP();
		POP();
		POP();
		POP();
		POP();
		
		PUSH(11);
		PUSH(13);
		PUSH(15);
		PUSH(17);
		PUSH(19);

		POP();
		POP();
		POP();
		POP();
		POP();
		POP();
	}
	catch(const std::exception& e)
	{
		std::cerr << "[Error]" << e.what() << '\n';
	}
}