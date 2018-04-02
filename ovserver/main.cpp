#include "Observer.h"
#include "Subject.h"
#include "InnerClassIdiom.h" // test inner class

#include <iostream>
#include <set>

int main()
{
	SubjectA s;
	ObserverA oa;
	ObserverB ob;
	ObserverC oc;

	s.registerObserver(oa);
	s.registerObserver(oa);
	// Question: Why we can still register the same observer twice, while we have used std::set<>
	// Answer:  For a set, you can call insert() multiple times to insert the same object, but only one can 
	//	actuall exist in the set.
	std::cout << "# of observers:" << s.countObservers() << std::endl;
	s.registerObserver(ob);
	s.registerObserver(oc);
	std::cout << "# of observers:" <<  s.countObservers() << std::endl;

	s.notifyOvsevers();
	// Only three observers will be notified, oa, ob and oc, instead of four, i.e, oa, oa, ob and oc;
	// This is why we use set

	s.removeObserver(oa);
	s.notifyOvsevers();
	std::cout << "clearChanged() in main " << std::endl;
	s.clearChanged();
	s.notifyOvsevers();
	std::cout << "setChanged() in main " << std::endl;
	s.setChanged();
	s.notifyOvsevers();

	//
	std::cout << "Test inner class implementation" << std::endl;
	outerClass out("aaa");
	// upcast from outerClass to baseClassA
	callBaseClassAFunction(out);
	// upcast from outerClass to baseClassB
	callBaseClassBFunction(out);
	return 0;
}