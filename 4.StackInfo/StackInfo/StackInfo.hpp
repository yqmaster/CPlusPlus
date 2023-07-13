#pragma once
#include <vector>

class BaseData {};

template <typename T >
class Data :public BaseData
{
public:
	Data(T& self) :_self(self) {};

	T Get() { return _self; }

private:
	T _self;
};

class StackInfo
{
public:
	template <typename T >
	void push(T var);

	template <typename T >
	void pop(T& var);

private:
	std::vector<BaseData*> datas;
};

template<typename T>
inline void StackInfo::push(T var)
{
	datas.push_back(new Data<T>(var));
}

template<typename T>
inline void StackInfo::pop(T& var)
{
	BaseData* data = datas.back();
	var = static_cast<Data <T>*>(data)->Get();
	datas.pop_back();
	delete data;
}
