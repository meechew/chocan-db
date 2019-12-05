#include "Manager.h"

// Default Constructor
Manager::Manager(): Operator() { }

// ID# Constructor
Manager::Manager(int ID): Operator(ID) { }

// ID Constructor
Manager::Manager(char* aName, int aID, char* aAddress, char* aCity, char* aState, int aZip):
            Operator(aName, aID, aAddress, aCity, aState, aZip, true) { }

// Destructor
Manager::~Manager() { }



// List of options available to manager
/*int Manager::OptionSelect(ChocAnDB & database)
{
	int choice;

	std::cout << "\n\tGenerate Report\t\t(Enter'R')\n";
	std::cout << "\tEnter Interactive Mode (Manager Only)\t\t(Enter 'I')\n";
	std::cout << "$";	// To prompt user to enter, common practice for command or console program

	std::cin >> choice;
	std::cin.ignore(100, '\n');
	choice = toupper(choice);

	while (choice != 'R' && choice != 'I') {
		std::cout << "\nPlease select from the above options.\n";
		std::cin >> choice;
		std::cin.ignore(100, '\n');
		choice = toupper(choice);
	}

	switch (choice)
	{
	case 'R':
		 Generate Report Here
		 *	1. Get operator ID Number
		 *	2. Run that class's report
		 *	3. ???
		 *	4. Profit
		
		break;
	case 'I':
		InteractiveMode(database);
		break;
	default:
		break;
	}
	return 0;
}
*/
// Wrapper for interactive mode.
// Opens DB, passes as arg to InteractiveMode(DB).
// Called from ChocAnMain.cpp
int Manager::EnterInteractiveMode() {

    // Open DB:
    int RetInt = 0;
    ChocAnDB * database = new ChocAnDB(RetInt);

    return InteractiveMode(*database);
}

// When enter interactive mode, we're be doing things to this
int Manager::InteractiveMode(ChocAnDB & database)
{
	ident To_Add;
	char choice;
	int IDnum;
	bool isInteractive = true;
	std::string user_input;
	
	 // Entering interactive mode
	 // Prompt for options within interactive mode
	 
	std::cout << " You can:";
	while (isInteractive == true)
	{
		std::cout << "\n\tAdd a user\t\t\t\t(Enter 'A')\n";
		std::cout << "\tEdit a user\t\t\t\t(Enter 'E')\n";
		std::cout << "\tRemove a user\t\t\t(Enter 'R')\n";
		std::cout << "\tAdd a new service\t\t(Enter 'S')\n";
		std::cout << "\tExit interactive mode\t(Enter 'X')\n";
		std::cout << "$";	// To prompt user to enter, common practice for command or console program

		std::cin >> choice;
		std::cin.ignore(100, '\n');
		choice = toupper(choice);

		while (choice != 'A' && choice != 'E'
			&& choice != 'R' && choice != 'X' && choice != 'S') {
			std::cout << "\nPlease select from the above options.\n";
			std::cin >> choice;
			std::cin.ignore(100, '\n');
			choice = toupper(choice);
		}

		bool valid = false;
		int svc_code = 0;
		float fee = 0.0;
		int error = 0;
		std::string s_name;

		switch (choice)
		{
		case 'A':
			
			char input[MAX_NAME];
			
			std::cout << "Enter User's NAME: ";
			std::cin >> To_Add.name;
			std::cin.ignore(MAX_NAME, '\n');

			To_Add.number = 0;

			std::cout << "Enter User's ADDRESS: ";
			std::cin >> To_Add.address;
			std::cin.ignore(MAX_NAME, '\n');
			
			std::cout << "Enter user's CITY: ";
			std::cin >> To_Add.city;
			std::cin.ignore(MAX_CITY, '\n');
			
			std::cout << "Enter User's STATE: ";
			std::cin >> To_Add.state;
			std::cin.ignore(2, '\n');
			
			std::cout << "Enter User's ZIP CODE: ";
			std::cin >> To_Add.zip;
			std::cin.ignore(5, '\n');

			char member_type;
            std::cout << "Enter the type of user: \t (p - provider) (m - member)\n";
            std::cout << "$";
            std::cin >> member_type;
            member_type = toupper(member_type);
			if (member_type == 'P')	// Add a Provider
				AddProvider(To_Add, database);
			else if (member_type == 'M')	// Add a Member
				AddMember(To_Add, database);
			break;

		case 'E':
			IDnum = 0;
			do
			{
				std::cout << "Enter an ID for edit: ";
				if(!isdigit(std::cin.peek()))
					std::cout << "Is not a number.\n";
				else
				{
					std::cin >> IDnum;
					if (IDnum <= 0 || IDnum > MAX_ID)
						std::cout << "Is not a valid ID.\n";
					else
						valid = true;
				}
				std::cin.ignore(100, '\n');
			} while (valid == false);
			break;

		case 'R':
			IDnum = 0;
			do
			{
				std::cout << "Enter an ID for edit: ";
				if (!isdigit(std::cin.peek()))
					std::cout << "Is not a number.\n";
				else
				{
					std::cin >> IDnum;
					if (IDnum <= 0 || IDnum > MAX_ID)
						std::cout << "Is not a valid ID.\n";
					else
						valid = true;
				}
				std::cin.ignore(100, '\n');
			} while (valid == false);
			break;

		case 'X':
			std::cout << "Exiting Interactive Mode. . .\n\n";
			isInteractive = false;
			break;

        case 'S':
            std::cout << "Enter service name:\n";
            std::cin >> user_input;
            s_name = new char[strlen(user_input.c_str()) + 1];
            std::cin.ignore(MAX_SVC_NAME, '\n');
            std::cout << "Enter service code:\n";
            std::cin >> svc_code;
            std::cin.ignore(100,'\n');
            std::cout << "Enter service fee:\n";
            std::cin >> fee;
            std::cin.ignore(100,'\n');
            database.AddServ(svc_code, s_name.c_str(), fee, error); // write service to db
            break;

		default:
			std::cout << "If you are reading this prompt, please let the dev team know\n\n";
			break;
		}
	}

	return 0;
}

