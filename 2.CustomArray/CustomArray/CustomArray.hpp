#pragma once
#include <ostream>

#ifndef _CUSTOM_ARRAY_H
#define _CUSTOM_ARRAY_H

template <typename T>
class CustomArray {
public:
	CustomArray() : _size(0), _maxSize(0), _arr(nullptr) {};

	friend std::ostream& operator<< (std::ostream& out, CustomArray<T>& val)
	{
		out << "[";
		for (size_t i = 0; i < val._size; i++)
		{
			out << " " << val._arr[i] << " ";
		}
		out << "]";
		return out;

	}

	void reserve(int size);
	void push(T val);
	int findIndex(T val);
	void insert(int index, T val);
	void remove(int index);
	void pop();
	void clear();

private:
	void _expand();

	T* _arr;
	int _size;
	int _maxSize;
};

template <typename T>
inline void CustomArray<T>::_expand()
{
	if (_size == _maxSize)
	{
		_maxSize = _maxSize ? _maxSize << 1 : 2;
	}
	T* temp = new T[_maxSize];
	// 拷贝
	if (_arr)
	{
		for (size_t i = 0; i < _size; i++)
		{
			temp[i] = _arr[i];
		}
		delete _arr;
	}
	_arr = temp;
}

template <typename T>
inline void CustomArray<T>::reserve(int size)
{
	// 已经初始化了或者越界了就返回
	if (_arr || size <= 0)
	{
		return;
	}
	_arr = new T[size];
	_maxSize = size;
}

template <typename T>
inline void CustomArray<T>::push(T val)
{
	if (_size == _maxSize || !_arr)
	{
		_expand();
	}

	_arr[_size] = val;
	_size++;
}

template<typename T>
inline int CustomArray<T>::findIndex(T val)
{
	for (size_t i = 0; i < _size; i++)
	{
		if (_arr[i] == val)
		{
			return i + 1;
		}
	}
}

template <typename T>
inline void CustomArray<T>::insert(int index, T val)
{
	// 如果插入的位置大于数组大小，则添加至末尾
	if (index > _size)
	{
		push(val);
		return;
	}
	if (_size == _maxSize)
	{
		_expand();
	}
	for (size_t i = _size; i >= index; i--)
	{
		_arr[i] = _arr[i - 1];
	}
	_arr[index - 1] = val;
	_size++;
}


template <typename T>
inline void CustomArray<T>::remove(int index)
{
	// 如果删除的位置越界，则添加返回
	if (index >= _size || index < 0)
	{
		return;
	}
	for (size_t i = index; i < _size; i++)
	{
		_arr[i - 1] = _arr[i];
	}
	_size--;
}

template<typename T>
inline void CustomArray<T>::pop()
{
	remove(_size);
}

template<typename T>
inline void CustomArray<T>::clear()
{
	delete _arr;
	_size = 0;
}
#endif 

