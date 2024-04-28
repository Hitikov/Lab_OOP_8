#pragma once
#include "Magazine.h"
#include <string>
#include <iostream>


Magazine::Magazine(string inName, string inAuthor, int inPageCount) :Printing(inName, inAuthor) {
	pageCount = inPageCount;
}

void Magazine::SetPageCount(int inPageCount)
{
	pageCount = inPageCount;
}
int Magazine::GetPageCount()
{
	return pageCount;
}

void Magazine::SetInfo()
{
	Printing::SetInfo();
	cout << endl << "Enter count of printing's pages: ";
	cin >> pageCount;
}
void Magazine::GetInfo(bool nameOnly = false)
{
	Printing::GetInfo(nameOnly);

	if (!nameOnly)
	{
		cout << "Count of pages: " << GetPageCount() << endl;
	}
}

Magazine& Magazine::operator= (Magazine& copyBase)
{
	Printing::operator=(copyBase);
	pageCount = copyBase.pageCount;

	return *this;
}