// launch source code

//imports

//header files
#include "Voice_up_launch.h"
#include "Vmain.h"

// creating wx-widgits version of int main

wxIMPLEMENT_APP(Voice_up_launch);// macro to crerat application of inctance


// code

// constructor and deconstructor

Voice_up_launch::Voice_up_launch() {}
Voice_up_launch::~Voice_up_launch() {}

// functions


/* function uses variables: 
Voice_up_launchger::Vmain*start frames
*/
bool Voice_up_launch::OnInit() {// create  frame instance

	start_frames = new Vmain("Voice_up launcher");//( default constructor made already)
	start_frames->Show();//show pointer window
	SetTopWindow(start_frames);// set it as the main window

	return true;
}


