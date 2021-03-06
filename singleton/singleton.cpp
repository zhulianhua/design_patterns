// singleton.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Singleton {
	int i;
	// 把构造函数放到private里面，所以无法创建Singleton对象
	Singleton(int x) : i(x) {}
	Singleton& operator=(Singleton&); // Disallowed
	Singleton(Singleton&); // Disallowed

public:
	static Singleton& instace() {
		static Singleton s(0);
		return s; }
	int getValue() { return i; }
	void setValue(int x) { i = x; }
};

int main()
{
	Singleton& single = Singleton::instace(); // 任何时候只存在一个引用
    return 0;
}