//imports
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
EVT_BUTTON(VoiceTunerID, Vmain::VoiceTuner)
EVT_BUTTON(Tests, Vmain::Voice_Tests)
EVT_BUTTON(Lessons, Vmain::Voice_Lessosn)
EVT_BUTTON(Graphing, Vmain::Graphing__)
END_EVENT_TABLE()



// constructor deconstructor

Vmain::Vmain(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxPoint(40, 30), wxSize(250, 450))
{

	// clear error log
	std::ofstream ErrorLog;
	ErrorLog.open("ErrorLog.txt", std::ofstream::out);
	ErrorLog << "\nNew start ============================================================\n\n\n\n";
	ErrorLog.close();
	// main user created 
	//Login *Userinuse = new Login();


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
	ButtonVoiceTuner = new wxButton(panel, VoiceTunerID, _T("Voice Tuner"), wxPoint(34, 30), wxSize(175, 40), 0);
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
	//exit;
}

void Vmain::LoginMain(wxCommandEvent& event) {
	//panel_sizer->Hide(pane2);
	//panel_sizer->Show(pane1);
	login_frame_a* login = new login_frame_a("login screen 1");
	login->Show();
	//SetTopWindow(login);
}

void Vmain::VoiceTuner(wxCommandEvent& event) {
	// open new window.
	Voice_Tuner_frame* Voicetune = new Voice_Tuner_frame("Voice Tuner");
	Voicetune->Show();
}

void Vmain::Voice_Tests(wxCommandEvent& event) {
	Error_screens* Error = new Error_screens(1);
	if (Error->Get_check() == false)
		return;
	Voice_Tests_frame* tester = new Voice_Tests_frame("tests");
	tester->Show();
}

void Vmain::Voice_Lessosn(wxCommandEvent& event) {
	Error_screens* Error = new Error_screens(1);
	if (Error->Get_check() == false)
		return;
	Voice_Tests_frame* Lesson = new Voice_Tests_frame("Lesson");
	Lesson->Show();
}

void Vmain::Graphing__(wxCommandEvent& event) {
	Error_screens* Error = new Error_screens(1);
	if (Error->Get_check() == false)
		return;
	Error-> ~Error_screens();
	Graph_frames* Graph = new Graph_frames("Graphing module");
	Graph->Show();
}

// Main end ==================================================================



//Login screen ===============================================================


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
	//below is just a counter to tell if login b run what user id should be 
	IDnum =0;
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
			ErrorLog1 << "No users left to button\n";
			break;
		}
		else {
			Button[i] = new wxButton(login_a, UserButton+i, Usernames[i] , wxPoint(10, 30*(i+1)+10), wxDefaultSize, 0);
			ErrorLog1 << "\n\nUsernames captcha ============================================================\n\n";
			ErrorLog1 << "buttoned" << Usernames[i];
			IDnum += 1;
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
	login_frame_b* Register = new login_frame_b("login screen 2",IDnum);
	Register->Show();
	//SetTopWindow(login);
}

// set user whewn buttons clicked
void login_frame_a::User1(wxCommandEvent& event){

	Login::SetMainUser(1);
	Close(true);
}

void login_frame_a::User2(wxCommandEvent& event) {

	Login::SetMainUser(2);
	Close(true);
}

void login_frame_a::User3(wxCommandEvent& event) {

	Login::SetMainUser(3);
	Close(true);
}

void login_frame_a::User4(wxCommandEvent& event) {

	Login::SetMainUser(4);
	Close(true);
}



//--------------------------------------------------------------------------

// login frame b code 

// login b event table

BEGIN_EVENT_TABLE(login_frame_b, wxFrame)
EVT_BUTTON(Save, login_frame_b::SaveNewUser)
EVT_BUTTON(Exit, login_frame_b::OnExit)
EVT_TOGGLEBUTTON(M, login_frame_b::Togglechange)
EVT_TOGGLEBUTTON(F, login_frame_b::TogglechangeF)
END_EVENT_TABLE()

