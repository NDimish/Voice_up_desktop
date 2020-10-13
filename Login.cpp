
//The source code for the header file login backend
//Imports of library files
#include <iostream>
//#include "sqlite3.h"
//Header files
#include "Login.h"
//Global variables 
//Structures used
//Functions definition
//Main code
//Function code
Login::Login() {

}




// 
void Login::GetNames() {

	
}
//The function above simiply get the usernames from an Sql Database
// Then send the names to the GUI to pring buttons 


// Status of completion null


// saves new user
 void Login::saveuser(User output) {
	NSQL temp;
	temp.Connect();
	temp.statementW((SQLCHAR*)"INSERT INTO dbo.Users([UserID],[Username],[Sex],[Sing_Type],[Age]) VALUES (?,?,?,?,?)", output);
	temp.Disconnect_from_sql();
}
// Status of completion done

