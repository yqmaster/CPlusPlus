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
	// Խ���򷵻ؿ�string
	if (pos > this->_len || pos <= 0 || count <= 0)
	{
		return CustomString("");
	}

	// �жϳ��ȣ�������Ӧ�Ŀռ�
	int length = count;
	if (pos + count - 1 >= this->_len)
	{
		length = this->_len - pos + 1;
	}

	// ��ֵ
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
	// ���Ϊ�գ����½�
	if (this->_str == NULL)
	{
		this->setNewCustomString(str);
		return;
	}

	// �����Ϊ�գ��������
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
	// ���Ϊ�գ����½�
	if (this->_str == NULL)
	{
		this->setNewCustomString(str);
		return;
	}
	//�����Ϊ�գ��������
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
	// ����Ƚϵ����Լ�ֱ�ӷ���
	if (this == &str)
	{
		return true;
	}
	// �ȱȽϳ���
	if (this->_len != str._len)
	{
		return false;
	}
	// һ���ַ�һ���ַ��ıȽ�
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

	// ��ѭ��
	for (size_t i = 0; i < this->_len - length; i++)
	{
		// ��ѭ��
		for (size_t j = 0; j < length; j++)
		{
			// �ж������������Ϊ���һ��ʱ�����ؽ��
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
	// ��ѭ��
	for (size_t i = 0; i < this->_len - length; i++)
	{
		// ��ѭ��
		for (size_t j = 0; j < length; j++)
		{
			// �ж������������Ϊ���һ��
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
	// �������Ϊ�գ��򰴿�������
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
	// �������Ϊ�գ��򰴿�������
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


std::ostream& operator<<(std::ostream& output, const CustomString& str)
{
	output << str._str;
	return output;
}
