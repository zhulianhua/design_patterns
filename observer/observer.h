/*
* @Author: lhzhu
* @Date:   2018-03-30 23:00:13
* @Last Modified by:   lhzhu
* @Last Modified time: 2018-03-30 23:00:13
*/

/*
* 思考：当对象A和B需要对另外一个对象C发出的不同的事件（事件1, 事件2）感兴趣时需要如何处理？
* 方案：需要让对象C包含派生自Subject的事件1对应的派生类对象，和派生自Subject的事件2派生类对象
* 还需要让对象A和B包含针对事件1的派生自Observer的类对象和针对事件2的派生自Observer的类对象
*/

#ifndef OBSERVER_H
#define OBSERVER_H

#define DEBUG

#include <iostream>

class Argument {
};

// use forward declaration instead of #include
class Subject;

class  Observer{
public:
	Observer() {}
	virtual ~Observer() {}
	// sub 作为因此update()操作的对象也作为参数放进来，并不是Observer模式所要求的
	// 但是当一个Observer被注册到多个Subject时，这个参数就有用了。
	// update函数的参数可以根据需要任意设置
	// arg存放所有的额外参数
	virtual void update(Subject* sub, Argument* arg) = 0; // make this class to be virtual
};

class  ObserverA : public Observer{
public:
	ObserverA(){}
	virtual ~ObserverA(){}
	virtual void update(Subject* sub, Argument* arg) {
		std::cout << "calling ObserverA::update() " << std::endl;
	}
};

class  ObserverB : public Observer{
public:
	ObserverB() {}
	virtual ~ObserverB() {}
	virtual void update(Subject* sub, Argument* arg) {
		std::cout << "calling ObserverB::update() " << std::endl;
		//std::cout << sub->hasChanged() << std::endl;
	}
};

class  ObserverC : public Observer{
public:
	ObserverC() {}
	virtual ~ObserverC() {}
	virtual void update(Subject* sub, Argument* arg) {
		std::cout << "calling ObserverC::update() " << std::endl;
	}
};

#endif