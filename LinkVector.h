#ifndef LINK_VECTOR_H
#define LINK_VECTOR_H

#include <iostream>
#include <cstring>

namespace hy
{
	template<typename T>
	class LinkVectorNode
	{
	public:
		LinkVectorNode * _Prev;
		LinkVectorNode * _Next;
		T _Data;

		LinkVectorNode(const T & data = T());
		LinkVectorNode(const LinkVectorNode & linkVectorNode);
		LinkVectorNode<T> & operator=(const LinkVectorNode & linkVectorNode);
		~LinkVectorNode();

		template<typename Type>
		friend std::ostream & operator<<(std::ostream & os, const LinkVectorNode & linkVectorNode);

#ifdef DEBUG_INFO
		std::ostream & PrintInfo(std::ostream & os) const;
#endif
	};

	template<typename T>
	LinkVectorNode<T>::LinkVectorNode(const T & data)
	{
		_Prev = this;
		_Next = this;
		_Data = data;
	}

	template<typename T>
	LinkVectorNode<T>::LinkVectorNode(const LinkVectorNode<T> & linkVectorNode)
	{
		_Prev = this;
		_Next = this;
		_Data = linkVectorNode._Data;
	}

	template<typename T>
	LinkVectorNode<T> & LinkVectorNode<T>::operator=(const LinkVectorNode<T> & linkVectorNode)
	{
		if(this == &linkVectorNode)
		{
			return *this;
		}

		_Prev = this;
		_Next = this;
		_Data = linkVectorNode._Data;
	}

	template<typename T>
	LinkVectorNode<T>::~LinkVectorNode()
	{
		
	}

	template<typename T>
	std::ostream & operator<<(std::ostream & os, const LinkVectorNode<T> & linkVectorNode)
	{
		os << linkVectorNode._Data;
		return os;
	}

#ifdef DEBUG_INFO
	template<typename T>
	std::ostream & LinkVectorNode<T>::PrintInfo(std::ostream & os) const
	{
		os << "{";
		os << " _Prev: " << _Prev << ", ";
		os << " _Next: " << _Next << ", ";
		os << " _Data: " << _Data;
		os << " }";

		return os;
	}
#endif

	template<typename T>
	class LinkVector
	{
	private:
		LinkVectorNode<T> * _Head;
		int _Count;
	
	public:
		LinkVector();
		LinkVector(const LinkVector<T> & linkVector);
		LinkVector<T> & operator=(const LinkVector<T> & linkVector);
		~LinkVector();

		void Insert(int index, const T & item);
		void AppendFirst(const T & item);
		void AppendLast(const T & item);
		void Remove(int index);
		void RemoveFirst();
		void RemoveLast();
		void Clear();

		T First() const;
		T Last() const;
		T At(int index) const;
		bool IsEmpty() const;
		int Count() const;

		T & operator[](int index);

		template<typename Type>
		friend std::ostream & operator<<(std::ostream & os, const LinkVector<Type> & linkVector);

#ifdef DEBUG_INFO
		std::ostream & PrintInfo(std::ostream & os) const;
#endif
	};

	template<typename T>
	LinkVector<T>::LinkVector()
	{
		_Head = new LinkVectorNode<T>;
		_Head->_Prev = _Head;
		_Head->_Next = _Head;
		_Count = 0;
	}

	template<typename T>
	LinkVector<T>::LinkVector(const LinkVector<T> & linkVector)
	{
		LinkVectorNode<T> * p = linkVector._Head->_Next;
		_Head = new LinkVectorNode<T>;
		LinkVectorNode<T> * q = _Head;
		while(p != linkVector._Head)
		{
			q->_Next = new LinkVectorNode<T>();
			q->_Next->_Prev = q;
			q->_Next->_Data = p->_Data;
			
			q = q->_Next;
			p = p->_Next;
		}
		_Head->_Prev = q;
		_Count = linkVector._Count;
	}

	template<typename T>
	LinkVector<T> & LinkVector<T>::operator=(const LinkVector<T> & linkVector)
	{
		if(this == &linkVector)
		{
			return *this;
		}

		LinkVectorNode<T> * p = linkVector._Head->_Next;
		_Head = new LinkVectorNode<T>;
		LinkVectorNode<T> * q = _Head;
		while(p != linkVector._Head)
		{
			q->_Next = new LinkVectorNode<T>();
			q->_Next->_Prev = q;
			q->_Next->_Data = p->_Data;
			
			q = q->_Next;
			p = p->_Next;
		}
		_Head->_Prev = q;
		_Count = linkVector._Count;

		return *this;
	}

	template<typename T>
	LinkVector<T>::~LinkVector()
	{
		LinkVectorNode<T> * p = _Head->_Next;
		LinkVectorNode<T> * q = nullptr;
		while(p != _Head)
		{
			q = p->_Next;
			delete p;
			p = q;
		}
		delete _Head;
	}

