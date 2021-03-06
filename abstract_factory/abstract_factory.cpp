// abstract_factory.cpp: 定义控制台应用程序的入口点。
// 抽象工厂模式： 具体工长可以创建系列对象，比如家电工厂是抽象工厂，可以创建手机和电视。抽象工程模式是工厂方法的拓展。
// 工厂方法只能生产同一种类型的产品，而抽象工厂模式可以生产一系列不同类型的产品。
// 类 ： 抽象工厂，具体工厂，抽象产品，具体产品
// 工厂可以创建系列产品，比如电子产品工厂是抽象工厂，可以创建手机和电视机
// 华为终端厂 是专门生产华为手机和电视的具体工厂
// 小米家电厂 是专门生产小米手机和电视的具体工厂
// 手机和电视都是抽象产品
// 华为手机和华为电视是具体产品
// 小米手机和小米电视是具体产品
// 可见使用抽象工厂模式时，增加一个电子产品品牌很容易，只需要增加具体工厂和系列的具体产品(手机电视)即可
// 但是如果突然想要增加一个产品，比如平板电脑，则会非常麻烦，因为这时需要修改之前定义的各种具体工厂，增加创建新产品的接口，
// 这违反了“开放闭合”原则。
// 实例：

#include "stdafx.h"
#include "factory.h"
#include "huaweiFactory.h"
#include "xiaomiFactory.h"
#include "phone.h"
#include "tv.h"

int main()
{
	Factory* fac = new HuaweiFactory();
	Phone* phone = fac->createPhone();
	phone->showSpec();
	Tv* tv = fac->createTv();
	tv->showUsage();

	// 换成小米的工厂
	fac = new XiaomiFactory();
	phone = fac->createPhone();
	phone->showSpec();
	tv = fac->createTv();
	tv->showUsage();
    return 0;
}

