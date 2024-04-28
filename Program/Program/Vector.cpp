#include "Vector.h"
#include "Object.h"
#include <string>
#include <iostream>


Vector::Vector()
{
	elements = nullptr;
	length = 0;
	curLength = 0;
}
Vector::Vector(int len)
{
	elements = new Object* [len];

	length = len;
	curLength = 0;
}
Vector::~Vector()
{
	if (!(elements = nullptr)) {
		for (int i = 0; i < curLength; i++) {
			delete elements[i];
		}

		delete[] elements;
	}
}

void Vector::recreate(int len)
{
	if (!(elements = nullptr)) {
		for (int i = 0; i < curLength; i++) {
			delete elements[i];
		}

		delete[] elements;
	}

	length = len;
	elements = new Object * [len];
	curLength = 0;
}

bool Vector::addElem(Object* element)
{
	if (curLength >= length) {
		std::cout << "Group is owerflowed" << std::endl;
		return false;
	}

	elements[curLength] = element;
	curLength++;
	return true;
}
bool Vector::deleteElem(std::string name)
{
	if (curLength == 0) {
		std::cout << "Group is empty" << std::endl;
		return false;
	}

	bool flag = false;

	for (int i = 0; i < curLength && !flag; i++) {
		flag = elements[i]->GetName() == name;

		if (flag) {
			Object* temp = elements[i];

			for (int j = i; j < curLength - 1; j++) {
				elements[j] = elements[j + 1];
			}

			delete temp;

			curLength--;

		}
	}

	if (!flag) std::cout << "Element not found" << std::endl;

	return flag;
}

void Vector::print(bool namesOnly)
{
	if (curLength == 0) {
		std::cout << "Group is empty" << std::endl;
		return;
	}

	elements[0]->GetInfo(namesOnly);

	for (int i = 1; i < curLength; i++) {
		std::cout << std::endl;
		elements[i]->GetInfo(namesOnly);

	}
}