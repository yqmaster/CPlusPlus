#include "SkipList.hpp"

SkipList::SkipList()
{
	this->Head = new SkipListNode(std::numeric_limits<int>::min(), MAX_LEVEL);
}

SkipList::~SkipList()
{
	SkipListNode* PreNode = this->Head;
	while (PreNode!= nullptr)
	{
		SkipListNode* DeleteNode = PreNode;
		PreNode = PreNode->Next[0];
		delete DeleteNode;
	}
}

void SkipList::Insert(int Element)
{
	SkipListNode* NewNode = new SkipListNode(Element, this->RandonLevel());
	for (int PresentLevel = 0; PresentLevel < NewNode->Level; ++PresentLevel)
	{
		SkipListNode* PreNode = this->Head;
		while (PreNode != nullptr)
		{
			SkipListNode* NextNode = PreNode->Next[PresentLevel];
			if (NextNode == nullptr)
			{
				PreNode->Next[PresentLevel] = NewNode;
				break;
			}
			if (PreNode->Value < Element && Element <= NextNode->Value)
			{
				NewNode->Next[PresentLevel] = NextNode;
				PreNode->Next[PresentLevel] = NewNode;
				break;
			}
			PreNode = NextNode;
		}
	}
}

bool SkipList::Find(int Element)
{
	SkipListNode* PreNode = this->Head;
	while (PreNode != nullptr)
	{
		if (PreNode->Value == Element)
		{
			return true;
		}
		PreNode = PreNode->Next[0];
	}
	return false;
}

bool SkipList::Remove(int Element)
{
	std::cout << "Remove Node = " << Element << "At Level = ";
	SkipListNode* DeleteNode = nullptr;

	for (int PresentLevel = 0; PresentLevel < MAX_LEVEL; ++PresentLevel)
	{
		SkipListNode* PreNode = this->Head;
		while (PreNode != nullptr)
		{
			SkipListNode* NextNode = PreNode->Next[PresentLevel];
			if (NextNode == nullptr)
			{
				break;
			}
			if (NextNode->Value == Element)
			{
				DeleteNode = NextNode;
				PreNode->Next[PresentLevel] = NextNode->Next[PresentLevel];
				std::cout << PresentLevel + 1 << ",";
				break;
			}
			PreNode = NextNode;
		}
	}

	std::cout << " Result = " << (DeleteNode != nullptr) << std::endl;
	if (DeleteNode != nullptr)
	{
		delete DeleteNode;
	}
	return DeleteNode != nullptr;
}

void SkipList::PrintList()
{
	for (int PresentLevel = 0; PresentLevel < MAX_LEVEL; ++PresentLevel)
	{
		SkipListNode* PreNode = this->Head;
		while (PreNode != nullptr)
		{
			SkipListNode* NextNode = PreNode->Next[PresentLevel];
			if (NextNode == nullptr)
			{
				break;
			}
			std::cout << NextNode->Value << ",";
			PreNode = NextNode;
		}
		std::cout << std::endl;
	}
}

int SkipList::RandonLevel()
{
	float Result = float(rand()) / RAND_MAX;
	int Level = 1;
	while (Result <= PROB && Level < MAX_LEVEL)
	{
		Level++;
		Result = float(rand()) / RAND_MAX;
	}
	return Level;
}
