#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>
#include "LinkVector.h"

namespace hy
{
	template<typename T>
	class Stack
	{
	private:
		LinkVector<T> _Containor;
	
	public:
		Stack();
		Stack(const Stack<T> & stack);
		Stack<T> & operator=(const Stack<T> & stack);
		~Stack();

		void Push(const T & item);
		T Pop();

		bool IsEmpty() const;
		T Top() const;

		template<typename Type>
		friend std::ostream & operator<<(std::ostream & os, const Stack<Type> & stack);
	};

	template<typename T>
	Stack<T>::Stack()
	{
		
	}

	template<typename T>
	Stack<T>::Stack(const Stack<T> & stack)
	{
		_Containor = stack->_Containor;
	}

	template<typename T>
	Stack<T> & Stack<T>::operator=(const Stack<T> & stack)
	{
		if(this == &stack)
		{
			return *this;
		}

		_Containor = stack->_Containor;
		return *this;
	}

	template<typename T>
	Stack<T>::~Stack()
	{

	}

	template<typename T>
	void Stack<T>::Push(const T & item)
	{
		_Containor.AppendLast(item);
	}

	template<typename T>
	T Stack<T>::Pop()
	{
		if(_Containor.IsEmpty())
			throw std::logic_error("对空栈执行Pop操作");
		
		T result = _Containor.Last();
		_Containor.RemoveLast();
		return std::move(result);
	}

	template<typename T>
	bool Stack<T>::IsEmpty() const
	{
		return _Containor.IsEmpty();
	}

	template<typename T>
	T Stack<T>::Top() const
	{
		T result = _Containor.Last();
		return std::move(result);
	}

	template<typename T>
	std::ostream & operator<<(std::ostream & os, const Stack<T> & stack)
	{
		os << stack._Containor;
		return os;
	}
}

#endif