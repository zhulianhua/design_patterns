// State.cpp: 状态模式示例，动态改变。
// 前端对象和后端对象：访问前端对象，动态改变后端对象来根据状态执行不同的策略

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// 笨拙的设计，通过if语句判断
class CreatureRaw {
protected:
	bool isFrog;
	//bool isBlueFrog;
public:
	CreatureRaw(bool frog) : isFrog(frog) {}
	void greet() {
		if (isFrog) {
			cout << "Ha, I'm a frog!!! " << endl;
		}
		else {
			cout << "Darling! I'm your prince" << endl;
		}
	}
	void kiss() { isFrog = false; }
};


// 设计状态模式的设计
class Creature {
	//把这些作为内部类并不是必须的，但是可以是代码更为紧凑
	//把这部分拿到外面去完全不影响编译和执行
	//但是做成内部类的问题是，每次新增加一个状态类型都需要改变这里的代码
	class State {
	public:
		virtual string response() = 0;
	};
	class Frog : public State {
	public:
		virtual string response() {
			return "Hi, I'm a frong";
		}
	};
	class Prince : public State {
	public:
		virtual string response() {
			return  "Darling! I'm your prince";
		}
	};

	State* state;

public:
	Creature() : state(new Frog()) {}
	void greet() {
		cout << state->response() << endl; // 使用状态模式，扩展新状态时，这里不需要改变
	}
	void kiss() {
		delete state;
		state = new Prince(); // 引入新状态岂不是每次也都需要改这里的代码？这里状态切换逻辑
	}
};

int main()
{
	CreatureRaw creaRaw(true);
	creaRaw.greet();
	creaRaw.kiss();
	creaRaw.greet();

	cout << endl << "Testing implementation using the state pattern" << endl;
	Creature crea;
	crea.greet();
	crea.kiss();
	crea.greet();
    return 0;
}

