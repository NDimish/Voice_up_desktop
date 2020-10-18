
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
	//Login::MainUser = new User();

}

Login::~Login()
{
}




//The function below simiply get the usernames from an Sql Database
// Then send the names to the GUI to pring button
void Login::GetNames(std::string names[]) {
	//errotrlog open
	std::ofstream ErrorLog2;
	ErrorLog2.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	ErrorLog2 << "\n\nLogin Getnames ============================================================\n\n";

	NSQL Getnames;
	std::string sqlout;
	std::string temp;
	Getnames.Connect();
	if (1 != Getnames.statement((SQLCHAR*)"SELECT Username FROM Users ", sqlout)) {
		ErrorLog2 << "\n\n COLUD NOT DO STATEMENT FOR LOGIN GETNAMES \n\n";
		Getnames.Disconnect_from_sql();
		ErrorLog2.close();
		return;
	}
	else {
		for (int i = 0; i < sqlout.length()+1; i++) {
			if ( i%8 ==0 && i>0) {
				temp += sqlout[i];
				names[(i/8)-1] = temp;
				temp = "";
				ErrorLog2 << "names written\n";

			}
			else {
				temp += sqlout[i];
				ErrorLog2 << "temp written\n";
			}

		}
	}

	Getnames.Disconnect_from_sql();
	ErrorLog2.close();
}
 


// Status of completion null


// saves new user
 void Login::saveuser(structures::User output) {

	 // forr error logging
	 std::ofstream ErrorLog2;
	 ErrorLog2.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	 ErrorLog2 << "\n\nLogin svae user ============================================================\n\n";

	NSQL temp;
	temp.Connect();
	temp.statementW((SQLCHAR*)"INSERT INTO dbo.Users([UserID],[Username],[Sex],[Sing_Type],[Age]) VALUES (?,?,?,?,?)", output);
	temp.Disconnect_from_sql();
	// setting this as main user
	structures::SetMainUser(output);
	structures::User x;
	x = structures::GetMainUser();
	ErrorLog2 << x.Username;
	ErrorLog2 << "\n\nLogin svae user end ============================================================\n\n";
	ErrorLog2.close();
}
// Status of completion done



 // sets Main user
 void Login::SetMainUser(int ID) {


	 // errorlogging
	 std::ofstream ErrorLog2;
	 ErrorLog2.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	 ErrorLog2 << "\n\nLogin setuser ============================================================\n\n";

	 // structers::setmainuser, actualy set the user this is just for choosinf which user
	 // get user name
	 structures::User setting;
	 NSQL open;
	 open.Connect();
	 switch (ID) {
	 case 1:
		 if (1 == open.statement((SQLCHAR*)"SELECT * FROM Users WHERE UserID = 1", setting))
			 structures::SetMainUser(setting);
		 else
			 return;
		 break;


	 case 2:
		 if (1 == open.statement((SQLCHAR*)"SELECT * FROM Users WHERE UserID = 2", setting))
			 structures::SetMainUser(setting);
		 else
			 return;
		 break;


	 case 3:
		 if (1 == open.statement((SQLCHAR*)"SELECT * FROM Users WHERE UserID = 3", setting))
			 structures::SetMainUser(setting);
		 else
			 return;
		 break;


	 case 4:
		 if (1 == open.statement((SQLCHAR*)"SELECT * FROM Users WHERE UserID = 4", setting))
			 structures::SetMainUser(setting);
		 else
			 return;
		 break;

	 }
	 open.Disconnect_from_sql();

	 // errorlogging
	 structures::User test = structures::GetMainUser();
	 ErrorLog2 << test.Username;
	 ErrorLog2 << "\n\nLogin set user end ============================================================\n\n";
	 ErrorLog2.close();

 }
 //done