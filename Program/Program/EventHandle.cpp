#pragma once

#include "EventHandle.h"
#include "Magazine.h"

#include <iostream>

const int eventNothing = 0;
const int eventMessage = 100;

const int cmdCreate = 1;
const int cmdAdd = 2;
const int cmdDelete = 3;
const int cmdPrint = 4;
const int cmdPrintNames = 5;
const int cmdQuit = 6;

Dialog::Dialog()
{
	executeEnd = false;
}
Dialog::~Dialog()
{

}

void Dialog::Execute()
{
	TEvent custEvent;

	while (!executeEnd)
	{
		std::cout << "\nm - create new group\n+ - add element\n- - delete element\ns - print elements info\nz - print elements names\nq - quit program\n";

		GetEvent(custEvent);
		HandleEvent(custEvent);
	}
}

void Dialog::GetEvent(TEvent& custEvent)
{
	char CommandSym;
	std::cout << "> ";
	std::cin >> CommandSym;

	custEvent.What = eventMessage;

	switch (CommandSym)
	{
	case 'm':
		custEvent.Command = cmdCreate;
		break;
	case '+':
		custEvent.Command = cmdAdd;
		break;
	case '-':
		custEvent.Command = cmdDelete;
		break;
	case 's':
		custEvent.Command = cmdPrint;
		break;
	case 'z':
		custEvent.Command = cmdPrintNames;
		break;
	case 'q':
		custEvent.Command = cmdQuit;
		break;
	default:
		custEvent.What = eventNothing;
		break;
	}

}

void Dialog::HandleEvent(TEvent& custEvent)
{
	if (custEvent.What == eventNothing) {
		std::cout << "Incorrect input" << std::endl;
		return;
	}

	std::string Name;

	switch (custEvent.Command)
	{
	case cmdCreate:
		int Size;

		do
		{
			std::cout << "Enter group size: " << std::endl;
			std::cin >> Size;
		} while (Size <= 0);

		recreate(Size);
		
		break;

	case cmdAdd:
		
		if (elements == nullptr)
		{
			std::cout << "Existing group required" << std::endl;
			return;
		}

		int number;

		do
		{
			std::cout << "Add: 1 - printing, 2 - magazine" << std::endl;
			std::cin >> number;
		} while (number != 1 && number != 2);

		std::cin.ignore();

		if (number == 1)
		{
			Printing* printing = new Printing;
			printing->SetInfo();

			addElem(printing);
		}
		else
		{
			Magazine* magaz = new Magazine;
			magaz->SetInfo();

			addElem(magaz);
		}
		
		break;

	case cmdDelete:
		
		if (elements == nullptr)
		{
			std::cout << "Existing group required" << std::endl;
			return;
		}

		std::cin.ignore();

		std::cout << "Enter name of element to delete" << std::endl;

		getline(cin, Name);

		deleteElem(Name);

	case cmdPrint:

		print(false);
		std::cout << std::endl;
		break;

	case cmdPrintNames:

		print(true);
		std::cout << std::endl;
		break;

	case cmdQuit:

		executeEnd = true;
		break;

	default:
		break;
	}

	custEvent.What = eventNothing;
}