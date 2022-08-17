#include "CustomString.h"
#include "cassert"
#include "Misc.hpp"

CustomString::CustomString()
{
	this->_str = NULL;
	this->_len = 0;
}

CustomString::~CustomString()
{
	this->clearCustomString();
}

CustomString::CustomString(const char* str)
{
	this->setNewCustomString(str);
}

CustomString::CustomString(const CustomString& str)
{
	this->setNewCustomString(str);
}

CustomString& CustomString::operator=(const CustomString& str)
{
	if (this == &str)
	{
		return *this;
	}

	this->clearCustomString();
	this->setNewCustomString(str);
	return *this;
}

int CustomString::len()
{
	return this->_len;
}

CustomString CustomString::sub(int pos, int count)
{
	// �жϳ��ȣ�������Ӧ�Ŀռ�
	if (pos >= this->_len || pos <= 0 || count <= 0)
	{
		return CustomString();
	}

	int length = count;
	if (pos + count >= this->_len) {

	}

	while (1)
	{
	}

	char* str = new char(length);

	return CustomString(str);
}

void CustomString::setNewCustomString(const char* str)
{
	// �������Ϊ�գ��򰴿�������
	if (str == NULL)
	{
		this->_len = 0;
		this->_str = NULL;
		return;
	}

	this->_len = getCharLength(str);
	this->_str = new char[this->_len + 1];
	copyChar(this->_str, str);
}

void CustomString::setNewCustomString(const CustomString& str)
{
	// �������Ϊ�գ��򰴿�������
	if (str._str == NULL)
	{
		this->_len = 0;
		this->_str = NULL;
		return;
	}
	this->_len = str._len;
	this->_str = new char[this->_len + 1];
	copyChar(this->_str, str._str);
}

void CustomString::clearCustomString()
{
	// ����������
	this->_len = 0;

	// ����Ѿ�Ϊ���˾�ֱ�ӷ���
	if (this->_str == NULL)
	{
		return;
	}

	// ����ڴ�
	delete this->_str;
	this->_len = NULL;
}