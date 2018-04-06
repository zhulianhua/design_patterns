#pragma once
#include <string>
#include "Beverage.h"

using namespace std;

// 这里我们故意不从Decorator类继承，而是直接从Beverage继承，看看会有啥不同
// 后面的测试发现，这样也能行得通。但是逻辑上比有Decorator类时模糊
// 比如Soy和Espresso都是直接继承自Beverage, 但是Soy本质上是个装饰，而Espresso是饮料，
// 另外Soy新引入了Beverage成员, 构造上也和Espresso不同，构造函数也不同
class Soy : public Decorator {
public:
	Soy(Beverage* b) : Decorator(b) {}
	double cost() { return 0.2 + beverage->cost(); }
	string getDescription() { return beverage->getDescription() + " with Soy"; }
	CupSize getCupSize() { return beverage->getCupSize(); }
};