#pragma once

#include <string>

class Object
{
public:
	virtual ~Object() {};
	Object() {};
	virtual std::string GetName() = 0;
	virtual void SetInfo() = 0;
	virtual void GetInfo(bool namesOnly = false) = 0;
};