#include "CustomString.h"

CustomString::CustomString()
{
}

CustomString::~CustomString()
{
}

CustomString::CustomString(const char* ca) :_ca(ca) {
}

int CustomString::len()
{
	return sizeof(_ca);
}

CustomString CustomString::sub(int pos, int count)
{
	
	return 
}

