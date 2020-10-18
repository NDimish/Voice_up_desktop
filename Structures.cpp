// this is the code for the structures class
//import 
#include "Structures.h";
#include "Import.h"

// code
// global(ststic) variables
structures::User structures::MainUser;


// set the mainuser
void structures::SetMainUser(structures::User input) {
	// for error log
	std::ofstream ErrorLog;
	ErrorLog.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	structures::MainUser = input;
	ErrorLog << "Main user is set to" << structures::MainUser.Username;
	ErrorLog.close();
}
//done

// get the main user
structures::User structures::GetMainUser() {
	return structures::MainUser;
}
//done
