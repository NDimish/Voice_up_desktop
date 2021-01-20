#pragma once
// this is the main code class

// imports 
#include "wx/wx.h"
#include <string>
#include "Structures.h"
#include "Import.h"
#include "led.h"
#include<thread>

// namespace

class Graph_frames;
class Voice_Tuner_frame;
class Error_screens;
class Voice_Tests_frame;
class login_frame_a;
// main menue class runs when called 
class Vmain : public wxFrame
{
private:
	// variables
	wxButton* ButtonLogin;
	wxPanel* panel;
	wxPanel* pane2;
	wxPanel* pane1;
	wxPanel* panels[13];
	wxBoxSizer* panel_sizer;

	wxPanel* bob;
	// other module classes

	Voice_Tuner_frame* Voicetune;
	Error_screens* Error;
	Voice_Tests_frame* tester;
	Voice_Tests_frame* Lesson;
	Graph_frames* Graph;
	login_frame_a* login1;


	
public:
	Vmain(const wxString& title);
	~Vmain();


	//functions
	void OnExit(wxCommandEvent& event);
	void LoginMain(wxCommandEvent& event);
	void VoiceTuner(wxCommandEvent& event);
	void Voice_Tests(wxCommandEvent& event);
	void Voice_Lessosn(wxCommandEvent& event);
	void Graphing__(wxCommandEvent& event);
	


	DECLARE_EVENT_TABLE()

};





//login =======================================================================

// login frame 1 -------------------------------------

class login_frame_a : public wxFrame
{
private:

public:
	// contructor
	login_frame_a(const wxString& title);
	// code below is for login b id
	int IDnum;
	void User1(wxCommandEvent& event);
	void User2(wxCommandEvent& event);
	void User3(wxCommandEvent& event);
	void User4(wxCommandEvent& event);
	void Registering(wxCommandEvent& event);
	void OnExit();

	DECLARE_EVENT_TABLE()

};


// login frame 2--------------------------------------
class login_frame_b : public wxFrame
{
private:
	structures::User newUser;
	int errorchk = 0;

	// buttons and panels( as many functions use them to get inputs.
	wxPanel* login_b;
	wxTextCtrl* TextboxUsername;
	int Male = 0 ;
	int Female = 0;

	wxArrayString voice_types;
	wxComboBox* DropdownSing_Type;
	wxComboBox* DropdownAge_Tens;
	wxComboBox* DropdownAge_Units;
	// this is for making id number
	int IDnum;

public:
	// constructor
	login_frame_b(const wxString& title, int Idnum);

	//functions
	// save user
	void SaveNewUser(wxCommandEvent& event);
	void OutputError(wxStaticText* st5);
	// ensure one toggle
	void Togglechange(wxCommandEvent& event);
	void TogglechangeF(wxCommandEvent& event);
	//exit
	void OnExit(wxCommandEvent& event);


	DECLARE_EVENT_TABLE()

};









// Voice tuner frame=======================================================================

// frame classes ----------------------------------------


//light screen----------------------------
class wxPanel;
class Light_screen :public wxPanel
{
private:
	//variablesWidgits
	wxPanel* m_parent;
	wxButton* play_note;
	//lights set 1
	wxLed* Lightset1[4];

	// light set 2
	wxLed* Lightset2[4];

	// if the note is the same dont refresh lights counter
	int Lightson;
public:
	Light_screen(wxPanel* parent);
	
	
	float Notefrequency;
	char Notename;
	//int notenumber;
	bool exit;

	//functions
	// below plays the note once

	// below change parameters when ready
	void Lights(int lightsnum);
	void playingnote(wxCommandEvent& event);
};





// remote------------------------
// declare the line: class function above code not working if link error 1141 appears
//like so
class wxPanel;
class TuneRemote : public wxPanel
{

private:
	//variables widgits
	wxFrame* frame;
	wxPanel* m_parent;
	wxButton* note_up;
	wxButton* note_down;
	wxButton* octave_up;
	wxButton* octave_down;
	wxStaticText* Note;
	std::string notename;
	std::thread* Toclose;

public:
	TuneRemote(wxPanel* parent, Light_screen* lights, std::thread* thread);
	// variables
	int octaveid;
	int noteid;
	Light_screen* LightScreen;

	//functions
	void Change_note_up(wxCommandEvent& event);
	void Change_note_Down(wxCommandEvent& event);
	void Change_Octave_up(wxCommandEvent& event);
	void Change_Octave_Down(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	// no events
	void OnExit();
	void setframe(wxFrame* frame_m);


};






//mainframe for voice tuner ---------------------------

//class wxPanel;

class Voice_Tuner_frame : public wxFrame
{
private:
	//variables widgits
	TuneRemote* Remote;
	Light_screen* Lights;
	wxPanel* setting;
public:
	
	// contructor
	Voice_Tuner_frame(const wxString& title);
	void OnExit();


	DECLARE_EVENT_TABLE()
};












// Tests frames=======================================================================

class Voice_Tests_frame : public wxFrame{
private:
	wxScrolledWindow* Testroller;
	structures::Block testgame[20];

public:
	Voice_Tests_frame(const wxString& title);
	//functions
	void OnExit(wxCommandEvent& event);
	void TestRun(wxCommandEvent& event);
	// no events
	void OnExit();

};


//-------------------

// game class
class Voice_game:public wxFrame {

private:
	wxPanel* Gamepanel;

public:
	Voice_game(int DataID);
	void RunExitScoreWindow(int score);
	void OnExit(wxCommandEvent& event);
};

//=============================================













// graph frames=======================================================================
class Graph_frames: public wxFrame {
private:
	wxPanel* Main_panel;
	wxButton* Buttonset[6];
	wxButton* ButtonExit;
	//wxButton* ButtonExit2;
	wxStaticText* title;

	// holds what screen and the selection per screen
	int current_screen;
	int selection[2];
	// for testing int b;
public:
	Graph_frames(const wxString& title);
	void Set_buttons(bool firstIntialize = false);
	//void test(wxCommandEvent& event);
	// button event stuff
	void Buttonevent1(wxCommandEvent& event);
	void Buttonevent2(wxCommandEvent& event);
	void Buttonevent3(wxCommandEvent& event);
	void Buttonevent4(wxCommandEvent& event);
	void Buttonevent5(wxCommandEvent& event);
	void Buttonevent6(wxCommandEvent& event);
	void Back(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	// no events
	void OnExit();

	DECLARE_EVENT_TABLE()

};













///button ids
/// // global file variable
// Below is the coulouring for the background
enum {
	login = wxID_HIGHEST + 1, VoiceTunerID, Tests, Lessons, Graphing, Exit,
	UserButton, UserButton1, UserButton2, UserButton3, Save, Register, F, M,
	NoteUp, NoteDown, OctaveUp, OctaveDown, Noteplay, Exit_error,Back_screen, onwards
};


// error screen======================
// for quick error screen, back round colour in constructor all else is in particular constructor
class Error_screens:wxFrame {
private:

	// for the error screen
	wxFrame* error;
	wxButton* exit;
	bool check;

public:

	

	// functions
	Error_screens(int choice);
	// for the error screen
	void Check_Mainuser_active();
	void close_error(wxCommandEvent& event);
	bool Get_check();

	// function for error log
	static void Error_log(std::string input, int x[]);

	static void Error_log(std::string input);
	static void Error_log(int input);


};

