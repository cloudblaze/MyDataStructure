#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <iostream>

namespace hy
{
	template<typename T>
	class Stack
	{
	private:
		std::vector<T> _Containor;
		int _Capacity;
		int _Top;
	
	public:
		Stack(int capacity = 32);
		bool IsEmpty() const;
		void Push(const T & item);
		void Pop();
		T & Top() const;

		template<typename Type>
		friend std::ostream & operator<<(std::ostream & os, const Stack<Type> & stack);
	};

	template<typename T>
	Stack<T>::Stack(int capacity)
	{
		_Containor.resize(capacity);
		_Capacity = capacity;
		_Top = -1;
	}

	template<typename T>
	bool Stack<T>::IsEmpty() const
	{
		return _Top == -1;
	}

	template<typename T>
	void Stack<T>::Push(const T & item)
	{
		_Containor[++_Top] = item;
	}

	template<typename T>
	void Stack<T>::Pop()
	{
		if(_Top < 0)
			throw std::logic_error("再一次对栈执行Pop操作");
		
		_Top--;
	}

	template<typename T>
	T & Stack<T>::Top() const
	{
		return _Containor[_Top];
	}

	template<typename T>
	std::ostream & operator<<(std::ostream & os, const Stack<T> & stack)
	{
		os << "[ ";
		for(int i = 0; i <= stack._Top; i++)
		{
			os << stack._Containor[i] << " ";
		}
		os << "]";

		return os;
	}
}

#endif