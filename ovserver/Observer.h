/*
* @Author: lhzhu
* @Date:   2018-03-30 23:00:13
* @Last Modified by:   lhzhu
* @Last Modified time: 2018-03-30 23:00:13
*/

/*
* ˼����������A��B��Ҫ������һ������C�����Ĳ�ͬ���¼����¼�1, �¼�2������Ȥʱ��Ҫ��δ���
* ��������Ҫ�ö���C����������Subject���¼�1��Ӧ����������󣬺�������Subject���¼�2���������
* ����Ҫ�ö���A��B��������¼�1��������Observer������������¼�2��������Observer�������
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
	// sub ��Ϊ���update()�����Ķ���Ҳ��Ϊ�����Ž�����������Observerģʽ��Ҫ���
	// ���ǵ�һ��Observer��ע�ᵽ���Subjectʱ����������������ˡ�
	// update�����Ĳ������Ը�����Ҫ��������
	// arg������еĶ������
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