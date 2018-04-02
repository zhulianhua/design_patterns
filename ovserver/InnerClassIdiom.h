/*
* @Author: lhzhu
* @Date:   2018-04-01 20:24:40
* @Last Modified by:   lhzhu
* @Last Modified time: 2018-04-01 20:25:00
*/

// ���һ��������Ӳ�ͬ�Ļ��������õ�����Щʱ����Ҫ�����������upcastΪ��ͬ�Ļ��࣬
// ����ʹ��C++���ڲ�������
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


// ͨ���ڲ���������������ṩ����Ľӿ�
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