login_frame_b::login_frame_b(const wxString& title, int Idnum) : wxFrame(nullptr, wxID_ANY, title, wxPoint(30, 40), wxSize(300, 250))
{
	// set idnum for when save pressed
	IDnum = Idnum+1;
	//panel
	login_b = new wxPanel(this, wxID_ANY);
	login_b->SetBackgroundColour(wxT("#C311D6"));

	//widgits
	wxButton* ButtonSave = new wxButton(login_b, Save, _T("Save"), wxPoint(40, 160), wxDefaultSize, 0);
	wxButton* ButtonExit = new wxButton(login_b, Exit, _T("Exit"), wxPoint(120, 160), wxDefaultSize, 0);



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
	newUser.UserID = IDnum;
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

//exit
void login_frame_b::OnExit(wxCommandEvent& event) {
	Close(true); // closes the program
}



// Login screen end ======================================================


// Voice tuner =====================================================


// voice tune code
//eventtable
BEGIN_EVENT_TABLE(Voice_Tuner_frame, wxFrame)
END_EVENT_TABLE()

Voice_Tuner_frame::Voice_Tuner_frame(const wxString& title): wxFrame(nullptr, wxID_ANY, title, wxPoint(30, 40), wxSize(900, 250)) {

	// setting panels via seperate classes for panels
	setting = new wxPanel(this, wxID_ANY);
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

	Lights = new Light_screen(setting);
	Remote = new TuneRemote(setting);

	// allows remote to control exit
	Remote->setframe(this);

	hbox->Add(Lights, 1, wxEXPAND | wxALL, 1);
	hbox->Add(Remote, 1, wxEXPAND | wxALL, 6);
	//openstream
	
	

	setting->SetSizer(hbox);

	this->Centre();



}

// functions for voice tune frame
void Voice_Tuner_frame::OnExit(wxCommandEvent& event) {
	Close(true);
}



// note id for all functions to use below
std::string Notenames[] = { "C","C#", "D" , "D#", "E" ,"F", "F#","G","G#","A", "A#","B" };
std::string Octavenames[] = { "1","2" ,"3", "4", "5", "6","7","8" };
// panel remote code ------------------------------------------------
TuneRemote::TuneRemote(wxPanel* parent) :wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(300, 150), wxBORDER_SIMPLE) {
	//wx size does nothing at the moment

	this->SetBackgroundColour(wxT("#aaaaaa"));
	// starting note
	noteid = 0;
	octaveid = 0;
	notename = Notenames[noteid]+Octavenames[octaveid];
	
	//buttons and mappings
	 m_parent = parent;
	 wxButton* NoteUpButton = new wxButton(this, NoteUp, wxT("Note Up"), wxPoint(195, 87.5));
	 Connect(NoteUp, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TuneRemote::Change_note_up));
	 wxButton* NoteDownButton = new wxButton(this, NoteDown, wxT("Note Down"), wxPoint(0, 87.5));
	 Connect(NoteDown, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TuneRemote::Change_note_Down));
	 wxButton* OctaveUpButton = new wxButton(this, OctaveUp, wxT("Octave Up"), wxPoint(97.5, 0));
	 Connect(OctaveUp, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TuneRemote::Change_Octave_up));
	 wxButton* OctaveDownButton = new wxButton(this, OctaveDown, wxT("Octave Down"), wxPoint(97.5, 175));
	 Connect(OctaveDown, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TuneRemote::Change_Octave_Down));
	 wxButton*ExitButton = new wxButton(this, Exit, wxT("Exit"), wxPoint(195,175));
	 ExitButton->SetBackgroundColour(wxT("#FF0000"));
	 Connect(Exit, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(TuneRemote::OnExit));

	 // changing font
	 wxFont textfont(20, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	 this->SetFont(textfont);
	  Note = new wxStaticText(this, wxID_ANY, notename, wxPoint(110, 80), wxSize(50,30), wxALIGN_CENTRE);
	  Note->SetBackgroundColour(wxT("#C311D6"));
}

