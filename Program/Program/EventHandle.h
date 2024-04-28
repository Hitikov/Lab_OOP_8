#pragma once

#include "Vector.h"

class TEvent
{
public:
	int What;
	int Command;
};

class Dialog : public Vector
{
protected:
	
	bool executeEnd;

public:

	Dialog();
	~Dialog();

	void Execute();

	void GetEvent(TEvent&);

	void HandleEvent(TEvent&);
};