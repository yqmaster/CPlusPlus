#pragma once

class CustomString
{
public:
	// Ĭ�Ϲ��캯��
	CustomString();
	// ��������
	~CustomString();

	// ��ͨ���캯��
	CustomString(const char* str);
	// ���ƹ��캯��
	CustomString(const CustomString& str);
	// ���ظ�ֵ�����
	CustomString& operator = (const CustomString& str);
	// ��ȡ����
	int len();
	// �����Ӵ�
	CustomString sub(int pos, int count);
	// �������
	void append(const char* str);
	void append(const CustomString str);

private:
	char* _str;
	int _len;
	void setNewCustomString(const char* str);
	void setNewCustomString(const CustomString& str);
	void clearCustomString();
};
