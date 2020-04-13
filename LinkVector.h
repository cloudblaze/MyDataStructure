#ifndef LINK_VECTOR_H
#define LINK_VECTOR_H

#include <iostream>
#include <cstring>

namespace hy
{
template <typename T>
class LinkVector
{
	struct LinkVectorNode
	{
	public:
		LinkVectorNode *Prev;
		LinkVectorNode *Next;
		T Data;

		LinkVectorNode(const T &data = T())
		{
			Prev = this;
			Next = this;
			Data = data;
		}

		LinkVectorNode(const LinkVectorNode &linkVectorNode)
		{
			Prev = this;
			Next = this;
			Data = linkVectorNode.Data;
		}

		LinkVectorNode &operator=(const LinkVectorNode &linkVectorNode)
		{
			if (this == &linkVectorNode)
			{
				return *this;
			}

			Prev = this;
			Next = this;
			Data = linkVectorNode.Data;
		}

		~LinkVectorNode()
		{
		}

		friend std::ostream &operator<<(std::ostream &os, const LinkVectorNode &linkVectorNode)
		{
			os << linkVectorNode.Data;
			return os;
		}

#ifdef DEBUG_INFO
		std::ostream &PrintInfo(std::ostream &os) const
		{
			os << "{";
			os << " Prev: " << Prev << ", ";
			os << " Next: " << Next << ", ";
			os << " Data: " << Data;
			os << " }";

			return os;
		}
#endif
	};

private:
	LinkVectorNode *_Head;
	int _Count;

public:
	LinkVector();
	LinkVector(const LinkVector<T> &linkVector);
	LinkVector<T> &operator=(const LinkVector<T> &linkVector);
	~LinkVector();

	void Insert(int index, const T &item);
	void AppendFirst(const T &item);
	void AppendLast(const T &item);
	void Remove(int index);
	void RemoveFirst();
	void RemoveLast();
	void Clear();

	T First() const;
	T Last() const;
	T At(int index) const;
	bool IsEmpty() const;
	int Count() const;
	bool IsContains(const T item) const;

	T &operator[](int index);

