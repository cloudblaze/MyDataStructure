#include <iostream>
#include "Queue.h"

#define ENQUEUE(queue, item) \
do \
{ \
	queue.EnQueue(item); \
	std::cout << "EnQueue " << item << " into queue, and now: " << queue << std::endl; \
} while (false)

#define DEQUEUE(queue) \
do \
{ \
	std::cout << "DeQueue the last item " << queue.DeQueue() << " from queue, and now: " << queue << std::endl; \
} while (false)

void TestQueue()
{
	try
	{
		std::cout << "Create queue: ";
		hy::Queue<int> queue;
		std::cout << "OK" << std::endl;

		for(int i = 0; i < 10; i++)
		{
			ENQUEUE(queue, i);
		}

		for(int i = 0; i < 10; i++)
		{
			DEQUEUE(queue);
		}
		DEQUEUE(queue);
	}
	catch(const std::exception& e)
	{
		std::cerr << "[Error]" << e.what() << '\n';
	}
	
}