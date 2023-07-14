#include <iostream>
#include "CustomList.hpp"

int main()
{
	auto list1 = CustomList<int>();

	list1.push(1);
	std::cout << list1 << std::endl;

	list1.push(2);
	std::cout << list1 << std::endl;

	list1.insert(2, 3);
	std::cout << list1 << std::endl;

	auto ret = list1.find(2);
	std::cout << ret << std::endl;

	list1.remove(2);
	std::cout << list1 << std::endl;

	list1.popAll();
	std::cout << list1 << std::endl;

	return 0;
}


