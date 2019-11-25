#include "Manager.h"

// Default Constructor
Manager::Manager()
{
	person = NULL;
}

Manager::Manager(char* aName, int aID, char* aAddress, char* aCity, char* aState, int aZip)
{
	person = new Operator(aName, aID, aAddress, aCity, aState,aZip);
}

// Destructor
Manager::~Manager()
{
	if (person)
		delete person;
}

char* Manager::getName()
{
	return person->getName();
}

int Manager::getID()
{
	return person->GetIDnumber();
}

char* Manager::getAddress()
{
	return person->getAdress();
}

char* Manager::getCity()
{
	return person->getCity();
}

char* Manager::getState()
{
	return person->getState();
}

int Manager::getZip()
{
	return person->getZip();
}

// List of options available to manager
int Manager::OptionSelect()
{
	/*
	char Input [1001];
	std::cout << "List options of things to do here.\n";
	std::cin.get(input, 10001, \n);
	std::cin.ignore(1000);

	// Identifying input here
	Case 1:	Get reports
	Case 2: Interactive mode
	*/
	return 0;
}

// When enter interactive mode, we're be doing things to this
int Manager::InteractiveMode()      // Alex: This UI stuff should be implemented in ChocAnMain.cpp.
{                                   //       Very little should be going on in this file.
	int choice;                     //       For interactive mode stuff, main() should be calling DB
	/*                              //       and DB should be calling methods of Provider and Member classes.
	 * Entering interactive mode
	 * Prompt for options within interactive mode
	 */
	std::cout << " You can:\n";
	std::cout << "\tAdd a user\t\t(Enter'A')\n";
	std::cout << "\tEdit a user\t\t(Enter 'E')\n";
	std::cout << "\tRemove a user\t\t(Enter 'R')\n";
	std::cout << "\tExit interactive mode\t\t(Enter 'X')\n";

	std::cin >> choice;
	std::cin.ignore(100, '\n');
	choice = toupper(choice);

	while (choice != 'A' && choice != 'E' 
		&& choice != 'R' && choice != 'X') {
		std::cout << "\nPlease select from the above options.\n";
		std::cin >> choice;
		std::cin.ignore(100, '\n');
		choice = toupper(choice);
	}
	// Option for Add a user
	/*
	if(choice == 'A')
	{
		// GetInformation();
		// Compare IDnumber inputted to see if it's a
		// Provider or a Member.
		if(Provider)
		{
			if(AddProvider(To_Add)
			{
				std::cout << "Add Provider failed\n";
				return -1;
			}
		}
		else if(Member)
		{
			if(AddMember(To_Add)
			{
				std::cout << "Add Member failed\n";
				return -1;
			}
		}
	}

	// Option for edit a member
	if(choice == 'E')
	{

	}
	// Option for remove a member
	if(choice == 'R')
	{

	}
	while(choice != 'X');
	 */
	return 0;
}

// Create new instance of provider
int Manager::AddProvider(Provider& To_Add)
{
	// First person in the system
	if(!person)
		person = new Provider(To_Add);

	return 0;
}

// Create new instance of member
int Manager::AddMember(Member& To_Add)
{
	// First person in the system
	if(!person)
		person = new Member(To_Add);

	if (!person)
		return -1;
	return 0;
}