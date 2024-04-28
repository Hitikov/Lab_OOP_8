#pragma once
#include "Printing.h"
#include <string>
#include <iostream>

using namespace std;

Printing::Printing(string inName, string inAuthor) 
{
	name = inName;
	author = inAuthor;
}

void Printing::SetName(string inName)
{
	name = inName;
}
void Printing::SetAuthor(string inAuthor)
{
	author = inAuthor;
}

string Printing::GetName()
{
	return name;
}
string Printing::GetAuthor()
{
	return author;
}

void Printing::SetInfo()
{
	cout << endl << "Enter printing name: ";
	getline(cin, name);
	cout << endl << "Enter printing author: ";
	getline(cin, author);
}
void Printing::GetInfo(bool nameOnly = false)
{
	if (!nameOnly) {
		cout << endl << "Printing information" << endl;
		cout << "Name: " << GetName() << endl;
		cout << "Author: " << GetAuthor() << endl;
	}
	else {
		cout << GetName();
	}
}

Printing& Printing::operator= (Printing& copyBase)
{
	name = copyBase.name;
	author = copyBase.author;

	return *this;
}