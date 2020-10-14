#pragma once


//This file is for globally used structures
//Imports of library files

#include <string>



//Header files
//Global variables 
//Structures used

// the structures class holds the structures and has global or
// static variables.

class structures {

public:
    // structure user
    struct User {
        int UserID;
        std::string Username;
        char SingType;
        char Sex;
        int Age;


    };

    // handle Mainuser functions
    static void SetMainUser(User input);
    static structures::User GetMainUser();


private:
    static structures::User MainUser;

};










//Functions definition
//Main code
//Function code
// Status of completion.