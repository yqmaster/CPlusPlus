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
	// Խ���򷵻ؿ�string
	if (pos > this->_len || pos <= 0 || count <= 0)
	{
		return CustomString("");
	}

	// �жϳ��ȣ�������Ӧ�Ŀռ�
	int length = count;
	if (pos + count - 1 >= this->_len)
	{
		length = this->_len - pos;
	}
	
	// ��ֵ
	char* str = new char[length];
	for (int i = 0; i < length; i++)
	{
		str[i] = this->_str[pos + i -1];
	}
	str[length] = '\0';

	return CustomString(str);
}

void CustomString::append(const char* str)
{
	// ���Ϊ�գ����½�
	if (this->_str == NULL) 
	{
		this->setNewCustomString(str);
		return;
	}

	// TODO �����Ϊ�գ��������
	int strLength = getCharLength(str);
	int length = strLength  + this->_len;
	char* temp = new char[length + 1];
	for (int i = 0; i < this->_len; i++)
	{
		temp[i] = this->_str[i];
	}
	for (int i = 0; i < strLength; i++)
	{
		temp[i + this->_len - 1] = str[i];
	}

	
}

void CustomString::append(const CustomString str)
{
	// ���Ϊ�գ����½�
	if (this->_str == NULL)
	{
		this->setNewCustomString(str);
		return;
	}
	// TODO �����Ϊ�գ��������


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