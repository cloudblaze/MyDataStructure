#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>
#include "LinkVector.h"

namespace hy
{
	template<typename T>
	class Deque
	{
	private:
		LinkVector<T> _containor;
	
	public:
		Deque();
		Deque(const Deque<T> & queue);
		Deque<T> & operator=(const Deque<T> & queue);
		~Deque();

		void EnQueueAtRear(const T &item);
		T DeQueueAtFront();
		void EnQueueAtFront(const T &item);
		T DeQueueAtRear();

		bool IsEmpty() const;
		T Front() const;
		T Rear() const;
		bool IsContains(const T & item) const;

		template<typename Type>
		friend std::ostream & operator<<(std::ostream & os, const Deque<Type> & queue);
	};

	template<typename T>
	Deque<T>::Deque()
	{
		
	}

	template<typename T>
	Deque<T>::Deque(const Deque<T> & queue)
	{
		_containor = queue._containor;
	}

	template<typename T>
	Deque<T> & Deque<T>::operator=(const Deque<T> & queue)
	{
		if(this == &queue)
		{
			return *this;
		}

		_containor = queue._containor;
		return *this;
	}

	template<typename T>
	Deque<T>::~Deque()
	{

	}

	template<typename T>
	void Deque<T>::EnQueueAtRear(const T & item)
	{
		_containor.AppendLast(item);
	}

	template<typename T>
	T Deque<T>::DeQueueAtFront()
	{
		if(_containor.IsEmpty())
			throw std::logic_error("对空队列执行DeQueue操作");

		T result = _containor.First();
		_containor.RemoveFirst();
		return std::move(result);
	}

	template<typename T>
	void Deque<T>::EnQueueAtFront(const T & item)
	{
		_containor.AppendFirst(item);
	}

	template<typename T>
	T Deque<T>::DeQueueAtRear()
	{
		if(_containor.IsEmpty())
			throw std::logic_error("对空队列执行DeQueue操作");

		T result = _containor.Last();
		_containor.RemoveLast();
		return std::move(result);
	}

	template<typename T>
	bool Deque<T>::IsEmpty() const
	{
		return _containor.IsEmpty();
	}

	template<typename T>
	T Deque<T>::Front() const
	{
		return _containor.First();
	}

	template<typename T>
	T Deque<T>::Rear() const
	{
		return _containor.Last();
	}

	template<typename T>
	bool Deque<T>::IsContains(const T & item) const
	{
		return _containor.IsContains(item);
	}

	template<typename T>
	std::ostream & operator<<(std::ostream & os, const Deque<T> & queue)
	{
		os << queue._containor;
		return os;
	}
}

#endif