// this is the code for the structures class
//import 
#include "Structures.h";

// code
// global(ststic) variables
structures::User structures::MainUser;


// set the mainuser
void structures::SetMainUser(structures::User input) {
	structures::MainUser = input;
}
//done

// get the main user
structures::User structures::GetMainUser() {
	return structures::MainUser;
}
//done
