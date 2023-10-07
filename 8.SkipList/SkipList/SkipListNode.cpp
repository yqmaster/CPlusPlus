#include "SkipListNode.hpp"

SkipListNode::SkipListNode(int InValue, int AtLevel) :Level(AtLevel), Value(InValue)
{
	std::cout << "Add ListNode = " << InValue << " At Level = " << AtLevel << std::endl;
	Next = new SkipListNode * [Level];
	for (int index = 0; index < Level; ++index)
	{
		Next[index] = nullptr;
	}
}

SkipListNode::~SkipListNode()
{
	for (int index = 0; index < this->Level; ++index)
	{
		Next[index] = nullptr;
	}
}
