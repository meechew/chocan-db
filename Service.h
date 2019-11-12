// Header file for services
#include <iostream>

const int MAX_NAME = 21;		// MUST be max of 20 characters
const int MAX_COMMENT = 101;	// MUST be max of 100 characters
const float MAX_FEE = 999.99;	// MUST be less than $999.99
const int MAX_ID = 1000000000;	// MUST be less than 10 digits
const int MAX_SERVICE = 1000000;// MUST be less than 7 digits
const int MAX_DATE = 11;		// MUST be MM-DD-YYYY format

class Service
{
public:
	Service();
	Service(char*, int, char*, char*, int, int, float, char*);
	~Service();
	int Display();

protected:
	char* service_name;
	int service_code;
	char* provided_date;
	char* logged_date;
	int memberID;
	int providerID;
	float service_fee;
	char* comments;
};