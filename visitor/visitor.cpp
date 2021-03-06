// visitor.cpp: 定义控制台应用程序的入口点。
// 首先讨论多（双）重派遣的问题，再引出访问者模式来解决这一问题。
// 访问者模式是最复杂的设计模式，也是GoF中的最后一种模式
// 访问者模式用得太少，就不学习了。




#include "stdafx.h"
#include <iostream>
using namespace std;

enum Outcome { WIN, LOSE, DRAW };

class Paper;
class Scissors;
class Stone;

class Item {
public:
	virtual Outcome compete(const Item*)  = 0;
	virtual Outcome eval(const Paper*) const = 0;
	virtual Outcome eval(const Scissors*) const = 0;
	virtual Outcome eval(const Stone*) const = 0;

	// helpr function
	virtual ostream& print(ostream& os) const = 0;
	// 类似外观模式，但不是成员函数，而是友元函数
	friend ostream& operator << (ostream& os, const Item* it) {
		return it->print(os);
	}
};

class Paper : public Item {
public:
	Outcome compete(const Item* it) {
		// 这里的核心问题是需要判断传入参数it被upcate到Item*前的实际类型，有了这一类型，就能判断出Outcome是啥。
		// 这里无法判断Item的派生类型，除非downcasting, 但是不知道具体需要downcast到哪个类。
		// downcasting : (Paper*) it 或者 (Scissors*) it 或者 (Stone*) it
		// 如果it不是Paper*类型，使用这种downcasting，则后续可能会引起不可预知的错误（后面使用的指针指向了不可预知的位置）。
		// 要避免这种情况发生，需要使用更安全的downcasting : dynamic_cast<new_type>() 操作。
		// 比如 dynamic_cast<Paper*>(it)。如果it被upcast之前的确不是Paper*类型，这里dynamic_cast将会返回nullptr
		// 因此这里如果使用dynamic_cast依次检测it是否是Paper, Scissors和Stone中的某一种类型，总是可以判断出其实际类型的。
		return it->eval(this);
	}
	Outcome eval(const Paper*) const { return DRAW; }
	Outcome eval(const Scissors*) const { return WIN; }
	Outcome eval(const Stone*) const  { return LOSE; }
	ostream& print(ostream& os) const { return os << "Paper"; }
};

class Scissors : public Item {
public:
	Outcome compete(const Item* it) {
		return it->eval(this);
	}
	Outcome eval(const Paper*) const { return LOSE; }
	Outcome eval(const Scissors*) const { return DRAW; }
	Outcome eval(const Stone*) const { return WIN; }
	ostream& print(ostream& os) const { return os << "Scissors"; }
};

class Stone : public Item {
public:
	Outcome compete(const Item* it) {
		return it->eval(this);
	}
	Outcome eval(const Paper*) const { return WIN; }
	Outcome eval(const Scissors*) const { return LOSE; }
	Outcome eval(const Stone*) const { return DRAW; }
	ostream& print(ostream& os) const { return os << "Stone"; }
};

// helper operator
ostream& operator<<(ostream& os, const Outcome out) {
	switch (out) {
	default:
	case WIN: return os << "win";
	case LOSE: return os << "lose";
	case DRAW: return os << "draw";
	}
}

int main()
{
	// 测试我们实现的双重派遣
	Item* ita = new Paper();
	Item* itb = new Scissors();

	Paper* itCast = dynamic_cast<Paper*>(itb);
	if (itCast == nullptr) {
		cout << "Not correct type!" << endl;
	}

	// 注意这里神奇的输出流转换，尽管ita和itb现在都是Item*类型，但是还是可以弄出其原始类型
	cout << "ita is type: " << ita << ", and itb is type: " << itb << endl;
	// C++中只有单重派遣，遇上下面这种情况，ita和itb都是Item*类型，
	// 受限调用ita的compete函数，执行第一次派遣，顺利的找到ita的虚函数Paper::compete(Item*)，
	// 然后itb仍然没有转换，仍然是Item*类型，不能发生第二次派遣。
	// 即使我们可以定义Paper::compete(Scissors*）这种函数也没有意义, 因为itb不能被downcast为Scissors*类型。
	cout << ita->compete(itb) << endl;
    return 0;
}
