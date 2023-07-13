#pragma once
#include <math.h>
#include <iostream>

template <typename T>
class RingBuffer
{
public:
	RingBuffer(int size = 0) : _size(size), _arg(nullptr), _readPos(0), _writePos(0) {};

	int Read(T*& arg, int length);
	void Write(T* arg, int length);

	void ShowBuffer();
	int Length();

private:
	void AutoExpand(int size);
	void AutoShrink();

	void SetNewSize(int newSize);
	void InitBuffer(int size);

private:
	T* _arg;
	int _size;
	int _readPos;
	int _writePos;
};


template<typename T>
inline void RingBuffer<T>::ShowBuffer()
{
	int length = Length();
	std::cout << "Buffer Size =  " << _size << " , ";
	std::cout << "Buffer Length =  " << length << " , ";
	std::cout << "Start Position = " << _readPos << " , ";
	std::cout << "End Position = " << _writePos << std::endl;
	std::cout << "Data = { ";
	for (size_t i = 0; i < length; i++)
	{
		std::cout << " " << _arg[(_readPos + i) % _size] << " ,";
	}
	std::cout << " }" << std::endl << std::endl;
}

template<typename T>
inline int RingBuffer<T>::Length()
{
	int length = _writePos - _readPos;
	return length >= 0 ? length : length + _size;
}

template<typename T>
inline int RingBuffer<T>::Read(T*& arg, int length)
{
	int _length = Length();
	int readLength = _length >= length ? length : _length;
	arg = new T[readLength];
	for (size_t i = 0; i < readLength; i++)
	{
		arg[i] = _arg[(_readPos + i) % _size];
	}
	_readPos = (_readPos + readLength) % _size;
	AutoShrink();
	return readLength;
}

template<typename T>
inline void RingBuffer<T>::Write(T* arg, int length)
{
	AutoExpand(length);
	for (size_t i = 0; i < length; i++)
	{
		_arg[(_writePos + i) % _size] = arg[i];
	}
	_writePos = (_writePos + length) % _size;
}

template<typename T>
inline void RingBuffer<T>::AutoExpand(int size)
{
	if (_arg == nullptr)
	{
		InitBuffer(size);
		return;
	}
	int newSize = Length() + size;
	if (newSize >= _size)
	{
		SetNewSize(newSize * 1.5);
	}
}

template<typename T>
inline void RingBuffer<T>::AutoShrink()
{
	if (Length() < _size / 4)
	{
		SetNewSize(_size / 2);
	}
}

template<typename T>
inline void RingBuffer<T>::SetNewSize(int newSize)
{
	T* arg = new T[newSize];
	int length = Length();
	for (size_t i = 0; i < length; i++)
	{
		arg[i] = _arg[(_readPos + i) % _size];
	}
	T* temp = _arg;
	_arg = arg;
	delete temp;

	arg = nullptr;
	temp = nullptr;
	_size = newSize;

	_readPos = 0;
	_writePos = length;
}

template<typename T>
inline void RingBuffer<T>::InitBuffer(int size)
{
	_size = 2 * size;
	_arg = new T[_size];
	_readPos = 0;
	_writePos = 0;
}
