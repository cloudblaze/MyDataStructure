#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
#include "LinkVector.h"

namespace hy
{
	template<typename T>
	class Queue
	{
	private:
		LinkVector<T> _containor;
	
	public:
		Queue();
		Queue(const Queue<T> & queue);
		Queue<T> & operator=(const Queue<T> & queue);
		~Queue();

		void EnQueue(const T & item);
		T DeQueue();

		bool IsEmpty() const;
		T Front() const;
		T Rear() const;

		template<typename Type>
		friend std::ostream & operator<<(std::ostream & os, const Queue<Type> & queue);
	};

	template<typename T>
	Queue<T>::Queue()
	{
		
	}

	template<typename T>
	Queue<T>::Queue(const Queue<T> & queue)
	{
		_containor = queue._containor;
	}

	template<typename T>
	Queue<T> & Queue<T>::operator=(const Queue<T> & queue)
	{
		if(this == &queue)
		{
			return *this;
		}

		_containor = queue._containor;
		return *this;
	}

	template<typename T>
	Queue<T>::~Queue()
	{

	}

	template<typename T>
	void Queue<T>::EnQueue(const T & item)
	{
		_containor.AppendLast(item);
	}

	template<typename T>
	T Queue<T>::DeQueue()
	{
		if(_containor.IsEmpty())
			throw std::logic_error("对空队列执行DeQueue操作");

		T result = _containor.First();
		_containor.RemoveFirst();
		return std::move(result);
	}

	template<typename T>
	bool Queue<T>::IsEmpty() const
	{
		return _containor.IsEmpty();
	}

	template<typename T>
	T Queue<T>::Front() const
	{
		return _containor.First();
	}

	template<typename T>
	T Queue<T>::Rear() const
	{
		return _containor.Last();
	}

	template<typename T>
	std::ostream & operator<<(std::ostream & os, const Queue<T> & queue)
	{
		os << queue._containor;
		return os;
	}
}

#endif