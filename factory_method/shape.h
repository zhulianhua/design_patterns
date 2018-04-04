#pragma once
#include <string>
using namespace std;

class Shape {
public:
	virtual void draw() = 0;
	virtual void erase() = 0;

	// �ѹ����������Ϊ����ľ�̬���������еļ򵥹���ģʽר����һ�������࣬�ṩ����������������(�����Factory��)
	//class BadShapeCreation : public logic_error {
	//public:
	//	BadShapeCreation(string str) : logic_error("Error !! Can not create Shape with type " + str) {};
	//};
	//static Shape* createShape(string str) throw(BadShapeCreation); //������������׳����쳣�������ﶨ��
};