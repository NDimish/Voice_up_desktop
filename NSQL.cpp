// the functions for the NSQL class
#include "Import.h"

// completion:: Working, still need to format for other data types.

// definitions
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000


//functions:

// constructor
 NSQL::NSQL() {
     //errotrlog open
     ErrorLog.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
}

 //deconstructor

NSQL:: ~NSQL() {
    //errotrlog close
    Disconnect_from_sql();
    ErrorLog.close();
 }


// connect to server give pass or fail
int NSQL::Connect() {
    ErrorLog << "NSQL loading ======================================================================================================\n\n";
    //lol

    //initializations
    sqlConnHandle = NULL;
    sqlStmtHandle = NULL;

    //allocations
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle)) {
        NSQL::Disconnect_from_sql(); ErrorLog << "problem1\n";
    }

    if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) {
        NSQL::Disconnect_from_sql(); ErrorLog << "problem4\n";
    }
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle)) {
        NSQL::Disconnect_from_sql(); ErrorLog << "problem2\n";
    }

    //output
    //connect to SQL Server  
    //I am using a trusted connection and port 14808
    //it does not matter if you are using default or named instance
    //just make sure you define the server name and the port
    //You have the option to use a username/password instead of a trusted connection
    //but is more secure to use a trusted connection
    int check = 0;
    switch (SQLDriverConnect(sqlConnHandle,
        NULL,
        //(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=master;UID=username;PWD=password;",
        (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=VoiceUp_DBS;Trusted=true;",
        SQL_NTS,
        retconstring,
        1024,
        NULL,
        SQL_DRIVER_NOPROMPT)) {

    case SQL_SUCCESS:
        check = 1;
        break;
    case SQL_SUCCESS_WITH_INFO:
        check = 1;
        break;
    case SQL_INVALID_HANDLE:
        NSQL::Disconnect_from_sql();
        ErrorLog << "f1\n";
        return Fail;
    case SQL_ERROR:
        NSQL::Disconnect_from_sql();
        ErrorLog << "f2\n";
        return Fail;

    default:
        break;
    }

    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle)) {
        NSQL::Disconnect_from_sql();
        ErrorLog << 'f3\n';
        return Fail;
    }
    return Success;
}
// variables from class used


//=====================================================================================================================




// below is the input from sql for a int output 
int NSQL::statement(SQLWCHAR* statement, int output[], int row) {

    ErrorLog << "\nstatement(SQLCHAR* statement, int output[], int row)++++++++++++\n\n";

    // ensures sql worked
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, statement, SQL_NTS)) {
        NSQL::Disconnect_from_sql();
        ErrorLog << "fail in request \n";
        return Fail;
    }

    // If works get data
    else {

        //declare output variable and pointer
        int sqltake;
        int available = 0;
        SQLLEN ptrSqltake;

        // check data is fetched
        if (SQLFetch(sqlStmtHandle) != SQL_SUCCESS) {
            ErrorLog << "fetch fail\n";
            return Fail;
        }

        // the code below is to repeate if a user wants more than one column

        do {
            for (int i = 1; i <= row; i++) {
                // put number in a list
                if (SQL_SUCCESS == SQLGetData(sqlStmtHandle, i, SQL_C_DEFAULT, &sqltake, SQL_RESULT_LEN, &ptrSqltake)) {
                    {
                        if (available == 0 && sqltake != NULL) {
                            output[available] = sqltake;
                            available += 1;
                        }
                        else if (sqltake != NULL) {
                            output[available] = NULL;
                            available += 1;
                            output[available] = sqltake;
                            available += 1;
                        }

                        else
                            return Fail;

                    }
                }
                else
                    ErrorLog << "fail transfer to sqltake\n";

                // if more data to fetch do agian
            }
        } while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS);

    }


    return Success;
}
// temp variables and interger list refrence





//====================================================================================================





// below is the input from sql for a string output 
int NSQL::statement(SQLWCHAR* statement, std::string& output, int row) {
    ErrorLog << "\nstatement(SQLCHAR* statement, std::string& output, int row)++++++++++\n\n";

    // ensures sql worked
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, statement, SQL_NTS)) {
        NSQL::Disconnect_from_sql();
        ErrorLog << "fail in request \n";
        return Fail;
    }
    // If works get data
    else {
        ErrorLog << "True in request \n";
        //declare output variable and pointer
        char sqltake[500];
        SQLLEN ptrSqltake;

        // check data is  fetched
        if (SQLFetch(sqlStmtHandle) != SQL_SUCCESS) {
            ErrorLog << "fetch fail\n";
            return Fail;
        }

        do {
            for (int i = 1; i <= row; i++) {

                if (SQL_SUCCESS == SQLGetData(sqlStmtHandle, i, SQL_C_DEFAULT, &sqltake, SQL_RESULT_LEN, &ptrSqltake)) {
                    for (int i = 0; i < 200; i++) {
                        if (sqltake[i + 1] != NULL)
                            output += sqltake[i];

                        else {
                            output += sqltake[i];
                            break;
                        }
                    }
                }
                else
                    ErrorLog << "fail transfer to sqltake\n";

            }
            // if more data to fetch do agian
        } while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS);


    }
    return Success;

}
// temp variable and string refrence





