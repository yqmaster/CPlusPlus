#include <iostream>
#include "SkipList.hpp"

int main()
{
	SkipList List;
	List.Insert(1);
	List.Insert(9);
	List.Insert(5);
	List.Insert(2);
	List.Insert(8);
	List.Insert(4);
	List.Insert(6);
	List.Insert(7);
	List.Insert(3);

	List.PrintList();

	std::cout << "Find Element Result = " << List.Find(8) << std::endl;
	std::cout << "Find Element Result = " << List.Find(0) << std::endl;
	std::cout << "Find Element Result = " << List.Find(10) << std::endl;

	List.Remove(6);
	List.Remove(9);

	List.PrintList();
}
