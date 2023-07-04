#include "CustomString.hpp"
#include "Misc.hpp"
#include "vector"

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
		length = this->_len - pos + 1;
	}

	// 赋值
	char* str = new char[length];
	for (size_t i = 0; i < length; i++)
	{
		str[i] = this->_str[pos + i - 1];
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

	// 如果不为空，则往后加
	int strLength = GlobalFunction::getCharLength(str);
	int newLength = strLength + this->_len;
	char* temp = new char[strLength + this->_len + 1];
	for (size_t i = 0; i < this->_len; i++)
	{
		temp[i] = this->_str[i];
	}
	for (size_t i = 0; i < strLength; i++)
	{
		temp[i + this->_len] = str[i];
	}
	temp[newLength] = '\0';

	delete this->_str;
	this->_str = temp;
	this->_len = newLength;
}

void CustomString::append(const CustomString str)
{
	// 如果为空，则新建
	if (this->_str == NULL)
	{
		this->setNewCustomString(str);
		return;
	}
	//如果不为空，则往后加
	int strLength = str._len;
	int newLength = strLength + this->_len;
	char* temp = new char[strLength + this->_len + 1];
	for (size_t i = 0; i < this->_len; i++)
	{
		temp[i] = this->_str[i];
	}
	for (size_t i = 0; i < strLength; i++)
	{
		temp[i + this->_len] = str._str[i];
	}

	delete this->_str;
	this->_str = temp;
	this->_len = newLength;
}

bool CustomString::operator==(const CustomString& str)
{
	// 如果比较的是自己直接返回
	if (this == &str)
	{
		return true;
	}
	// 先比较长度
	if (this->_len != str._len)
	{
		return false;
	}
	// 一个字符一个字符的比较
	for (size_t i = 0; i < this->_len; i++)
	{
		if (this->_str[i] != str._str[i])
		{
			return false;
		}
	}
	return true;
}

int CustomString::find(const char* str)
{
	int length = GlobalFunction::getCharLength(str);
	if (length > this->_len)
	{
		return -1;
	}

	// 外循环
	for (size_t i = 0; i < this->_len - length; i++)
	{
		// 内循环
		for (size_t j = 0; j < length; j++)
		{
			// 判断条件：相等且为最后一个时，返回结果
			if (this->_str[i + j] != str[j])
			{
				break;
			}
			if (j == length - 1)
			{
				return i + 1;
			}
		}
	}
	return -1;
}

CustomString* CustomString::split(const char* str)
{
	int length = GlobalFunction::getCharLength(str);
	if (length > this->_len)
	{
		return { new CustomString(str) };
	}

	std::vector<int> temp;
	// 外循环
	for (size_t i = 0; i < this->_len - length; i++)
	{
		// 内循环
		for (size_t j = 0; j < length; j++)
		{
			// 判断条件：相等且为最后一个
			if (this->_str[i + j] != str[j])
			{
				break;
			}
			if (j == length - 1)
			{
				temp.push_back(i + 1);
				break;
			}
		}
	}

	if (temp.size() <= 0)
	{
		return { new CustomString(str) };
	}

	CustomString* result = new CustomString[temp.size() + 1];
	int a = 0;

	for (int i = 0; i <= temp.size(); i++)
	{
		if (i == temp.size())
		{
			result[i] = sub(a + 2, this->_len - a);
		}
		else
		{
			int index = temp[i];
			result[i] = sub(a + 1, index - a - 1);
			a = index;
		}
	}
	return result;
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

	this->_len = GlobalFunction::getCharLength(str);
	this->_str = new char[this->_len + 1];
	GlobalFunction::copyChar(this->_str, str);
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
	GlobalFunction::copyChar(this->_str, str._str);
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


std::ostream& operator<<(std::ostream& output, const CustomString& str)
{
	output << str._str;
	return output;
}