// Create new instance of provider
//If return -1 == UNDEFINED
int Manager::AddProvider(ident& To_Add, ChocAnDB & database)
{
	char type = 'p';
	int retInt = 0;
	int result;
	// ADD PROVIDER TO DATABASE
	result = database.AddUser(type, To_Add, retInt);
	return result;
}

// Create new instance of member
int Manager::AddMember(ident& To_Add, ChocAnDB & database)
{
	char type = 'm';
	int retInt = 0;
	int result;
	// ADD MEMBER TO DATABASE
	result = database.AddUser(type, To_Add, retInt);
	return result;
	
}

int Manager::Write_Report(int ID)
{
	std::ofstream out;

	out.open("ManagerReport.txt");
	out << ("Testing writing to filen\n");

	// Get Manager
	int RetInt = 0;
	ChocAnDB* database = new ChocAnDB(RetInt);
	ident provider = database->GetUser('p', ID, RetInt);
	out << "PROVIDER NAME: " << provider.name << std::endl;
	out << "ID: " << provider.number << std::endl;
	out << "ADDRESS: " << provider.address << std::endl;
	out << "CITY: " << provider.city << std::endl;
	out << "STATE: " << provider.state << std::endl;
	out << "ZIP: " << provider.zip << std::endl << std::endl;
	// Output provider data to file

	// Get service base on providerID
	ServRep* report;
	report = database->GetServRep('p', provider.number, RetInt);
	//ident member = database->GetUser('m', report member id, RetInt);

	// Get ALL Services for that provider
	/*
	 * SERVICE PROVIDED FOR: // member.name
	 * SERVICE SUMMARY: // service->getName();
	 * PROVIDED DATE: // service->getProvDate();
	 * LOGGED DATE: // service->getLogDate();
	 * FEE: // service->getFee();
	 * COMMENTS: // service->getComments();
	 */

	out.close();
	return 0;
}