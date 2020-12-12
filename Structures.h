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
    // Structure for the moving block in tests module 
    struct Block {
        int Notenum;
        std::string Notename;
        int frequency;
        int length;
        int NextNoteTime;
        std::string Word;
    };

    // handle Mainuser functions
    static void SetMainUser(User input);
    static structures::User GetMainUser();

    // for checking what open
    static void SetOpenWindows(int window,bool status = true);
    static bool GetOpenwindows(int window);




private:
    // mainUser
    static structures::User MainUser;
    // function deemed invalid check windoe open or closed
    static bool OpenWindows[5];
    

};










//Functions definition
//Main code
//Function code
// Status of completion.