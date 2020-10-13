#pragma once
//This is the login class flie

//Imports of library files
#include "Vmain.h"

//Header files
#include "Import.h"
//Global variables 
//Structures used
//Functions definition


//Main code
class Login
{
private:

	User MainUser;

public:
	Login();
	~Login();

	// functions
	static void GetNames();
	static void saveuser(User output);

};

//Function code
// Status of completion NO
