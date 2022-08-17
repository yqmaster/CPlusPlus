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
	// 判断长度，申请相应的空间
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