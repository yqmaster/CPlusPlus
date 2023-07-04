#include "CustomArray.hpp"
#include <iostream>

int main()
{
	auto arr = CustomArray<int>();
	arr.reserve(4);

	arr.push(1);
	std::cout << arr << std::endl;

	arr.push(2);
	std::cout << arr << std::endl;

	int index = arr.findIndex(1);
	std::cout << index << std::endl;

	arr.insert(1, 3);
	std::cout << arr << std::endl;

	arr.remove(1);
	std::cout << arr << std::endl;

	arr.pop();
	std::cout << arr << std::endl;

	arr.clear();
	std::cout << arr << std::endl;

	return 0;
}
