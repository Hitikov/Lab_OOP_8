#pragma once
#include "Printing.h"
#include <string>

using namespace std;

class Magazine : public Printing
{
protected:
	int pageCount;
public:
	Magazine() :Printing() { pageCount = 0; };
	Magazine(string, string, int);
	virtual ~Magazine() {};

	void SetPageCount(int);
	int GetPageCount();

	virtual void SetInfo();
	virtual void GetInfo(bool);

	Magazine& operator= (Magazine&);
};