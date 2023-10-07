#pragma once
#include "SkipListNode.hpp"

const int MAX_LEVEL = 5;
const float PROB = 0.5;

class SkipList
{
public:
	SkipList();
	~SkipList();

	void Insert(int Element);
	bool Find(int Element);
	bool Remove(int Element);
public:
	void PrintList();
private:
	int RandonLevel();
private:
	SkipListNode* Head;
};