// functions for remote
// below functions to change note or actave. if on max start from min and vice versa
void TuneRemote::Change_note_up(wxCommandEvent& event) {

	delete Note;
	if (noteid ==  11 && octaveid !=7) {
		noteid = 0;
		octaveid +=1;
	}
	else if (noteid == 11 && octaveid == 7) {
		noteid = 0;
		octaveid =0;
	
	}
	else
		noteid +=1;
	
	notename = Notenames[noteid]+Octavenames[octaveid];
	Note = new wxStaticText(this, wxID_ANY, notename, wxPoint(110, 80), wxSize(50, 30), wxALIGN_CENTRE);
	Note->SetBackgroundColour(wxT("#C311D6"));
}

void TuneRemote::Change_note_Down(wxCommandEvent& event) {
	delete Note;
	if (noteid == 0 && octaveid != 0) {
		noteid = 11;
		octaveid -= 1;
	}
	else if (noteid == 0 && octaveid == 0) {
		noteid = 0;
		octaveid = 7;

	}
	else
		noteid -= 1;

	notename = Notenames[noteid] + Octavenames[octaveid];
	Note = new wxStaticText(this, wxID_ANY, notename, wxPoint(110, 80), wxSize(50, 30), wxALIGN_CENTRE);
	Note->SetBackgroundColour(wxT("#C311D6"));
}

void TuneRemote::Change_Octave_up(wxCommandEvent& event) {

	delete Note;
	if ( octaveid == 7) {
		octaveid =0;
	}
	else
		octaveid += 1;

	notename = Notenames[noteid] + Octavenames[octaveid];
	Note = new wxStaticText(this, wxID_ANY, notename, wxPoint(110, 80), wxSize(50, 30), wxALIGN_CENTRE);
	Note->SetBackgroundColour(wxT("#C311D6"));
}

void TuneRemote::Change_Octave_Down(wxCommandEvent& event) {

	delete Note;
	if (octaveid == 0) {
		octaveid = 7;
	}
	else
		octaveid -= 1;

	notename = Notenames[noteid] + Octavenames[octaveid];
	Note = new wxStaticText(this, wxID_ANY, notename, wxPoint(110, 80), wxSize(50, 30), wxALIGN_CENTRE);
	Note->SetBackgroundColour(wxT("#C311D6"));
}

void TuneRemote::OnExit(wxCommandEvent& event) {
	frame->Close(true);
}

void TuneRemote::setframe(wxFrame* frame_m) {
	frame = frame_m;
}

// panel for light panel code --------------------------------
Light_screen::Light_screen(wxPanel* parent) : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(600, -1), wxBORDER_SUNKEN) {



	this->SetBackgroundColour(wxT("#C311D6"));
	m_parent = parent;

	// below is testing
	//button and mapping
	wxButton* Notplay = new wxButton(this, Noteplay, wxT("Note Play"), wxPoint(270, 87.5));
	Connect(Noteplay, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Light_screen::playingnote));
	//light set 1
	Lightset1[0] = new wxLed(this, wxID_ANY, wxPoint(210, 87.5), wxSize(50,50), wxColour(00, 255, 00));
	Lightset1[0]->Disable();
	Lightset1[1] = new wxLed(this, wxID_ANY, wxPoint(140, 87.5), wxSize(50, 50), wxColour(20, 48, 226));
	Lightset1[1]->Disable();
	Lightset1[2] = new wxLed(this, wxID_ANY, wxPoint(80, 87.5), wxSize(50, 50), wxColour(255, 00, 230));
	Lightset1[2]->Disable();
	Lightset1[3] = new wxLed(this, wxID_ANY, wxPoint(20, 87.5), wxSize(50, 50), wxColour(226, 20, 20));
	Lightset1[3]->Disable();

	//light set 2
	Lightset2[0] = new wxLed(this, wxID_ANY, wxPoint(380, 87.5), wxSize(50, 50), wxColour(00, 255, 00));
	Lightset2[0]->Disable();
	Lightset2[1] = new wxLed(this, wxID_ANY, wxPoint(440, 87.5), wxSize(50, 50), wxColour(20, 48, 226));
	Lightset2[1]->Disable();
	Lightset2[2] = new wxLed(this, wxID_ANY, wxPoint(500, 87.5), wxSize(50, 50), wxColour(255, 00, 230));
	Lightset2[2]->Disable();
	Lightset2[3] = new wxLed(this, wxID_ANY, wxPoint(550, 87.5), wxSize(50, 50), wxColour(226, 20, 20));
	Lightset2[3]->Disable();

	// frequency being used and lights to show on startup
	Notefrequency = 0;
	// 1-4 is right side , 5-8 left side, 9 is mid
	lightsnum = 0;
}


