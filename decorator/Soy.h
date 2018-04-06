#pragma once
#include <string>
#include "Beverage.h"

using namespace std;

// �������ǹ��ⲻ��Decorator��̳У�����ֱ�Ӵ�Beverage�̳У���������ɶ��ͬ
// ����Ĳ��Է��֣�����Ҳ���е�ͨ�������߼��ϱ���Decorator��ʱģ��
// ����Soy��Espresso����ֱ�Ӽ̳���Beverage, ����Soy�������Ǹ�װ�Σ���Espresso�����ϣ�
// ����Soy��������Beverage��Ա, ������Ҳ��Espresso��ͬ�����캯��Ҳ��ͬ
class Soy : public Decorator {
public:
	Soy(Beverage* b) : Decorator(b) {}
	double cost() { return 0.2 + beverage->cost(); }
	string getDescription() { return beverage->getDescription() + " with Soy"; }
	CupSize getCupSize() { return beverage->getCupSize(); }
};