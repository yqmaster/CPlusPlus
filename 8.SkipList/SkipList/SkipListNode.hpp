#include <iostream>

class SkipListNode
{
public:
	SkipListNode(int InValue, int AtLevel);
	~SkipListNode();

public:
	int Value;
	int Level;
	SkipListNode** Next;
};