void Light_screen::Lights(){

	//for testing
	if (lightsnum == 9)
		lightsnum = 1;
	else
		lightsnum += 1;
	// all below is testing in comment
	//wxStaticText* example = new wxStaticText(this, wxID_ANY, "working", wxPoint(10, B), wxDefaultSize, wxALIGN_CENTRE);

	// resets lights
	for (int i = 0; i < 4; i++) {
		Lightset1[i]->Disable();
		Lightset2[i]->Disable();
		Refresh();
	}

	// if voice is perfec (9) two lights show
	if (lightsnum == 9) {
		Lightset1[0]->Enable();
		Lightset2[0]->Enable();
		Refresh();
	}

	// enabling the right side lights
	else if (lightsnum < 5) {
			for (int i = 0; i < lightsnum; i++) {
				Lightset1[i]->Enable();
				Lightset1[i]->Enable();
				Refresh();
		}
	}

	// enabling left side lights
	else {
		for (int i = 0; i < lightsnum-4; i++) {
			Lightset2[i]->Enable();
			Lightset2[i]->Enable();
			Refresh();
		}
	}


}

void Light_screen::playingnote(wxCommandEvent& event) {

	Light_screen::Lights();
}


// Voice tuner end ======================================================


// Tests tuner =====================================================

Voice_Tests_frame::Voice_Tests_frame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxPoint(40, 30), wxSize(250, 450)) {
	TestrollPanel = new wxPanel(this, wxID_ANY);
	//wxButton* buttontests = new wxButton(TestrollPanel, wxID_ANY,wxT("Tests"));

}






// Tests tuner ======================================================


// graphs =====================================================


//event table
BEGIN_EVENT_TABLE(Graph_frames, wxFrame)
EVT_BUTTON(onwards + 1, Graph_frames::Buttonevent1)
EVT_BUTTON(onwards + 2, Graph_frames::Buttonevent2)
EVT_BUTTON(onwards + 3, Graph_frames::Buttonevent3)
EVT_BUTTON(onwards + 4, Graph_frames::Buttonevent4)
EVT_BUTTON(onwards + 5, Graph_frames::Buttonevent5)
EVT_BUTTON(onwards + 6, Graph_frames::Buttonevent6)
EVT_BUTTON(Back_screen, Graph_frames::Back)
EVT_BUTTON(Exit, Graph_frames::OnExit)
END_EVENT_TABLE()

// string names
std::string Graph_frame_text[][6] = { {"C","C#", "D" , "D#", "E" ,"F"},{"F#","G","G#","A", "A#","B"},{"r","q","w","f", "g","h"} };
Graph_frames::Graph_frames(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxPoint(40, 30), wxSize(250, 450)) {
	
	current_screen = 0;
	Main_panel = new wxPanel(this, wxID_ANY);
	// for test b = 10;
	
	Set_buttons();

	this->Show();
}


