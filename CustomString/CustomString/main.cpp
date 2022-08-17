#include "CustomString.h"

int main() {
	auto str1 = CustomString("test1");
	auto str2 = CustomString("test2, test3");
	auto str3 = CustomString(str1);
	str1 = "test3";
	int len = str1.len();
	CustomString sub1 = str1.sub(1, 2);

	//str1.append("append");
	//bool equal = str1 == str2;
	//int index = str1.find(""es"");
	//CustomString* ret = str2.split("", ""); "
	return 0;
}