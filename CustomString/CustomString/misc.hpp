#include <cassert>
#include <iostream>

int getCharLength(const char* str)
{
	// ����Ĳ���Ϊ��
	assert(str != NULL);

	// ����ָ�������㳤��
	char* p = (char*)str; // ǿת
	while (*p != '\0')
	{
		p++;
	}

	return p - str;
}

void copyChar(char* str1, const char* str2)
{
	// ����Ĳ���Ϊ��
	assert(str1 != NULL);
	assert(str2 != NULL);

	// ��2��ֵ��1

	while (*str2 != '\0')
	{
		// std::cout << *str1 << "<------ " << *str2 << std::endl;
		*str1++ = *str2++;
	}
	*str1 = '\0';
}