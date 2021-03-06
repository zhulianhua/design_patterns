// proxy.cpp: 定义控制台应用程序的入口点。
// 为其他对象提供一种代理以控制对这个对象的访问。有四种常用的情况：
//（1）远程代理
//（2）虚代理 : lazy initilization
//（3）保护代理: 如auto_ptr
// (4）智能引用: 如smart_ptr


#include "stdafx.h"
#include <iostream>

using namespace std;

class ProxyBase {
public:
	virtual void f() = 0;
	virtual void g() = 0;
	virtual void h() = 0;
};

class Implementation : public ProxyBase { 
public:
	void f() { cout << "Calling Implementation::f()" << endl; }
	void g() { cout << "Calling Implementation::g()" << endl; }
	void h() { cout << "Calling Implementation::h()" << endl; }
};

// 让Proxy继承ProxyBase的目的是为了能让接口强制统一，另外任何需要操作ProxyBase的地方都可以用Proxy对象
class Proxy : public ProxyBase {
	ProxyBase* implementation;
public:
	Proxy() { implementation = new Implementation(); }
	~Proxy() { delete implementation; };
	void f() { implementation->f(); }
	void g() { implementation->g(); }
	void h() { implementation->h(); }
};

int main()
{
	Proxy proxy;
	proxy.f();
	proxy.g();
	proxy.h();
    return 0;
}