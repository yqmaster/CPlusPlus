#include "CustomString.hpp"
#include <iostream>

int main()
{
	auto str1 = CustomString("test1");
	auto str2 = CustomString("test2, test3");

	auto str3 = CustomString(str1);
	std::cout << str3 << std::endl;

	str1 = "test3";
	std::cout << str1 << std::endl;

	int len = str1.len();
	std::cout << len << std::endl;

	CustomString sub1 = str1.sub(1, 4);
	std::cout << sub1 << std::endl;

	str1.append("append");
	std::cout << str1 << std::endl;

	bool equal = str1 == str3;
	std::cout << equal << std::endl;

	int index = str1.find("es");
	std::cout << index << std::endl;

	CustomString* ret = str2.split(", ");
	std::cout << ret[0] << " -- " << ret[1] << std::endl;

	return 0;
}