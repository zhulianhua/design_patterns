// command.cpp: 定义控制台应用程序的入口点。
// 命令模式：命令模式就是作为把函数封装为对象
// 思考：在做模拟时，经常需要每隔多少步就执行某种操作，比如写文件，输出到屏幕，检查是否收敛等等，这些可以作为命令对象组织起来

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Command {
public:
	virtual void execute() = 0;
};

class Hello : public Command {
public:
	void execute() {
		cout << "Hello! ";
	}
};

class World : public Command {
public:
	void execute() {
		cout << "World, ";
	}
};

class Iam : public Command {
public:
	void execute() {
		cout << "I'm the command pattern" << endl;
	}
};

class Macro {
	vector<Command*>  commands;
public:
	void addCommand(Command* cmd) {
		commands.push_back(cmd);
	}
	void run() {
		vector<Command*>::iterator iter = commands.begin();
		while (iter != commands.end())
			(*iter++)->execute();
	}
};

// 一个更为真实的例子：在循环执行一些任务时，需要处理某些异步发生的事件，使用命令模式来完成。

class Task {
public:
	virtual void operation() = 0;
};

// 首先使用单件模式定义一个TaskRunner, 相当于上面例子中的Macro类
class TaskRunner {
	static vector<Task*> tasks;
	TaskRunner() {} // make it a sSingleton
	//TaskRunner& operator=(TaskRunner&); // disallowed assign
	TaskRunner(const TaskRunner&); // disallowed
	//static TaskRunner tr;
public:
	static void add(Task& t) { tasks.push_back(&t); }
	static void run() {
		vector<Task*>::iterator iter = tasks.begin();
		while (iter != tasks.end())
			(*iter++)->operation();
	}
};

// 静态变量需要在这里实现
//TaskRunner TaskRunner::tr;
vector<Task*> TaskRunner::tasks;

class EventSimulator {
	clock_t creation;
	clock_t delay;
public:
	EventSimulator() : creation(clock()) {
		delay = CLOCKS_PER_SEC / 10 * (rand() % 20 + 1);
		cout << "delay = " << delay << endl; 
	}
	bool fired() {
		return clock() > creation + delay; // delay秒之后才可以点火发射！
	}
};

class Button {bool pressed;
	string id;
	EventSimulator e;
public:
	Button(string name) : id(name), pressed(false) {}
	void press() { pressed = true; }
	bool isPressed() {
		if (e.fired()) press();
		return pressed;
	}
	friend ostream&
	operator<<(ostream& os, const Button&b) {
		return os << b.id;
	}
};

class CheckButton : public Task {
	Button& button;
	bool handled;

public:
	CheckButton(Button& b) : button(b), handled(false) {}
	void operation() {
		if (button.isPressed() && !handled) {
			cout << button << " pressed " << endl;
			handled = true;
		}
	}
};

// 在循环处理下面这些任务的时候，突然按下1/2/3号中的任意一个按钮，就作相应的处理
void procedure1() {
	// do procedure1 here
	TaskRunner::run();
}

void procedure2() {
	// do procedure2 here
	TaskRunner::run();
}

void procedure3() {
	// do procedure3 here
	TaskRunner::run();
}


int main()
{
	Macro macro;
	macro.addCommand(new Hello()); // 创建并传递命令对象
	macro.addCommand(new World());
	macro.addCommand(new Iam());
	macro.run();

	// test the taskrunner
	srand((int) time(0));
	Button b1("Button 1"), b2("Button 2"), b3("Button 3");
	CheckButton cb1(b1), cb2(b2), cb3(b3);
	TaskRunner::add(cb1);
	TaskRunner::add(cb2);
	TaskRunner::add(cb3);

	while (true) {
		procedure1();
		procedure2();
		procedure3();
	}
    return 0;
}