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

	

public:
	// variable
	//static User MainUser;
	Login();
	~Login();

	// functions
	static void GetNames(std::string names[]);
	static void saveuser(structures::User output);
	//setsmainuser
	static void SetMainUser(int ID);

};

//Function code
// Status of completion NO
