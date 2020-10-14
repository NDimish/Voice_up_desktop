
#include "Vmain.h"
#include <fstream>
#include "Login.h"
#include "string"
#include "Structures.h"
#include <wx/tglbtn.h>
#include "Import.h"


// source code for main program class

// purple function consts

// below includes the eventtable which says what happens when each button is pressed






// Menu GUI 
BEGIN_EVENT_TABLE(Vmain, wxFrame)
EVT_BUTTON(login, Vmain::LoginMain)
EVT_BUTTON(Exit, Vmain::OnExit)
END_EVENT_TABLE()



// constructor deconstructor

Vmain::Vmain(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxPoint(40, 30), wxSize(250, 450))
{
	// main user created 
	Login *Userinuse = new Login();


	// panels
	//for (int i = 0; i < 13; i++) {
		//panels[i] = new wxPanel(this, wxID_HIGHEST + 1 + i);
		//panel_sizer->Add(panels[i]);
		//panels[i]->Hide();
	//}

	// colours 
	//wxColour col1, col2;
	//col1.Set(wxT("#4f5049"));
	//col2.Set(wxT("#ededed"));
  //button sizer
	//panel_sizer = new wxBoxSizer(wxHORIZONTAL);
	//pane1 = new wxPanel(this, wxID_ANY);

		//pane1->SetBackgroundColour(col1);
	// pane2 = new wxPanel(panel, wxID_ANY);
	// pane2->SetBackgroundColour(col2);
	// panel_sizer->Add(pane2);// makes panel 20 smaller than window so if any panel behind is shown
	// panel_sizer->Add(pane1);
	// panel_sizer->Hide(pane2);
	// panel_sizer->Show(pane1);
	//panel_sizer->Add(pane1,1, wxEXPAND );
	//panel_sizer->Add(panel, 1, wxEXPAND);
	//panel_sizer->Hide(pane1);
	//panel_sizer->Show(panel);
	//panel_sizer->Show(pane1);
	//panel_sizer->Hide(panel);

		//wxButton* ButtonUser = new wxButton(pane1, wxID_ANY, _T("User"), wxPoint(50, 100), wxDefaultSize, 0)
	//button_sizer->Add(ButtonLogin);
	//main_sizer->Add(button_sizer, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);
	//pane1->SetSizer(panel_sizer);
	//panel_sizer->Layout();
  // intialise buttons help
	// text box
	//menubar
	// statusbar
	// this is the code for main menue, run when app opens


	// panel on a window with all the buttons that go to modules
	wxColour purp;
	purp.Set(wxT("#C311D6"));
	wxColour oj;
	oj.Set(wxT("#F99910"));
	wxColour red;
	red.Set(wxT("#D92C2C"));

	panel = new wxPanel(this, wxID_ANY);
	panel->SetBackgroundColour(purp);

	ButtonLogin = new wxButton(panel, login, _T("Login"), wxPoint(34, 10), wxSize(175, 40), 0);
	ButtonLogin->SetBackgroundColour(red);

	wxButton* ButtonVoiceTuner;
	ButtonVoiceTuner = new wxButton(panel, VoiceTuner, _T("Voice Tuner"), wxPoint(34, 30), wxSize(175, 40), 0);
	ButtonVoiceTuner->SetBackgroundColour(oj);

	wxButton* ButtonTests;
	ButtonTests = new wxButton(panel, Tests, _T("Singing Tests"), wxPoint(34, 50), wxSize(175, 40), 0);
	ButtonTests->SetBackgroundColour(oj);

	wxButton* ButtonLessons;
	ButtonLessons = new wxButton(panel, Lessons, _T("Singing Lessons"), wxPoint(34, 70), wxSize(175, 40), 0);
	ButtonLessons->SetBackgroundColour(oj);

	wxButton* ButtonGraphing;
	ButtonGraphing = new wxButton(panel, Graphing, _T("Progress"), wxPoint(34, 90), wxSize(175, 40), 0);
	ButtonGraphing->SetBackgroundColour(oj);

	wxButton* ButtonExit;
	ButtonExit = new wxButton(panel, Exit, _T("Exit"), wxPoint(34, 110), wxSize(175, 40), 0);
	ButtonExit->SetBackgroundColour(red);


	// below is the sizer, setting as blank, button, letter

	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

	wxFlexGridSizer* SizerMenu = new wxFlexGridSizer(7, 3, 20, 10);
	SizerMenu->Add(new wxSizerItem);
	SizerMenu->Add(ButtonLogin, 1, wxALL | wxEXPAND);
	SizerMenu->Add(new wxStaticText(panel, -1, wxT("V")), 1, wxEXPAND);
	SizerMenu->Add(new wxSizerItem);
	SizerMenu->Add(ButtonVoiceTuner, 1, wxALL | wxEXPAND);
	SizerMenu->Add(new wxStaticText(panel, -1, wxT("O")), 1, wxEXPAND);
	SizerMenu->Add(new wxSizerItem);
	SizerMenu->Add(ButtonTests, 1, wxALL | wxEXPAND);
	SizerMenu->Add(new wxStaticText(panel, -1, wxT("I")), 1, wxEXPAND);
	SizerMenu->Add(new wxSizerItem);
	SizerMenu->Add(ButtonLessons, 1, wxALL | wxEXPAND);
	SizerMenu->Add(new wxStaticText(panel, -1, wxT("C")), 1, wxEXPAND);
	SizerMenu->Add(new wxSizerItem);
	SizerMenu->Add(ButtonGraphing, 1, wxALL | wxEXPAND);
	SizerMenu->Add(new wxStaticText(panel, -1, wxT("E")), 1, wxEXPAND);
	SizerMenu->Add(new wxSizerItem);
	SizerMenu->Add(ButtonExit, 1, wxALL | wxEXPAND);
	SizerMenu->Add(new wxStaticText(panel, -1, wxT("U\nP")), 1, wxEXPAND);

	SizerMenu->AddGrowableCol(2);
	//SizerMenu->AddGrowableRow(2, 1);
	//SizerMenu->AddGrowableCol(1, 1);
	//SizerMenu->AddGrowableRow(1, 1);
	//SizerMenu->AddGrowableCol(3, 1);
	//SizerMenu->AddGrowableRow(3, 1);

	hbox->Add(SizerMenu, 1, wxALL | wxEXPAND, 15);
	panel->SetSizer(hbox);
	Centre();
}



