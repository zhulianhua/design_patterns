 //adaptor.cpp: 定义控制台应用程序的入口点。
 //定义： 将一个类的接口，转化成客户期望的另一个类的接口。适配器让原本接口不兼容的类可以合作无间。
 //
 //不要将适配器模式与外观模式混为一谈 : 适配器是改变接口符合客户需求，而外观模式是简化接口或者将客户从多组件子系统解耦
 //注意适配器模式和装饰者模式看起来很像
 //双向适配器
 //区分对象适配器和类适配器:类适配器使用多重继承来实现(C++中可以），而Java中不行。
 //对象适配器使用组合来实现，适配器类中包含一个被适配类的对象，所以才叫对象适配器。
 //对象适配器还可以适配被适配类的派生类。

#include "stdafx.h"
#include <iostream>

using namespace std;

class Target {
	//friend void fun(Target* target);
public:
	//virtual void request() { cout << "Target::request()" << endl; }
	//或者是虚基类
	virtual void request() = 0;
};


class NormalTarget : public Target {
public:
	void request();
};

void NormalTarget::request()
{
	cout << "NormalTarget::request()" << endl;
}

class Adaptee {
public:
	void specificRequest() { cout << "Adaptee::specificRequest()" << endl; }
};

class Adapter : public Target {
private:
	Adaptee * adaptee;
public:
	Adapter(Adaptee* a) : adaptee(a) {}
	void request() { adaptee->specificRequest(); }
};

// Client 函数，接受Target
void fun(Target* target) {
	target->request();
}

int main()
{
	Target* normal = new NormalTarget();
	fun(normal);
	Adaptee adaptee;
	Target* adapter = new Adapter(&adaptee);
	fun(adapter);
    return 0;
}

