#pragma once
#include "Object.h"
#include <string>

class Printing : public Object {
protected:
	std::string name;
	std::string author;
public:
	Printing() {};
	Printing(std::string, std::string);
	virtual ~Printing() {};

	void SetName(std::string);
	void SetAuthor(std::string);
	
	std::string GetName();
	std::string GetAuthor();

	virtual void SetInfo();
	virtual void GetInfo(bool);

	Printing& operator= (Printing&);
};