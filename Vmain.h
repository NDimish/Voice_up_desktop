#pragma once
// this is the main code class

// imports 
#include "wx/wx.h"
#include <string>
#include "Structures.h"
#include "Import.h"

// namespace

// main menue class runs when called 
class Vmain : public wxFrame
{
private:

public:
	Vmain(const wxString& title);
	~Vmain();

	// variables
	wxButton* ButtonLogin;
	wxPanel* panel;
	wxPanel* pane2;
	wxPanel* pane1;
	wxPanel* panels[13];
	wxBoxSizer* panel_sizer;

	//functions
	void OnExit(wxCommandEvent& event);
	void LoginMain(wxCommandEvent& event);
	void VoiceTuner(wxCommandEvent& event);


	DECLARE_EVENT_TABLE()

};






// login frame 1

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


// login frame 2
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


	DECLARE_EVENT_TABLE()

};









// Voice tuner frame

class wxPanel;
class TuneRemote : public wxPanel
{

private:

public:
	TuneRemote(wxPanel*parent);
	//variables
	wxPanel* m_parent;
	wxButton* note_up;
	wxButton* note_down;
	wxButton* octave_up;
	wxButton* octave_down;


};


class wxPanel;
class Light_screen :public wxPanel
{
private:

public:
	Light_screen(wxPanel* parent);
	//variables
	wxPanel* m_parent;
	wxButton* play_note;
	//lights set 1
	// light set 2
};

//class wxPanel;

class Voice_Tuner_frame : public wxFrame
{
private:

public:
	//variables
	TuneRemote* Remote;
	Light_screen* Lights;
	wxPanel* setting;
	// contructor
	Voice_Tuner_frame(const wxString& title);


	DECLARE_EVENT_TABLE()
};


















///button ids
enum {
	login = wxID_HIGHEST + 1, VoiceTunerID, Tests, Lessons, Graphing, Exit,
	UserButton, UserButton1, UserButton2, UserButton3, Save, Register, F, M,
	NoteUp, NoteDown, OctaveUp, OctaveDown
};