//functions 
void Graph_frames::Set_buttons() {

	// reset buttons
	for (int i = 0; i < 6; i++) {
		delete Buttonset[i];
	}
	delete ButtonExit;

	if (current_screen != 3) {
		for (int i = 0; i < 6; i++) {
			if (i % 2 == 0) {
				Buttonset[i] = new wxButton(Main_panel, i + 1 + onwards, Graph_frame_text[current_screen][i], wxPoint(34, (i + 1) * 10));
			}
			else {
				Buttonset[i] = new wxButton(Main_panel, i + 1 + onwards, Graph_frame_text[current_screen][i], wxPoint(104.5, i * 10));

			}
		}
	}
	if (current_screen == 0 || current_screen == 3)
		ButtonExit = new wxButton(Main_panel, Exit,"Exit");
	else
		ButtonExit = new wxButton(Main_panel, Back_screen,"Previous");

	//Connect(onwards+1, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Graph_frames::test));
	// for testing b += 1; wxStaticText* example = new wxStaticText(Main_panel, wxID_ANY, "working", wxPoint(10, b), wxDefaultSize, wxALIGN_CENTRE);
	Refresh();
}

// button fuctions ( change soon)
void Graph_frames::Buttonevent1(wxCommandEvent& event) {
	selection[current_screen] = 1;
	if (current_screen == 3)
		return;
	else {
		current_screen += 1;
		Set_buttons();
	}
}

void Graph_frames::Buttonevent2(wxCommandEvent& event) {
	selection[current_screen] = 2;
	if (current_screen == 3)
		return;
	else {
		current_screen += 1;
		Set_buttons();
	}
}

void Graph_frames::Buttonevent3(wxCommandEvent& event) {
	selection[current_screen] = 3;
	if (current_screen == 3)
		return;
	else {
		current_screen += 1;
		Set_buttons();
	}
}

void Graph_frames::Buttonevent4(wxCommandEvent& event) {
	selection[current_screen] = 4;
	if (current_screen == 3)
		return;
	else {
		current_screen += 1;
		Set_buttons();
	}

}

void Graph_frames::Buttonevent5(wxCommandEvent& event) {
	selection[current_screen] = 5;
	if (current_screen == 3)
		return;
	else {
		current_screen += 1;
		Set_buttons();
	}
}

void Graph_frames::Buttonevent6(wxCommandEvent& event) {
	selection[current_screen] = 6;
	if (current_screen == 3)
		return;
	else {
		current_screen += 1;
		Set_buttons();
	}

}

void Graph_frames::Back(wxCommandEvent& event) {
	current_screen -= 1;
	Set_buttons();
}

void Graph_frames::OnExit(wxCommandEvent& event) {

	Close(true);
}





// graphs end=========================================


// error screens ==========================================
 Error_screens::Error_screens(int choice) : wxFrame(nullptr, wxID_ANY, "no user here", wxPoint(30, 40), wxSize(300, 200)) {

	 this->SetBackgroundColour(wxT("#C311D6"));
	Check_Mainuser_active();
}


void Error_screens::Check_Mainuser_active()  {
	structures::User temp;
	temp = structures::GetMainUser();

	if (temp.Age == NULL) {
		wxPanel* Error = new wxPanel(this, wxID_ANY);
		wxStaticText* st1 = new wxStaticText(Error, wxID_ANY, "  Please log in  ", wxPoint(50, 10), wxDefaultSize, wxALIGN_CENTRE);
		exit = new wxButton(Error, Exit_error, "Exit", wxPoint(50, 30));
		exit->SetBackgroundColour(wxT("#FF0000"));
		Connect(Exit_error, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Error_screens::close_error));


		this->Show();
		check = false;
	}
	else
		check = true;
}

void Error_screens::close_error(wxCommandEvent& event) {
	Close(true);
}

bool Error_screens::Get_check() {
	return check;
}