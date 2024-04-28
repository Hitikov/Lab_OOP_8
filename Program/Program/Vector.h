#pragma once
#include "Object.h"
#include <string>

class Vector
{
protected:
	Object** elements;
	int length;
	int curLength;

public:

	Vector();
	Vector(int);
	~Vector();

	void recreate(int);

	bool addElem(Object*);
	bool deleteElem(std::string);

	void print(bool);
};

