#pragma once
#include <ostream>

#ifndef _CUSTOM_STRING_H
#define _CUSTOM_STRING_H

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
	// 后面添加
	void append(const char* str);
	void append(const CustomString str);
	// 重载关系运算符
	bool operator == (const CustomString& str);
	// 查找某串字符串的位置
	int find(const char* str);


	// 重载输出运算符
	friend std::ostream& operator<<(std::ostream& output, const CustomString& str);

private:
	char* _str;
	int _len;
	void setNewCustomString(const char* str);
	void setNewCustomString(const CustomString& str);
	void clearCustomString();
};

#endif 