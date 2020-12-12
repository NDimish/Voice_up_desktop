//This is the source code for test backend
//Imports of library files
//Header files
#include "Tests_backend.h"
//Global variables 
//Structures used
//Functions definition
//Function code

void Tests_backend::Get_tests_names(std::string* check) {
	//errotrlog open
	std::ofstream ErrorLog2;
	ErrorLog2.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	ErrorLog2 << "\n\nTests Getnames ============================================================\n\n";

	// Below is the variable storing all the row value in an unorderd string
	std::string SQLRAW;
	// NSQL object
	NSQL SQLObj;
	if (1 == SQLObj.Connect()) {
		if (1 != SQLObj.statement((SQLWCHAR*)L"SELECT TestsName FROM TestData ", SQLRAW)) {
			SQLObj.Disconnect_from_sql();
		}
		else
			ErrorLog2 << "fail2";
	}
	else
		ErrorLog2 << "fail1";
	ErrorLog2 << SQLRAW;

	// below is spliting sql raw input into an array. check is the array;
	//number is where in the array
	// temp is temp storage
	//std::string check[21];
	std::string temp;
	int number = 0;
	for (int i = 1; i < SQLRAW.length() + 1; i++) {
		if (SQLRAW[i] == '|') {
			check[number] = temp;
			number += 1;
			temp = "";
		}
		else {
			temp += SQLRAW[i];
			continue;
		}
	}
	check[number] = temp;
	ErrorLog2 << "\n";
	for (int i = 0; i < 21; i++) {
		ErrorLog2 << check[i] << i << "\n";
	}

	ErrorLog2 << "Tests Getnames END ==========================================";
	ErrorLog2.close();

};


// need editing need to ensure you can sub in TestsID
structures::Block* Tests_backend::Get_test_data(int TestID) {
	return NULL;
	//errotrlog open
	std::ofstream ErrorLog2;
	ErrorLog2.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	ErrorLog2 << "\n\nTests Getnames ============================================================\n\n";

	// Below is the variable storing all the row value in an unorderd string
	std::string SQLRAW;
	// NSQL object
	NSQL SQLObj;
	if (1 == SQLObj.Connect()) {
		if (1 != SQLObj.statement((SQLWCHAR*)(L"SELECT TestsData FROM TestData WHERE TestID = " + TestID), SQLRAW)) {
			SQLObj.Disconnect_from_sql();
		}

		else
			ErrorLog2 << "fail2";
	}
	else
		ErrorLog2 << "fail1";
	ErrorLog2 << SQLRAW;
};