Vmain::~Vmain() {}


//functions
void Vmain::OnExit(wxCommandEvent& event) {
	Close(true); // closes the program
}

void Vmain::LoginMain(wxCommandEvent& event) {
	//panel_sizer->Hide(pane2);
	//panel_sizer->Show(pane1);
	login_frame_a* login = new login_frame_a("login screen 1");
	login->Show();
	//SetTopWindow(login);
}



// Main end -------------------------------



//Login screen -------------------------


// temp frame class

/// login screen A
/// // login a event table

BEGIN_EVENT_TABLE(login_frame_a, wxFrame)
EVT_BUTTON(Register, login_frame_a::Registering)
EVT_BUTTON(UserButton, login_frame_a::User1)
EVT_BUTTON(UserButton1, login_frame_a::User2)
EVT_BUTTON(UserButton2, login_frame_a::User3)
EVT_BUTTON(UserButton3, login_frame_a::User4)
END_EVENT_TABLE()

login_frame_a::login_frame_a(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxPoint(30, 40), wxSize(300, 200))
{// get names

	// =============================== edit to button

	// below is the code to output the user buttons in order
	wxButton* Button[4];
	//panel
	wxPanel* login_a = new wxPanel(this, wxID_ANY);
	login_a->SetBackgroundColour(wxT("#C311D6"));
	//title
	wxStaticText* st1 = new wxStaticText(login_a, wxID_ANY, "  Select-User  ", wxPoint(50, 10), wxDefaultSize, wxALIGN_CENTRE);

	std::string Usernames[4];
	std::ofstream ErrorLog1;
	ErrorLog1.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	Login::GetNames(Usernames);
	for (int i = 0; i < 4; i++) {
		if (Usernames[i] == "") {

			wxButton* ButtonRegister = new wxButton(login_a, Register, _T("Register"), wxPoint(10, 30*(i+1)+10), wxDefaultSize, 0);
			ErrorLog1 << "\n\nUsernames captcha ============================================================\n\n";
			ErrorLog1 << "No users here\n";
			break;
		}
		else {
			Button[i] = new wxButton(login_a, UserButton+i, Usernames[i] , wxPoint(10, 30*(i+1)+10), wxDefaultSize, 0);
			ErrorLog1 << "\n\nUsernames captcha ============================================================\n\n";
			ErrorLog1 << Usernames[i];
		}
	}
	ErrorLog1.close();

	//====================================================== end edit to button

	//std::string* Usernames = Login::GetNames();
	
}



