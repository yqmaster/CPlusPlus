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
	// 越界则返回空string
	if (pos > this->_len || pos <= 0 || count <= 0)
	{
		return CustomString("");
	}

	// 判断长度，申请相应的空间
	int length = count;
	if (pos + count - 1 >= this->_len)
	{
		length = this->_len - pos;
	}
	
	// 赋值
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
	// 如果为空，则新建
	if (this->_str == NULL) 
	{
		this->setNewCustomString(str);
		return;
	}

	// TODO 如果不为空，则往后加
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
	// 如果为空，则新建
	if (this->_str == NULL)
	{
		this->setNewCustomString(str);
		return;
	}
	// TODO 如果不为空，则往后加


}

void CustomString::setNewCustomString(const char* str)
{
	// 如果输入为空，则按空来处理
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
	// 如果输入为空，则按空来处理
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
	// 长度先清零
	this->_len = 0;

	// 如果已经为空了就直接返回
	if (this->_str == NULL)
	{
		return;
	}

	// 清空内存
	delete this->_str;
	this->_len = NULL;
}