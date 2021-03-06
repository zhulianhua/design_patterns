// template_method.cpp: 定义控制台应用程序的入口点。
//

// 模板方法常见的作用是用在驱动程序运行的引擎，


#include "stdafx.h"
#include <iostream>
using namespace std;

class baseClass {

// 这两个函数被保护起来，不许客户代码直接访问，
// 要使用它们的功能只能功过模版方法来访问, 原则 “坚持相同的代码”
protected:
	virtual void funA() = 0;
	virtual void funB() = 0;

public:
	baseClass() {}
	// 这个函数就是模版方法函数
	// 客户代码总是通过这个基类的模版方法函数使用其功能, 并且语法总是这样
	// 需要需要变化的代码封装起来，但是这个函数本身不会变化，因为他不是虚函数
	void templateMethod() {
		funA();
		funB();
	}
};

class derivedClassA : public baseClass {
public:
	derivedClassA() {}
protected:
	virtual void funA() {
		cout << "calling derivedClassA::funA()" << endl;
	}
	virtual void funB() {
		cout << "calling derivedClassA::funB()" << endl;
	}
};

class derivedClassB : public baseClass {
public:
	derivedClassB() {}

protected:
	virtual void funA() {
		cout << "calling derivedClassB::funA()" << endl;
	}
	virtual void funB() {
		cout << "calling derivedClassB::funB()" << endl;
	}
};

/* 实际中的应用： 对于很多数值模拟程序，通常包含如下过程：
 * 初始化参数
 * 开辟内存
 * 定义网格
 * 初始化场
 * 演化 (包含演化内部，处理边界，并行通信)
 * 每个多少步输出场
 * 运行完毕的清理工作
 *
 * 可以定义一个抽象的Simulation类，使用模板方法定义其基本流程，然后客户代码可以总是使用一个相同的模版方法来完成其功能
 */

class Simulation {
protected:
	virtual void initParameters() = 0;
	virtual void allocateMemory() = 0;
	virtual void initMesh() = 0;
	virtual void initField() = 0;
	virtual void updateInternal() = 0;
	virtual void updateBoundary() = 0;
	virtual void parallelCommunicate() = 0;
	virtual void writeData() = 0;
	virtual void cleanUp() = 0;

public:
	void initilize() {
		initParameters();
		allocateMemory();
		initMesh();
		initField();
	}
	void evolve() {
		updateInternal();
		updateBoundary();
		parallelCommunicate();
	}
	void saveData() {
		writeData();
	}
	void finalize() {
		cleanUp();
	}
};

class LbmSimulation : public Simulation {
private:
	double tau;
	int N;
	double* rho;

protected:
	virtual void initParameters() { cout << "setting parmetering" << endl;  tau = 0.5; N = 1000; };
	virtual void allocateMemory() { cout << "allocating memory for data fileds " << endl;  rho = new double[N]; };
	virtual void initMesh() { cout << "Creating uniform Cartesin mesh! " << endl; };
	virtual void initField() { for (int i = 0; i < N; i++) rho[i] = 1.0; };
	virtual void updateInternal() { 
		for (int i = 0; i < N; i++)
			rho[i] += 0.01;
	};
	virtual void updateBoundary() { cout << "Boucing back" << endl; };
	virtual void parallelCommunicate() { cout << "Exchanging data" << endl; };
	virtual void writeData() { cout << "Wrting data" << endl; };
	virtual void cleanUp() { cout << "deallocating data" << endl; delete[] rho; };
};

int main()
{
	derivedClassA ca;
	ca.templateMethod();
	derivedClassB cb;
	cb.templateMethod();

	baseClass* ba = new derivedClassA;
	ba->templateMethod();
	ba = new derivedClassB;
	ba->templateMethod();

	LbmSimulation lbmsim;
	lbmsim.initilize();
	lbmsim.evolve();
	lbmsim.saveData();
	lbmsim.finalize();

    return 0;
}

