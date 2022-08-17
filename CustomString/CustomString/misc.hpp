#include <cassert>
#include <iostream>

int getCharLength(const char* str)
{
	// 传入的不能为空
	assert(str != NULL);

	// 利用指针来计算长度
	char* p = (char*)str; // 强转
	while (*p != '\0')
	{
		p++;
	}

	return p - str;
}

void copyChar(char* str1, const char* str2)
{
	// 传入的不能为空
	assert(str1 != NULL);
	assert(str2 != NULL);

	// 把2赋值到1

	while (*str2 != '\0')
	{
		// std::cout << *str1 << "<------ " << *str2 << std::endl;
		*str1++ = *str2++;
	}
	*str1 = '\0';
}