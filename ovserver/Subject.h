#ifndef SUBJECT_H
#define SUBJECT_H
#define DEBUG

#include <set>
#include <iostream>

// argument to be sent to observers

// Must use #include instead of using forward declaration if want to compile independently, i.e.,
// put the implementation in a cpp file.
// Because, this file call the update() function from the Observer

#include "Observer.h"
//class Observer; 


class Subject
{
private:
	// why use set here instead of list or vector?
	// Answer : To prevent copy!
	std::set<Observer*> observers; 

protected:
	// 放在protected 里面，所以只要Subject的继承者才能设置这一状态, 而Observer无权设置它们。
	// Subject类对象也无法访问它们。
	virtual void setChanged() { changed = true; }
	virtual void clearChanged() { changed = false; }
	bool changed;

public:
	Subject() {};
	virtual ~Subject() {}
	// register a new observer to the set
	virtual void registerObserver(Observer& o) {
		observers.insert(&o);
		std::cout << "register a new observer" << std::endl;

	}
	// remove a specific observer
	virtual void removeObserver(Observer& o) {
		observers.erase(&o);
		std::cout << "remove a observer" << std::endl;
	}

	// remove all observers
	virtual void removeAllObservers() {
		observers.clear();
		std::cout << "remove all observers" << std::endl;
	}

	// arg是订阅的主题内容, 这样设计可以让Subject只负责维护Observers和通知他们, 而不负责维护这个arg，
    // arg是随时传进来的
	virtual void notifyOvsevers(Argument* arg = 0) {
		if (!hasChanged()) return;
		clearChanged();
		std::set<Observer*>:: iterator it;
		std::cout << "Notify each observer" << std::endl;
		for (it = observers.begin(); it != observers.end(); it++)
			(*it) -> update(this, arg);
	}

	// see if changed?
	virtual bool hasChanged() { return changed; }

	// count the number of observers
	virtual int countObservers() {
		return observers.size();
	}


};

// SubjectA的派生类实现setChanged()和clearChanged()的具体逻辑
class SubjectA : public Subject {
public:
	virtual void setChanged() { changed = true; }
	virtual void clearChanged() { changed = false; }
};

#endif