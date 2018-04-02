/*
* @Author: lhzhu
* @Date:   2018-04-01 20:24:40
* @Last Modified by:   lhzhu
* @Last Modified time: 2018-04-01 20:25:00
*/

// 如果一个派生类从不同的基类派生得到，有些时候需要把派生类对象upcast为不同的基类，
// 可以使用C++的内部类做到
#ifndef INNERCLASSIDIOM_H
#define INNERCLASSIDIOM_H

#include <iostream>
#include <string>

// base class A
class baseClassA {
public:
	virtual void funcA() = 0;
};

class baseClassB {
public:
	virtual void funcB() = 0;
};

void callBaseClassAFunction(baseClassA& ba) {
	ba.funcA();
};

void callBaseClassBFunction(baseClassB& bb) {
	bb.funcB();
};


// 通过内部类而不是派生来提供基类的接口
class outerClass {
	std::string name;
	class innerClassA;
	friend class outerClass::innerClassA;
	class innerClassA : public baseClassA {
		outerClass* parent;
	public:
		innerClassA(outerClass* outer) : parent(outer) {}
		virtual void funcA() {
			std::cout << "funA() called for " << parent->name << std::endl;
		}

	} innerA;

	class innerClassB;
	friend class outerClass::innerClassB;
	class innerClassB : public baseClassB {
		outerClass* parent;
	public:
		innerClassB(outerClass* outer) : parent(outer) {}
		virtual void funcB() {
			std::cout << "funB() called for " << parent->name << std::endl;
		}
	} innerB;

public:
	outerClass(const std::string& nm) : name(nm), innerA(this), innerB(this) {}
	operator baseClassA&() { return innerA; }
	operator baseClassB&() { return innerB; }

};

#endif