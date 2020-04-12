#ifndef VECTOR_H
#define VECTOR_H

#include <cstring>
#include <iostream>
#include <stdexcept>

namespace hy
{
	template<typename T>
	class Vector
	{
	private:
		T * _data;
		
		int _Size;
	
	public:
		Vector(int size = 32);
		Vector(const Vector & vector);
		Vector & operator=(const Vector & vector);
		~Vector();

		void Resize(int size);

		int Size() const;
		T & operator[](int index);

		template<typename Type>
		friend std::ostream & operator<<(std::ostream & os, const Vector<Type> vector);

#ifdef DEBUG_INFO
		std::ostream & PrintInfo(std::ostream & os) const;
#endif
	};

	template<typename T>
	Vector<T>::Vector(int size)
	{
		if(size <= 0)
		{
			throw std::invalid_argument("向量表空间大小必须大于0。");
		}
		
		_Size = size;
		_data = new T[_Size];
	}

	template<typename T>
	Vector<T>::Vector(const Vector & vector)
	{
		_Size = vector._Size;
		_data = new T[_Size];
		memcpy(_data, vector._data, sizeof(T) * _Size);
	}

	template<typename T>
	Vector<T> & Vector<T>::operator=(const Vector<T> & vector)
	{
		if(this == &vector)
		{
			return *this;
		}

		this->_Size = vector._Size;
		this->_data = new T[_Size];
		memcpy(this->_data, vector._data, sizeof(T) * this->_Size);

		return *this;
	}

	template<typename T>
	Vector<T>::~Vector()
	{
		delete [] _data;
	}

	template<typename T>
	void Vector<T>::Resize(int size)
	{
		T * newData = new T[size];
		memcpy(newData, _data, sizeof(T) * size);
		delete [] _data;
		_data = newData;
		_Size = size;
	}

	template<typename T>
	int Vector<T>::Size() const
	{
		return _Size;
	}

	template<typename T>
	T & Vector<T>::operator[](int index)
	{
		return _data[index];
	}

	template<typename Type>
	std::ostream & operator<<(std::ostream & os, const Vector<Type> vector)
	{
		os << "[ ";
		for(int i = 0; i < vector._Size; i++)
		{
			os << vector._data[i] << " ";
		}
		os << "]";

		return os;
	}

#ifdef DEBUG_INFO
	template<typename T>
	std::ostream & Vector<T>::PrintInfo(std::ostream & os) const
	{
		os << "{";
		os << " _Size: " << _Size << ", ";
		os << " _data: [ ";
		for(int i = 0; i < _Size; i++)
		{
			os << _data[i] << " ";
		}
		os << "]" << " ";
		os << "}";

		return os;
	}
#endif
}

#endif