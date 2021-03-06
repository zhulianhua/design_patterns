// strategy.cpp: 定义控制台应用程序的入口点。
//

// 思考：策略模式如何跟状态模式相结合达到动态改变策略的目的？

#include "stdafx.h"
#include <iostream>
using namespace std;

class Strategy
{
public:
	virtual void fun() = 0;
};

class StrategyA : public Strategy {
public:
	void fun() { cout << "calling StrategyA::fun()" << endl; }
};

class StrategyB : public Strategy {
public:
	void fun() { cout << "calling StrategyB::fun()" << endl; }
};

class Context {
	Strategy& strategy;

public:
	Context(Strategy& str) : strategy(str) {}
	void fun() { strategy.fun(); }
};

// 与状态模式结合使用的策略模式, 可以动态改变策略，而不是在初始化的时候就固定死，但是这看起来并没有什么特别的，
// 依然要hard code策略切换函数
class ContextNew {
	Strategy* strategy;
public:
	ContextNew() : strategy(new StrategyA()) {}

	void switchToB() {
		delete strategy;
		strategy = new StrategyB();
	}
	void switchToA() {
		delete strategy;
		strategy = new StrategyA();
	}
	void fun() { strategy->fun(); }
};
int main()
{
	StrategyA sta;
	StrategyB stb;
	// 虽然Context::fun() 不能改变，但是可以在运行时改变其包含的Stratergy对象，从而改变程序的行为
	// 可以结合状态模式，动态变化一个Context对象包含的Stratergy对象
	Context conta(sta), contb(stb);
	conta.fun();
	contb.fun();

	ContextNew contaNew;
	contaNew.fun();
	contaNew.switchToB();
	contaNew.fun();
	contaNew.switchToA();
	contaNew.fun();
	return 0;
}

