#include <cstring>
#include "Service.h"

// Default Constructor
Service::Service()
{
	service_name = NULL;
	service_code = 0;
	provided_date = NULL;
	logged_date = NULL;
	memberID = 0;
	providerID = 0;
	service_fee = 0.0;
	comments = NULL;
}

// Constructor w/ Args
Service::Service(char* s_name, int code, char* p_date, char* l_date, int mID, int pID, float fee, char* s_comments) {
	service_name = new char[MAX_NAME];
    strcpy(service_name, s_name);

    if (code > MAX_SERVICE || code <= 0) {
        // Throw exception
        service_code = 0;
    } else service_code = code;

    provided_date = new char[MAX_DATE];
    strcpy(provided_date, p_date);
    /*
        Check date format here
    */
    logged_date = new char[MAX_DATE];
    strcpy(logged_date, l_date);
    /*
        Check date format here
    */

    if (mID > MAX_ID || mID <= 0) {
        // Throw exception
        memberID = 0;
    } else memberID = mID;

    if (pID > MAX_ID || pID <= 0) {
        // Throw exception
        providerID = 0;
    } else providerID = pID;

    if (fee > MAX_FEE || fee <= 0) {
        //Throw exception
        service_fee = 0.0;
    }
	else service_fee = fee;

	comments = new char[MAX_COMMENT];
	strcpy(comments, s_comments);
}

// Copy Constructor
Service::Service(const Service* To_Add)
{
	if (!To_Add)
		return;

	service_name = new char[MAX_NAME];
	strcpy(service_name, To_Add->service_name);

	service_code = To_Add->service_code;

	provided_date = new char[MAX_DATE];
	strcpy(provided_date, To_Add->provided_date);
	/*
		Check date format here
	*/
	
	logged_date = new char[MAX_DATE];
	strcpy(logged_date, To_Add->logged_date);
	/*
		Check date format here
	*/

	memberID = To_Add->memberID;
	providerID = To_Add->providerID;
	service_fee = To_Add->service_fee;

	comments = new char[MAX_COMMENT];
	strcpy(comments, To_Add->comments);
}

// Destructor
Service::~Service()
{
    //destroy(this);
	if (service_name)
		delete [] service_name;
	if (provided_date)
		delete [] provided_date;
	if (logged_date)
		delete [] logged_date;
	if (comments)
		delete [] comments;
}


// Display this service
int Service::display()
{
	if (!service_name)
		return -1;

	std::cout << "Service Name: " << service_name << std::endl;
	std::cout << "Service ID: " << service_code << std::endl;
	std::cout << "Date Provided: " << provided_date << std::endl;
	std::cout << "Date Logged: " << logged_date << std::endl;
	std::cout << "Member ID: " << memberID << std::endl;
	std::cout << "Provider ID: " << providerID << std::endl;
	std::cout << "Fee: " << service_fee << std::endl;
	std::cout << "Comments: " << comments << std::endl << std::endl;

	return 0;
}

char* Service::getName(){ return service_name; }
int Service::getServID(){ return service_code; }
char* Service::getProvDate(){ return provided_date; }
char* Service::getLogDate(){ return logged_date; }
int Service::getMemberID(){ return memberID; }
int Service::getProviderID(){ return providerID; }
float Service::getFee(){ return service_fee; }
char* Service::getComments(){ return comments; }