#pragma once

class CustomString
{
public:
	// 默认构造函数
	CustomString();
	// 析构函数
	~CustomString();
	// 普通构造函数
	CustomString(const char* str);
	// 复制构造函数
	CustomString(const CustomString& str);
	// 重载赋值运算符
	CustomString& operator = (const CustomString& str);
	// 获取长度
	int len();
	// 返回子串
	CustomString sub(int pos, int count);

private:
	char* _str;
	int _len;
	void setNewCustomString(const char* str);
	void setNewCustomString(const CustomString& str);
};
