#pragma once

class CustomString
{
public:
	CustomString();
	~CustomString();
	CustomString(const char* ca);
	int len();
	CustomString sub(int pos,int count);

private:
	const char* _ca;

};

