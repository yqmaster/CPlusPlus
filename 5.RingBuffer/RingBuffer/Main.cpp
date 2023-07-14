#include <iostream>
#include "ringbuffer.hpp"

template<typename T>
void ReadArr(const T* arg, int length)
{
	std::cout << "Read Finish, Result = {";
	for (size_t i = 0; i < length; i++)
	{
		std::cout << " " << arg[i] << " ,";
	}
	std::cout << "}" << std::endl;
}

int main()
{
	RingBuffer<int> test;
	int a[8] = { 1,2,3,4,5,6,7,8 };
	int b[4] = { 9,10,11,12 };
	int c[4] = { 13,14,15,16 };

	test.Write(a, 8);
	test.ShowBuffer();

	test.Write(b, 4);
	test.ShowBuffer();

	test.Write(c, 4);
	test.ShowBuffer();

	int* a1 = nullptr;
	int length1 = test.Read(a1, 2);
	ReadArr(a1, length1);
	test.ShowBuffer();

	int* a2 = nullptr;
	int length2 = test.Read(a2, 4);
	ReadArr(a2, length2);
	test.ShowBuffer();

	test.Write(a, 8);
	test.ShowBuffer();

	test.Write(a, 3);
	test.ShowBuffer();
}

