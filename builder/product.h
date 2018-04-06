#pragma once
#include <string>
#include <iostream>
using namespace std;

class Product {
	string partA;
	string partB;
	string partC;
public:
	void setPartA(string str) { partA = str; }
	void setPartB(string str) { partB = str; }
	void setPartC(string str) { partC = str; }
	string getPartA() { return partA; }
	string getPartB() { return partB; }
	string getPartC() { return partC; }
	void whatInside() { cout << partA << " and " << partB << " and " << partC << endl; }
};