//=============================================================================================================







// below is the code for inserting data user
int NSQL::statementW(SQLWCHAR* statement, structures::User input) {
    ErrorLog << "\nstatementW(SQLCHAR* statement, User input)++++++++++\n\n";

    // set in all the values (tailored for user)
    //int retcode;
    int Age = input.Age;
    int UserID = input.UserID;
    std::string Username = input.Username;
    std::string Sex;
    Sex += input.Sex;
    std::string Sing_Type;
    Sing_Type += input.SingType;



    // (SQLWCHAR*)L"INSERT INTO dbo.Users([Username]) VALUES (?)"
    if (SQL_SUCCESS == SQLPrepare(sqlStmtHandle, statement, SQL_NTS))
        ErrorLog << "\npassed prepare\n";
    else
    {
        ErrorLog << "fail to prepare\n";
        return Fail;
    }



    // below i bind the parameters
    if (SQL_SUCCESS == SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_LONGVARCHAR, 10, 0, (SQLPOINTER)Username.c_str(), Username.length(), NULL))
        ErrorLog << "pass\n";
    else
    {
        ErrorLog << "fail to insert\n";
        return Fail;
    }


    if (SQL_SUCCESS == SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_LONGVARCHAR, 10, 0, (SQLPOINTER)Sex.c_str(), Sex.length(), NULL))
        ErrorLog << "pass\n";
    else
    {
        ErrorLog << "fail to insert\n";
        return Fail;
    }


    if (SQL_SUCCESS == SQLBindParameter(sqlStmtHandle, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_LONGVARCHAR, 10, 0, (SQLPOINTER)Sing_Type.c_str(), Sing_Type.length(), NULL))
        ErrorLog << "pass\n";
    else
    {
        ErrorLog << "fail to insert\n";
        return Fail;
    }




    if (SQL_SUCCESS == SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &UserID, 0, NULL))
        ErrorLog << "pass\n";
    else
    {
        ErrorLog << "fail to insert\n";
        return Fail;
    }





    if (SQL_SUCCESS == SQLBindParameter(sqlStmtHandle, 5, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &Age, 0, NULL))
        ErrorLog << "pass\n";
    else
    {
        ErrorLog << "fail to insert\n";
        return Fail;
    }






    // ensures sql worked
   // retcode = SQLExecute(sqlStmtHandle);
    if (SQL_SUCCESS != SQLExecute(sqlStmtHandle)) {
        NSQL::Disconnect_from_sql();
        ErrorLog << "fail in request \n";
        return Fail;
    }
    else
        return Success;


}
// temp variables user values


//======================================================================================================================




// below is the statements to recive a whole row of users. you can only get one row
int NSQL::statement(SQLWCHAR* statement, structures::User& output) {
    ErrorLog << "\nstatement(SQLCHAR* statement, User& output)++++++++++\n\n";

    // ensures sql worked
    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, statement, SQL_NTS)) {
        NSQL::Disconnect_from_sql();
        ErrorLog << "fail in request \n";
        return Fail;
    }
    else {
        // check data is fetched
        if (SQLFetch(sqlStmtHandle) != SQL_SUCCESS) {
            ErrorLog << "fetch fail\n";
            return Fail;
        }
        // intialise temp variables for string
        char sqltake[200];
        SQLLEN ptrSqltake;


        if (SQL_SUCCESS == SQLGetData(sqlStmtHandle, 2, SQL_C_DEFAULT, &sqltake, SQL_RESULT_LEN, &ptrSqltake)) {
            for (int i = 0; i < 200; i++) {
                if (sqltake[i + 1] != NULL)
                    output.Username += sqltake[i];

                else
                    break;
            }


        }

        if (SQL_SUCCESS == SQLGetData(sqlStmtHandle, 3, SQL_C_DEFAULT, &sqltake, SQL_RESULT_LEN, &ptrSqltake)) {

            output.Sex = sqltake[0];

        }
        if (SQL_SUCCESS == SQLGetData(sqlStmtHandle, 4, SQL_C_DEFAULT, &sqltake, SQL_RESULT_LEN, &ptrSqltake)) {

            output.SingType = sqltake[0];

        }

        // getting intergers
        int sqltakei;
        SQLLEN ptrSqltakei;
        if (SQL_SUCCESS == SQLGetData(sqlStmtHandle, 1, SQL_C_DEFAULT, &sqltakei, SQL_RESULT_LEN, &ptrSqltakei)) {

            output.UserID = sqltakei;

        }

        if (SQL_SUCCESS == SQLGetData(sqlStmtHandle, 5, SQL_C_DEFAULT, &sqltakei, SQL_RESULT_LEN, &ptrSqltakei)) {

            output.Age = sqltakei;
        }
        else {
            ErrorLog << "faliure in users copy";
            return Fail;

        }
    }

    return Success;

}
// temp variable user refrence 



//=========================================================================================================



// disconnect from server
void NSQL::Disconnect_from_sql() {
    ErrorLog << "\nNSQL::Disconnect_from_sql()++++++++++\n\n";

    SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
    SQLDisconnect(sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);

    ErrorLog << "\n\nNSQL finished ======================================================================================================\n\n";


    // close errorlog
    ErrorLog.close();
}
// class variables

