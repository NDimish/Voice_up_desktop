// this is the code for the structures class
//import 
#include "Structures.h";
#include "Import.h"

// code
// global(ststic) variables
structures::User structures::MainUser;
bool structures::OpenWindows[5];


// set the mainuser
void structures::SetMainUser(structures::User input) {
	// for error log
	std::ofstream ErrorLog;
	ErrorLog.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	structures::MainUser = input;
	ErrorLog << "Main user is set to " << structures::MainUser.Username<<"\n";
	ErrorLog.close();
}
//done

// get the main user
structures::User structures::GetMainUser() {
	return structures::MainUser;
}
//done


/*// get defualterrror log values
int* structures::Get_errorlogDefaultvalue(){
	errorlogDefaultvalue[0] = -1;
	errorlogDefaultvalue[1] = -1;
	errorlogDefaultvalue[2] = -1;
	return errorlogDefaultvalue;

}
*/

// set the open windows
void structures::SetOpenWindows(int window, bool status) {

	switch (window){

	case 0:
		structures::OpenWindows[0] = status;
		break;
	case 1:
		structures::OpenWindows[1] = status;
		break;
	case 2:
		structures::OpenWindows[2] = status;
		break;
	case 3:
		structures::OpenWindows[3] = status;
		break;
	case 4:
		structures::OpenWindows[4] = status;
		break;
	default:
		structures::OpenWindows[0] = false;
		structures::OpenWindows[1] = false;
		structures::OpenWindows[2] = false;
		structures::OpenWindows[3] = false;
		structures::OpenWindows[4] = false;
	}


}

//get the open windows
bool structures::GetOpenwindows(int window) {

	return structures::OpenWindows[window];
}



