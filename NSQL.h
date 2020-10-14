#pragma once
/* To use this class one must first connect, stament the disconnect*/


#include "Import.h"

// structure test


#define Success 1
#define Fail 2
class NSQL
{
private:
    // handles constatnts for sql
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

    //define handles and variables
    SQLHANDLE sqlEnvHandle;
    SQLHANDLE sqlConnHandle;
    SQLHANDLE sqlStmtHandle;
    SQLCHAR retconstring[SQL_RETURN_CODE_LEN];
    
    // error logging
    std::ofstream ErrorLog;
    

    // functions

public:
    NSQL();
    ~NSQL();
    // connects to database
    int Connect();
    //dissconnect from data base
    void Disconnect_from_sql();
    // get statement data for ints, can get multiple
    // if multiple column ints are set as pairs
    // numbers split by 0
    int statement(SQLCHAR* statement, int output[], int row = 1);
    // gets statement data for strings, can get multiple
    // if multiple column string are set as pairs
    // every string is the max len staored in sql for that string
    int statement(SQLCHAR* statement, std::string& output, int row = 1);


    // the statement below is to insert data for user
    int statementW(SQLCHAR* statement, structures::User input);
    //gets entire row for user, can only get one row
    int statement(SQLCHAR* statement, structures::User& output);
    // 

};
