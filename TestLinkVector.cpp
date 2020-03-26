#include <iostream>
#include "LinkVector.h"

#define CREATE(linkVectorNode) \
do \
{ \
	std::cout << "Created " << #linkVectorNode << std::endl; \
} while (false)

#define INSERT(linkVector, index, item) \
do \
{ \
	linkVector.Insert(index, item); \
	std::cout << "After insert " << (item) << " at index " << index << ", now " << #linkVector << ": " << linkVector << std::endl; \
} while (false)

#define APPEND(linkVector, item) \
do \
{ \
	linkVector.AppendLast(item); \
	std::cout << "After append " << (item) << ", now " << #linkVector << ": " << linkVector << std::endl; \
} while (false)

#define REMOVE(linkVector, index) \
do \
{ \
	int lastValue = linkVector.At(index); \
	linkVector.Remove(index); \
	std::cout << "After Remove item of " << #linkVector << " at " << index << "(" << lastValue << "), now " << #linkVector << ": " << linkVector << std::endl; \
} while (false)

#define REMOVE_LAST(linkVector) \
do \
{ \
	int lastValue = linkVector.Last(); \
	linkVector.RemoveLast(); \
	std::cout << "After Remove last item of " << #linkVector << "(" << lastValue << "), now " << #linkVector << ": " << linkVector << std::endl; \
} while (false)

#define AT(linkVector, index) \
do \
{ \
	std::cout << "Item of " << #linkVector << " at " << index << " is [" << linkVector.At(index) << "]." << std::endl; \
} while (false)


void TestLinkVectorNode()
{
	hy::LinkVectorNode<int> linkVectorNode1(5);
	CREATE(linkVectorNode1);
	hy::LinkVectorNode<int> linkVectorNode2(linkVectorNode1);
	CREATE(linkVectorNode2);
	hy::LinkVectorNode<int> linkVectorNode3 = linkVectorNode2;
	CREATE(linkVectorNode3);

	std::cout << "Now, linkVectorNode3: " << linkVectorNode3 << std::endl;

#ifdef DEBUG_INFO
    std::cout << "Info of linkVectorNode3(" << &linkVectorNode3 << "): ";
    linkVectorNode3.PrintInfo(std::cout) << std::endl;
#endif
}

void TestLinkVector()
{
	hy::LinkVector<int> linkVector1;
	hy::LinkVector<int> linkVector2(linkVector1);
	hy::LinkVector<int> linkVector3 = linkVector2;

	std::cout << "Now, linkVector3: " << linkVector3 << std::endl;

	for(int i = 0; i < 10; i++)
	{
		APPEND(linkVector3, i * 2 + 1);
	}

	std::cout << "First item of linkVector3: " << linkVector3.First() << std::endl;

	for(int i = 0; i < 10; i++)
	{
		REMOVE_LAST(linkVector3);
	}

	for(int i = 0; i < 10; i++)
	{
		INSERT(linkVector3, 0, i * 3 + 1);
	}

	for(int i = 0; i < 10; i++)
	{
		AT(linkVector3, i);
	}

	REMOVE(linkVector3, 2);
	REMOVE(linkVector3, -2);
	REMOVE(linkVector3, -1);
	REMOVE(linkVector3, 0);
	REMOVE(linkVector3, -1);
	REMOVE(linkVector3, 0);
	REMOVE(linkVector3, -1);
	REMOVE(linkVector3, 0);
	REMOVE(linkVector3, -1);
	REMOVE(linkVector3, 0);

	for(int i = 0; i < 10; i++)
	{
		INSERT(linkVector3, 0, i * 4 + 1);
	}
	std::cout << "linkVector3[" << 3  << "] is " << linkVector3[3] << std::endl;

#ifdef DEBUG_INFO
    std::cout << "Info of linkVector3: ";
    linkVector3.PrintInfo(std::cout) << std::endl;
#endif
}