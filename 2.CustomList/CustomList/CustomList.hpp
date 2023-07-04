#pragma once
#include <iostream>

#ifndef  _CUSTOM_LIST_H
#define _CUSTOM_LIST_H

template <typename T>
class CustomNode
{
public:
	CustomNode() = delete;
	CustomNode(T var) :pre(nullptr), next(nullptr), var(var) {};

	friend std::ostream& operator <<(std::ostream& out, const CustomNode<T>& var)
	{
		out << var.var;
		return out;
	}

	CustomNode* pre;
	CustomNode* next;
	T var;
};

template <typename T>
class CustomList
{
public:
	CustomList() :_first(nullptr), _last(nullptr), _size(0) {};

	friend std::ostream& operator <<(std::ostream& out, const CustomList<T>& var)
	{
		CustomNode<T>* temp = var._first;
		out << "[";
		while (temp)
		{
			out << " " << *temp << " ";
			temp = temp->next;
		}
		out << "]";
		return out;
	}

	void push(T val);
	void insert(int index, T var);
	int find(T var);
	void remove(T var);
	void popAll();

private:
	CustomNode<T>* _first;
	CustomNode<T>* _last;
	size_t _size;
};

template <typename T>
inline void CustomList<T>::push(T var)
{
	CustomNode<T>* temp = new CustomNode<T>(var);
	// 如果最后一个存在，则添加至末尾
	if (_last)
	{
		temp->pre = _last;
		_last->next = temp;
		_last = temp;
	}
	// 如果最后一个不存在，就直接加到这里面
	else
	{
		_first = temp;
		_last = temp;
	}
	_size++;
}

template<typename T>
inline void CustomList<T>::insert(int index, T var)
{
	// 如果越界则返回
	if (index < 0 || index >= _size + 2)
	{
		return;
	}
	// 如果为空，则加入第一个
	if (_size == 0)
	{
		push(var);
	}
	CustomNode<T>* temp = _first;
	CustomNode<T>* node = new CustomNode<T>(var);
	for (size_t i = 1; i < index - 1; i++)
	{
		if (temp->next)
		{
			break;
		}
		temp = temp->next;
	}

	node->next = temp->next;
	node->pre = temp;
	temp->next = node;
	temp = node->next;
	if (temp)
	{
		temp->pre = node;
	}
}

template <typename T>
inline int CustomList<T>::find(T var)
{
	// 如果为空则返回
	if (_size == 0)
	{
		return -1;
	}

	CustomNode<T>* temp = _first;
	for (size_t i = 1; i <= _size; i++)
	{
		temp = temp->next;
		if (temp == nullptr)
		{
			return -1;
		}
		if (temp->var == var)
		{
			return i + 1;
		}
	}
	return -1;
}

template<typename T>
inline void CustomList<T>::remove(T var)
{
	int index = find(var);
	if (index == -1)
	{
		return;
	}
	CustomNode<T>* temp = _first;
	for (size_t i = 1; i < index; i++)
	{
		temp = temp->next;
		if (temp == nullptr)
		{
			return;
		}
	}
	CustomNode<T>* pre = temp->pre;
	CustomNode<T>* next = temp->next;

	if (next)
	{
		next->pre = pre;
	}
	else
	{
		_last = pre;
	}

	if (pre)
	{
		pre->next = next;
	}
	else
	{
		_first = next;
	}
	_size--;
	delete temp;
}

template<typename T>
inline void CustomList<T>::popAll()
{
	CustomNode<T>* temp = _first;
	while (temp)
	{
		CustomNode<T>* toDelete = temp;
		temp = temp->next;
		delete toDelete;
	}
	_first = nullptr;
	_last = nullptr;
	_size = 0;
}
#endif // ! _CUSTOM_LIST_H