// functions

void login_frame_a::Registering(wxCommandEvent& event) {
	//panel_sizer->Hide(pane2);
	//panel_sizer->Show(pane1);
	Close(true);
	login_frame_b* Register = new login_frame_b("login screen 2");
	Register->Show();
	//SetTopWindow(login);
}

// set user whewn buttons clicked
void login_frame_a::User1(wxCommandEvent& event){

	Close(true);
}

void login_frame_a::User2(wxCommandEvent& event) {

	Close(true);
}

void login_frame_a::User3(wxCommandEvent& event) {

	Close(true);
}

void login_frame_a::User4(wxCommandEvent& event) {

	Close(true);
}



//--------------------------------------------------------------------------

// login frame b code 

// login b event table

BEGIN_EVENT_TABLE(login_frame_b, wxFrame)
EVT_BUTTON(Save, login_frame_b::SaveNewUser)
EVT_TOGGLEBUTTON(M, login_frame_b::Togglechange)
EVT_TOGGLEBUTTON(F, login_frame_b::TogglechangeF)
END_EVENT_TABLE()

login_frame_b::login_frame_b(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxPoint(30, 40), wxSize(300, 250))
{
	//panel
	login_b = new wxPanel(this, wxID_ANY);
	login_b->SetBackgroundColour(wxT("#C311D6"));

	//widgits
	wxButton* ButtonSave = new wxButton(login_b, Save, _T("Save"), wxPoint(50, 160), wxDefaultSize, 0);



	wxStaticText* st1 = new wxStaticText(login_b, wxID_ANY, "Username", wxPoint(10, 10), wxDefaultSize, wxALIGN_CENTRE);
	TextboxUsername = new wxTextCtrl(login_b, wxID_ANY, "hi!", wxPoint(100, 10), wxSize(100, 20), wxTE_MULTILINE | wxTE_RICH, wxDefaultValidator, wxTextCtrlNameStr);



	wxStaticText* st2 = new wxStaticText(login_b, wxID_ANY, "Sex", wxPoint(10, 50), wxDefaultSize, wxALIGN_CENTRE);
	 wxToggleButton* ToggleMale = new wxToggleButton(login_b, M, wxT("Male"), wxPoint(100, 50), wxSize(50, 20));

	 wxToggleButton* ToggleFemale = new wxToggleButton(login_b,F, wxT("Female"), wxPoint(150, 50), wxSize(50, 20));

	// ensures only one button toggled

	// choices for dropdown
	// Create common wxArrayString array
	voice_types.Add(wxT("Soprano"));
	voice_types.Add(wxT("Alto"));
	voice_types.Add(wxT("Tenor"));
	voice_types.Add(wxT("Bass"));
	wxStaticText* st3 = new wxStaticText(login_b, wxID_ANY, "Voice type", wxPoint(10, 80), wxDefaultSize, wxALIGN_CENTRE);
	DropdownSing_Type = new wxComboBox(login_b, wxID_ANY, "Voice_Type", wxPoint(100, 80), wxSize(100,50), voice_types, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX1"));


	// choices for dropdown box 2
	wxArrayString   numbers;
	numbers.Add(wxT("0")); numbers.Add(wxT("1")); numbers.Add(wxT("2")); numbers.Add(wxT("3")); numbers.Add(wxT("4")); numbers.Add(wxT("5")); numbers.Add(wxT("6"));
	numbers.Add(wxT("7")); numbers.Add(wxT("8")); numbers.Add(wxT("9"));

	wxStaticText* st4 = new wxStaticText(login_b, wxID_ANY, "Age         \nTens,Units", wxPoint(10, 110), wxDefaultSize, wxALIGN_CENTRE);
	DropdownAge_Tens = new wxComboBox(login_b, wxID_ANY, "Tens", wxPoint(100, 110), wxSize(50, 20), numbers, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX2"));
	DropdownAge_Units = new wxComboBox(login_b, wxID_ANY, "Units", wxPoint(150, 110), wxSize(50, 20), numbers, wxCB_READONLY, wxDefaultValidator, _T("ID_COMBOBOX3"));
	
	
}




// functions for login screen b

void login_frame_b::SaveNewUser(wxCommandEvent& event) {

	// gets value
	newUser.Username = TextboxUsername->GetValue();
	// checks value is valid 
	if (newUser.Username.length() == 0 || newUser.Username.length() >10) {
		wxStaticText* st5 = new wxStaticText(login_b, wxID_ANY, "Error in your regestration ( Username )", wxPoint(10, 190), wxDefaultSize, wxALIGN_CENTRE);
		if (errorchk == 0) {
			st5->SetBackgroundColour(*wxRED);
			st5->Refresh();;
			errorchk = 1;
		}
		else {
			st5->SetBackgroundColour(*wxGREEN);
			st5->Refresh();;
			errorchk = 0;
		}
		return;
	}



	// validation for toggle
	if (Male ==0 && Female ==0 || Male == 1 && Female == 1) {
		wxStaticText* st5 = new wxStaticText(login_b, wxID_ANY, "Error in your regestration ( Sex )            ", wxPoint(10, 190), wxDefaultSize, wxALIGN_CENTRE);
		if (errorchk == 0) {
			st5->SetBackgroundColour(*wxRED);
			st5->Refresh();;
			errorchk = 1;
		}
		else {
			st5->SetBackgroundColour(*wxGREEN);
			st5->Refresh();;
			errorchk = 0;
		}
		return;
	}
	if (Male == 0)
		newUser.Sex = 'F';
	else
		newUser.Sex = 'M';





	// checks dropdown choosen
	if ((char)DropdownSing_Type->GetCurrentSelection() == 'ÿ') {
		wxStaticText* st5 = new wxStaticText(login_b, wxID_ANY, "Error in your regestration ( Sing )          ", wxPoint(10, 190), wxDefaultSize, wxALIGN_CENTRE);
		if (errorchk == 0) {
			st5->SetBackgroundColour(*wxRED);
			st5->Refresh();;
			errorchk = 1;
		}
		else {
			st5->SetBackgroundColour(*wxGREEN);
			st5->Refresh();;
			errorchk = 0;
		}
		return;
	}
	// set dropdown choice
	int x = DropdownSing_Type->GetCurrentSelection();
	wxString y = voice_types[x];
	newUser.SingType = y[0];

	

	// validation for age input
	if ((char)DropdownAge_Tens->GetCurrentSelection() == 'ÿ' || (char)DropdownAge_Units->GetCurrentSelection() == 'ÿ') {
		wxStaticText* st5 = new wxStaticText(login_b, wxID_ANY, "Error in your regestration ( Age )           ", wxPoint(10, 190), wxDefaultSize, wxALIGN_CENTRE);
		if (errorchk == 0) {
			st5->SetBackgroundColour(*wxRED);
			st5->Refresh();;
			errorchk = 1;
		}
		else {
			st5->SetBackgroundColour(*wxGREEN);
			st5->Refresh();;
			errorchk = 0;
		}
		return;
	}
	// formatting input
	x = DropdownAge_Tens->GetCurrentSelection();
	newUser.Age = x * 10;
	x = DropdownAge_Units->GetCurrentSelection();
	newUser.Age += x;



	//wxStaticText* st5 = new wxStaticText(login_b, wxID_ANY,(char)newUser.Age , wxPoint(70, 190), wxDefaultSize, wxALIGN_CENTRE);
	//st5->Refresh();

	// below saves user
	newUser.UserID = 1;
	Login::saveuser(newUser);
	//Login::MainUser = &newUser;
	Close(true);
}

//toggle change temp
void login_frame_b::Togglechange(wxCommandEvent& event) {
	if (Male == 0)
		Male = 1;
	else
		Male = 0;
}

void login_frame_b::TogglechangeF(wxCommandEvent& event) {
	if (Female == 0)
		Female = 1;
	else
		Female = 0;
}


