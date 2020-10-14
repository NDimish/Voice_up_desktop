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

	//function
	void OnExit(wxCommandEvent& event);
	void LoginMain(wxCommandEvent& event);


	DECLARE_EVENT_TABLE()

};






// login frame 1

class login_frame_a : public wxFrame
{
private:

public:
	login_frame_a(const wxString& title);
	void Registering(wxCommandEvent& event);
	void User1(wxCommandEvent& event);
	void User2(wxCommandEvent& event);
	void User3(wxCommandEvent& event);
	void User4(wxCommandEvent& event);

	DECLARE_EVENT_TABLE()

};


// login frame 2
class login_frame_b : public wxFrame
{
private:
	structures::User newUser;
	int errorchk = 0;

	wxPanel* login_b;
	wxTextCtrl* TextboxUsername;
	int Male = 0 ;
	int Female = 0;

	wxArrayString voice_types;
	wxComboBox* DropdownSing_Type;
	wxComboBox* DropdownAge_Tens;
	wxComboBox* DropdownAge_Units;

public:
	login_frame_b(const wxString& title);

	//functions
	// save user
	void SaveNewUser(wxCommandEvent& event);
	// ensure one toggle
	void Togglechange(wxCommandEvent& event);
	void TogglechangeF(wxCommandEvent& event);


	DECLARE_EVENT_TABLE()

};








// Class for structures



///button ids
enum {
	login = wxID_HIGHEST + 1, VoiceTuner, Tests, Lessons, Graphing, Exit, 
	UserButton, UserButton1, UserButton2, UserButton3,  Save, Register,F,M
};



