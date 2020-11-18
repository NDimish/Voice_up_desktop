#pragma once
// this is the main code class

// imports 
#include "wx/wx.h"
#include <string>
#include "Structures.h"
#include "Import.h"
#include "led.h"

// namespace

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
	// ensure one toggle
	void Togglechange(wxCommandEvent& event);
	void TogglechangeF(wxCommandEvent& event);
	//exit
	void OnExit(wxCommandEvent& event);


	DECLARE_EVENT_TABLE()

};









// Voice tuner frame=======================================================================

// frame classes ----------------------------------------

// remot------------------------
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

public:
	TuneRemote(wxPanel*parent);
	// variables
	int octaveid;
	int noteid;

	//functions
	void Change_note_up(wxCommandEvent& event);
	void Change_note_Down(wxCommandEvent& event);
	void Change_Octave_up(wxCommandEvent& event);
	void Change_Octave_Down(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void setframe(wxFrame* frame_m);


};



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
public:
	Light_screen(wxPanel* parent);
	
	
	int Notefrequency;
	char Notename;
	int lightsnum;

	//functions
	// below plays the note once

	// below change parameters when ready
	void Lights();
	void playingnote(wxCommandEvent& event);
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
	void OnExit(wxCommandEvent& event);


	DECLARE_EVENT_TABLE()
};












// Tests frames=======================================================================

class Voice_Tests_frame : public wxFrame {
private:
	wxPanel* TestrollPanel;

public:
	Voice_Tests_frame(const wxString& title);
};

//==













// graph frames=======================================================================
class Graph_frames: public wxFrame {
private:
	wxPanel* Main_panel;
	wxButton* Buttonset[6];
	wxButton* ButtonExit;
	int current_screen;
	int selection[2];
	// for testing int b;
public:
	Graph_frames(const wxString& title);
	void Set_buttons();
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

	DECLARE_EVENT_TABLE()

};













///button ids
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


};