	template<typename T>
	void LinkVector<T>::Insert(int index, const T & item)
	{
		LinkVectorNode<T> * p = _Head;
		if(index >= 0)
		{
			for(int i = 0; i < index; i++)
			{
				p = p->_Next;
			}
		}
		else
		{
			for(int i = 0; i > index; i--)
			{
				p = p->_Prev;
			}
		}

		LinkVectorNode<T> * newLinkVectorNode = new LinkVectorNode<T>(item);
		newLinkVectorNode->_Prev = p;
		newLinkVectorNode->_Next = p->_Next;
		p->_Next->_Prev = newLinkVectorNode;
		p->_Next = newLinkVectorNode;

		_Count++;
	}

	template<typename T>
	void LinkVector<T>::AppendFirst(const T & item)
	{
		Insert(0, item);
	}

	template<typename T>
	void LinkVector<T>::AppendLast(const T & item)
	{
		Insert(_Count, item);
	}

	template<typename T>
	void LinkVector<T>::Remove(int index)
	{
		if(_Count <= 0)
		{
			throw std::logic_error("该向量为空向量，不可执行Remove()操作。");
		}

		LinkVectorNode<T> * p = nullptr;
		if(index >= 0)
		{
			p = _Head->_Next;
			for(int i = 0; i < index; i++)
			{
				p = p->_Next;
			}
		}
		else
		{
			p = _Head;
			for(int i = 0; i > index; i--)
			{
				p = p->_Prev;
			}
		}

		p->_Prev->_Next = p->_Next;
		p->_Next->_Prev = p->_Prev;
		delete p;

		_Count--;
	}

	template<typename T>
	void LinkVector<T>::RemoveFirst()
	{
		Remove(0);
	}

	template<typename T>
	void LinkVector<T>::RemoveLast()
	{
		Remove(-1);
	}

	template<typename T>
	void LinkVector<T>::Clear()
	{
		LinkVectorNode<T> * p = _Head->_Next;
		LinkVectorNode<T> * q = nullptr;
		while(p != _Head)
		{
			q = p->_Next;
			delete p;
			p = q;
		}
		
		_Head->_Prev = _Head->_Next;
	}

	template<typename T>
	T LinkVector<T>::First() const
	{
		if(_Count <= 0)
		{
			throw std::logic_error("该向量为空向量，不可执行First()操作。");
		}

		T result = _Head->_Next->_Data;
		return std::move(result);
	}

	template<typename T>
	T LinkVector<T>::Last() const
	{
		if(_Count <= 0)
		{
			throw std::logic_error("该向量为空向量，不可执行Last()操作。");
		}

		T result = _Head->_Prev->_Data;
		return std::move(result);
	}

	template<typename T>
	T LinkVector<T>::At(int index) const
	{
		if(_Count <= 0)
		{
			throw std::logic_error("该向量为空向量，不可执行At()操作。");
		}

		if(index >= _Count || index < _Count * -1)
		{
			throw std::out_of_range("参数index的有效范围是 [" + std::to_string(_Count * -1) + ", " + std::to_string(_Count - 1) + "]");
		}

		LinkVectorNode<T> * p = nullptr;
		if(index >= 0)
		{
			p = _Head->_Next;
			for(int i = 0; i < index; i++)
			{
				p = p->_Next;
			}
		}
		else
		{
			p = _Head;
			for(int i = 0; i > index; i--)
			{
				p = p->_Prev;
			}
		}

		T result = p->_Data;
		return std::move(result);
	}

	template<typename T>
	bool LinkVector<T>::IsEmpty() const
	{
		return _Count == 0;
	}

	template<typename T>
	int LinkVector<T>::Count() const
	{
		return _Count;
	}

	template<typename T>
	T & LinkVector<T>::operator[](int index)
	{
		if(_Count <= 0)
		{
			throw std::logic_error("该向量为空向量，不可执行At()操作。");
		}

		if(index >= _Count || index < _Count * -1)
		{
			throw std::out_of_range("参数index的有效范围是 [" + std::to_string(_Count * -1) + ", " + std::to_string(_Count - 1) + "]");
		}

		LinkVectorNode<T> * p = nullptr;
		if(index >= 0)
		{
			p = _Head->_Next;
			for(int i = 0; i < index; i++)
			{
				p = p->_Next;
			}
		}
		else
		{
			p = _Head;
			for(int i = 0; i > index; i--)
			{
				p = p->_Prev;
			}
		}

		T & result = p->_Data;
		return result;
	}

	template<typename T>
	std::ostream & operator<<(std::ostream & os, const LinkVector<T> & linkVector)
	{
		os << "[ ";
		LinkVectorNode<T> * p = linkVector._Head->_Next;
		while(p != linkVector._Head)
		{
			os << *p << " ";
			p = p->_Next;
		}
		os << "]";

		return os;
	}

#ifdef DEBUG_INFO
		template<typename T>
		std::ostream & LinkVector<T>::PrintInfo(std::ostream & os) const
		{
			os << "{";
			os << " _Head(" << _Head <<"): ";
			_Head->PrintInfo(os);
			os << " -- [ ";
			LinkVectorNode<T> * p = _Head->_Next;
			while(p != _Head)
			{
				os << *p << " ";
				p = p->_Next;
			}
			os << "]";
			os << ", _Count: " << _Count;
			os << " }";

			return os;
		}
#endif
}

#endif