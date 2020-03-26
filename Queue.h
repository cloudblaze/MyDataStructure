#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <iostream>
#include <stdexcept>

namespace hy
{
	template<typename T>
	class Queue
	{
	private:
		std::vector _Containor;
		int _Rear;
	
	public:
		Queue(int capacity = 32);

		bool IsEmpty() const;
		T Front() const;
		T Rear() const;
		void Push(const T & item);
		void Pop();

		template<typename Type>
		friend std::ostream & operator<<(std::ostream & os, Queue<Type> queue);
	};

	template<typename T>
	Queue<T>::Queue(int capacity)
	{
		if(capacity <= 0)
			throw std::invalid_argument("队列空间初始大小设置不允许小于等于0");

		_Containor.resize(capacity);
		_Rear = -1;
	}

	template<typename T>
	bool Queue<T>::IsEmpty() const
	{
		return _Rear == -1;
	}

	template<typename T>
	T Queue<T>::Front() const
	{
		return _Containor[0];
	}

	template<typename T>
	T Queue<T>::Rear() const
	{
		return _Containor[_Rear];
	}

	template<typename T>
	void Queue<T>::Push(const T & item)
	{
		_Containor[++_Rear];
	}

	template<typename T>
	void Queue<T>::Pop()
	{
		
	}
}

#endif