	template <typename Type>
	friend std::ostream &operator<<(std::ostream &os, const LinkVector<Type> &linkVector)
	{
		os << "[ ";
		LinkVectorNode *p = linkVector._Head->Next;
		while (p != linkVector._Head)
		{
			os << *p << " ";
			p = p->Next;
		}
		os << "]";

		return os;
	}

#ifdef DEBUG_INFO
	std::ostream &PrintInfo(std::ostream &os) const;
#endif
};

template <typename T>
LinkVector<T>::LinkVector()
{
	_Head = new LinkVectorNode;
	_Head->Prev = _Head;
	_Head->Next = _Head;
	_Count = 0;
}

template <typename T>
LinkVector<T>::LinkVector(const LinkVector<T> &linkVector)
{
	LinkVectorNode *p = linkVector._Head->Next;
	_Head = new LinkVectorNode;
	LinkVectorNode *q = _Head;
	while (p != linkVector._Head)
	{
		q->Next = new LinkVectorNode();
		q->Next->Prev = q;
		q->Next->Data = p->Data;

		q = q->Next;
		p = p->Next;
	}
	_Head->Prev = q;
	_Count = linkVector._Count;
}

template <typename T>
LinkVector<T> &LinkVector<T>::operator=(const LinkVector<T> &linkVector)
{
	if (this == &linkVector)
	{
		return *this;
	}

	LinkVectorNode *p = linkVector._Head->Next;
	_Head = new LinkVectorNode;
	LinkVectorNode *q = _Head;
	while (p != linkVector._Head)
	{
		q->Next = new LinkVectorNode();
		q->Next->Prev = q;
		q->Next->Data = p->Data;

		q = q->Next;
		p = p->Next;
	}
	_Head->Prev = q;
	_Count = linkVector._Count;

	return *this;
}

template <typename T>
LinkVector<T>::~LinkVector()
{
	LinkVectorNode *p = _Head->Next;
	LinkVectorNode *q = nullptr;
	while (p != _Head)
	{
		q = p->Next;
		delete p;
		p = q;
	}
	delete _Head;
}

template <typename T>
void LinkVector<T>::Insert(int index, const T &item)
{
	LinkVectorNode *p = _Head;
	if (index >= 0)
	{
		for (int i = 0; i < index; i++)
		{
			p = p->Next;
		}
	}
	else
	{
		for (int i = 0; i > index; i--)
		{
			p = p->Prev;
		}
	}

	LinkVectorNode *newLinkVectorNode = new LinkVectorNode(item);
	newLinkVectorNode->Prev = p;
	newLinkVectorNode->Next = p->Next;
	p->Next->Prev = newLinkVectorNode;
	p->Next = newLinkVectorNode;

	_Count++;
}

template <typename T>
void LinkVector<T>::AppendFirst(const T &item)
{
	Insert(0, item);
}

template <typename T>
void LinkVector<T>::AppendLast(const T &item)
{
	Insert(_Count, item);
}

template <typename T>
void LinkVector<T>::Remove(int index)
{
	if (_Count <= 0)
	{
		throw std::logic_error("该向量为空向量，不可执行Remove()操作。");
	}

	LinkVectorNode *p = nullptr;
	if (index >= 0)
	{
		p = _Head->Next;
		for (int i = 0; i < index; i++)
		{
			p = p->Next;
		}
	}
	else
	{
		p = _Head;
		for (int i = 0; i > index; i--)
		{
			p = p->Prev;
		}
	}

	p->Prev->Next = p->Next;
	p->Next->Prev = p->Prev;
	delete p;

	_Count--;
}

template <typename T>
void LinkVector<T>::RemoveFirst()
{
	Remove(0);
}

template <typename T>
void LinkVector<T>::RemoveLast()
{
	Remove(-1);
}

template <typename T>
void LinkVector<T>::Clear()
{
	LinkVectorNode *p = _Head->Next;
	LinkVectorNode *q = nullptr;
	while (p != _Head)
	{
		q = p->Next;
		delete p;
		p = q;
	}

	_Head->Prev = _Head->Next;
}

template <typename T>
T LinkVector<T>::First() const
{
	if (_Count <= 0)
	{
		throw std::logic_error("该向量为空向量，不可执行First()操作。");
	}

	T result = _Head->Next->Data;
	return std::move(result);
}

template <typename T>
T LinkVector<T>::Last() const
{
	if (_Count <= 0)
	{
		throw std::logic_error("该向量为空向量，不可执行Last()操作。");
	}

	T result = _Head->Prev->Data;
	return std::move(result);
}

template <typename T>
T LinkVector<T>::At(int index) const
{
	if (_Count <= 0)
	{
		throw std::logic_error("该向量为空向量，不可执行At()操作。");
	}

	if (index >= _Count || index < _Count * -1)
	{
		throw std::out_of_range("参数index的有效范围是 [" + std::to_string(_Count * -1) + ", " + std::to_string(_Count - 1) + "]");
	}

	LinkVectorNode *p = nullptr;
	if (index >= 0)
	{
		p = _Head->Next;
		for (int i = 0; i < index; i++)
		{
			p = p->Next;
		}
	}
	else
	{
		p = _Head;
		for (int i = 0; i > index; i--)
		{
			p = p->Prev;
		}
	}

	T result = p->Data;
	return std::move(result);
}

template <typename T>
bool LinkVector<T>::IsEmpty() const
{
	return _Count == 0;
}

template <typename T>
int LinkVector<T>::Count() const
{
	return _Count;
}

template <typename T>
bool LinkVector<T>::IsContains(const T item) const
{
	LinkVectorNode *p = _Head->Next;
	while (p != _Head)
	{
		if(p->Data == item)
		{
			return true;
		}
		
		p = p->Next;
	}

	return false;
}

template <typename T>
T &LinkVector<T>::operator[](int index)
{
	if (_Count <= 0)
	{
		throw std::logic_error("该向量为空向量，不可执行At()操作。");
	}

	if (index >= _Count || index < _Count * -1)
	{
		throw std::out_of_range("参数index的有效范围是 [" + std::to_string(_Count * -1) + ", " + std::to_string(_Count - 1) + "]");
	}

	LinkVectorNode *p = nullptr;
	if (index >= 0)
	{
		p = _Head->Next;
		for (int i = 0; i < index; i++)
		{
			p = p->Next;
		}
	}
	else
	{
		p = _Head;
		for (int i = 0; i > index; i--)
		{
			p = p->Prev;
		}
	}

	T &result = p->Data;
	return result;
}

#ifdef DEBUG_INFO
template <typename T>
std::ostream &LinkVector<T>::PrintInfo(std::ostream &os) const
{
	os << "{";
	os << " _Head(" << _Head << "): ";
	_Head->PrintInfo(os);
	os << " -- [ ";
	LinkVectorNode *p = _Head->Next;
	while (p != _Head)
	{
		os << *p << " ";
		p = p->Next;
	}
	os << "]";
	os << ", _Count: " << _Count;
	os << " }";

	return os;
}
#endif
} // namespace hy

#endif