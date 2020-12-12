//imports
#include "Vmain.h"
#include <fstream>
#include "Login.h"
#include "string"
#include "Structures.h"
#include <wx/tglbtn.h>
#include "Import.h"
#include "Tests_backend.h"
#include "Free_tune.h"
#include <windows.h>
#include<thread> 



// definitions
// below is for the background

// source code for main program class

// purple function consts

// below includes the eventtable which says what happens when each button is pressed


//note,
//exit button only allows the open counter to work





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
	// sett all 0o[pen windows to false
	structures::SetOpenWindows(9,false);
	//wxPanel* x = new wxPanel(this, wxID_ANY);

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
	panel->Show();

}



Vmain::~Vmain() {}


//functions
void Vmain::OnExit(wxCommandEvent& event) {
	
	Close(true); // closes the program
	Sleep(100);
	
}

void Vmain::LoginMain(wxCommandEvent& event) {
	//panel_sizer->Hide(pane2);
	//panel_sizer->Show(pane1);
	login_frame_a* login = new login_frame_a("login screen 1");
	login->Show();
	//SetTopWindow(login);
}

void Vmain::VoiceTuner(wxCommandEvent& event) {
	//check if window open
//	if (structures::GetOpenwindows(1))
	//	return;
	
	// open new window.
	Voicetune = new Voice_Tuner_frame("Voice Tuner");
	Voicetune->Show();
	// set window to open
	structures::SetOpenWindows(1);
}

void Vmain::Voice_Tests(wxCommandEvent& event) {
	
	//check if window open
//	if (structures::GetOpenwindows(2))
//		return;

	Error_screens* Error = new Error_screens(1);
	if (Error->Get_check() == false)
		return;
	Error-> ~Error_screens();
	tester = new Voice_Tests_frame("tests");
	tester->Show();

	// set window to open
	structures::SetOpenWindows(2);
}

void Vmain::Voice_Lessosn(wxCommandEvent& event) {
	//check if window open
	//if (structures::GetOpenwindows(3))
	//	return;
	/*Error_screens* Error = new Error_screens(1);
	if (Error->Get_check() == false)
		return;
	Error-> ~Error_screens();
	Lesson = new Voice_Tests_frame("Lesson");
	Lesson->Show();
	// set window to open
	structures::SetOpenWindows(3);*/

}

void Vmain::Graphing__(wxCommandEvent& event) {

	//check if window open
	//if (structures::GetOpenwindows(4))
	//	return;
	Error_screens* Error = new Error_screens(1);
	if (Error->Get_check()== false)
		return;
	Error-> ~Error_screens();
	Graph = new Graph_frames("Graphing module");
	Graph->Show();
	// set window to open
	structures::SetOpenWindows(4);
}

// Main end ==================================================================












//Login screen ===============================================================


/// login screen A
/// // login a event table

BEGIN_EVENT_TABLE(login_frame_a, wxFrame)
EVT_BUTTON(Register, login_frame_a::Registering)
EVT_BUTTON(UserButton, login_frame_a::User1)
EVT_BUTTON(UserButton1, login_frame_a::User2)
EVT_BUTTON(UserButton2, login_frame_a::User3)
EVT_BUTTON(UserButton3, login_frame_a::User4)
END_EVENT_TABLE()

login_frame_a::login_frame_a(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxPoint(30, 40), wxSize(250, 450))
{// get names

	//bitmaps used
	wxBitmap bitmap[5];
	bitmap[0].LoadFile(R"(..\Documentation_for_voice_up\bmp files\girl4.bmp)", wxBITMAP_TYPE_BMP);
	bitmap[1].LoadFile(R"(..\Documentation_for_voice_up\bmp files\yoda.bmp)", wxBITMAP_TYPE_BMP);
	bitmap[2].LoadFile(R"(..\Documentation_for_voice_up\bmp files\groot.bmp)", wxBITMAP_TYPE_BMP);
	bitmap[3].LoadFile(R"(..\Documentation_for_voice_up\bmp files\guy.bmp)", wxBITMAP_TYPE_BMP);
	bitmap[4].LoadFile(R"(..\Documentation_for_voice_up\bmp files\new_user.bmp)", wxBITMAP_TYPE_BMP);


	// below is the code to output the user buttons in order
	wxBitmapButton* Button[4];
	//below is just a counter to tell if login b run what user id should be 
	IDnum =0;
	//panel
	wxPanel* login_a = new wxPanel(this, wxID_ANY);
	login_a->SetBackgroundColour(wxT("#C311D6"));

	//title
	wxStaticText* st1 = new wxStaticText(login_a, wxID_ANY, "  Select-User  ", wxPoint(70, 10), wxDefaultSize, wxALIGN_CENTRE);

	// code to print buttons 
	std::string Usernames[4];
	std::ofstream ErrorLog1;
	ErrorLog1.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	Login::GetNames(Usernames);
	for (int i = 0; i < 4; i++) {
		if (Usernames[i] == "") {

			wxButton* ButtonRegister = new wxBitmapButton(login_a, Register, bitmap[4], wxPoint(50, 95*(i)+30), wxSize(100, 75), 0);
			ErrorLog1 << "\n\nUsernames captcha ============================================================\n\n";
			ErrorLog1 << "No users left to button\n";
			break;
		}
		else {
			Button[i] = new wxBitmapButton(login_a, UserButton+i, bitmap[i], wxPoint(50, 95*(i)+25), wxSize(100, 70), 0);
			wxStaticText* stnmae = new wxStaticText(login_a, wxID_ANY, Usernames[i], wxPoint(70, 95 * (i)+96), wxDefaultSize, wxALIGN_CENTRE);
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
	if (newUser.Username.length() == 0 || newUser.Username.length() >6) {
		wxStaticText* st5 = new wxStaticText(login_b, wxID_ANY, "Error in your regestration ( Username )", wxPoint(10, 190), wxDefaultSize, wxALIGN_CENTRE);
		OutputError(st5);
		return;
	}



	// validation for toggle
	if (Male ==0 && Female ==0 || Male == 1 && Female == 1) {
		wxStaticText* st5 = new wxStaticText(login_b, wxID_ANY, "Error in your regestration ( Sex )            ", wxPoint(10, 190), wxDefaultSize, wxALIGN_CENTRE);
		OutputError(st5);
		return;
	}
	if (Male == 0)
		newUser.Sex = 'F';
	else
		newUser.Sex = 'M';






	// checks dropdown choosen
	if ((char)DropdownSing_Type->GetCurrentSelection() == 'ÿ') {
		wxStaticText* st5 = new wxStaticText(login_b, wxID_ANY, "Error in your regestration ( Sing )          ", wxPoint(10, 190), wxDefaultSize, wxALIGN_CENTRE);
		OutputError(st5);
		return;
	}
	// set dropdown choice
	int x = DropdownSing_Type->GetCurrentSelection();
	wxString y = voice_types[x];
	newUser.SingType = y[0];

	

	// validation for age input
	if ((char)DropdownAge_Tens->GetCurrentSelection() == 'ÿ' || (char)DropdownAge_Units->GetCurrentSelection() == 'ÿ') {
		wxStaticText* st5 = new wxStaticText(login_b, wxID_ANY, "Error in your regestration ( Age )           ", wxPoint(10, 190), wxDefaultSize, wxALIGN_CENTRE);
		OutputError(st5);
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

void login_frame_b::OutputError(wxStaticText* st5) {
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

// function to allow threading
void openthread(Free_tune* inputoutputstream) {

	inputoutputstream->AudioCheck();
	
}
Voice_Tuner_frame::Voice_Tuner_frame(const wxString& title): wxFrame(nullptr, wxID_ANY, title, wxPoint(30, 40), wxSize(900, 250)) {

	// setting panels via seperate classes for panels
	setting = new wxPanel(this, wxID_ANY);
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

	Lights = new Light_screen(setting);
	// for the adiuo input
	Free_tune* ADAC = new Free_tune();
	(*ADAC).Lights = Lights;
	// threading for the voice 
	std::thread* Voice = new std::thread(openthread, std::cref(ADAC));

	// remote to control all
	Remote = new TuneRemote(setting, Lights, Voice);

	// allows remote to control exit
	Remote->setframe(this);

	hbox->Add(Lights, 1, wxEXPAND | wxALL, 1);
	hbox->Add(Remote, 1, wxEXPAND | wxALL, 6);
	//openstream
	
	

	setting->SetSizer(hbox);

	this->Centre();



}

// functions for voice tune frame
/*void Voice_Tuner_frame::OnExit(wxCommandEvent& event) {
	Close(true);
}*/



// note id for all functions to use below
// note frequencies to be used below 2d array octive than note
std::string Notenames[] = { "C","C#", "D" , "D#", "E" ,"F", "F#","G","G#","A", "A#","B" };
std::string Octavenames[] = { "0","1","2" ,"3", "4", "5", "6","7","8" };
float notefrequency[9][12] = { {16.35,17.32,18.35,19.45,20.60,21.83,23.12,24.50,25.96,27.50,29.14,30.87 }, 
	{32.70,34.65,36.71,38.89,41.20,43.65,46.25,49.00,51.91,55.00,58.27,61.74},
	{65.41,69.30,73.42,77.78,82.41,87.31,92.50,98.00,103.83,110.00,116.54,123.47},
	{130.81,138.59,146.83,155.56,164.81,174.61,185.00,196.00,207.65,220.00,233.08,246.94},
	{261.63,277.18,293.66,311.13,329.63,349.23,369.99,392.00,415.30,440.00,466.16,493.88},
	{523.25,554.37,587.33,622.25,659.25,698.46,739.99,783.99,830.61,880.00,932.33,987.77},
	{1046.50,1108.73,1174.66,1244.51,1318.51,1396.91,1479.98,1567.98,1661.22,1760.00,1864.66,1975.53},
	{2093.00,2217.46,2349.32,2489.02,2637.02,2793.83,2959.96,3135.96,3322.44,3520.00,3729.31,3951.07},
	{4186.01,4434.92,4698.63,4978.03,5274.04,5587.65,5919.91,6271.93,6644.88,7040.00,7458.62,7902.13} };
// panel remote code ------------------------------------------------
TuneRemote::TuneRemote(wxPanel* parent,Light_screen* lights, std::thread* thread) :wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(300, 150), wxBORDER_SIMPLE) {
	//wx size does nothing at the moment
	// for the close interuppt of the frequency stream
	LightScreen = lights;
	Toclose = thread;
	this->SetBackgroundColour(wxT("#aaaaaa"));
	// starting note
	noteid = 0;
	octaveid = 4;
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
	if (noteid ==  11 && octaveid !=9) {
		noteid = 0;
		octaveid +=1;
	}
	else if (noteid == 11 && octaveid == 9) {
		noteid = 0;
		octaveid =0;
	
	}
	else
		noteid +=1;
	
	//notename = Notenames[noteid]+Octavenames[octaveid];
	(*LightScreen).Notefrequency = notefrequency[octaveid][noteid];
	Note = new wxStaticText(this, wxID_ANY, (Notenames[noteid] + Octavenames[octaveid]), wxPoint(110, 80), wxSize(50, 30), wxALIGN_CENTRE);
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
		octaveid = 9;

	}
	else
		noteid -= 1;

	notename = Notenames[noteid] + Octavenames[octaveid];
	(*LightScreen).Notefrequency = notefrequency[octaveid][noteid];
	Note = new wxStaticText(this, wxID_ANY, notename, wxPoint(110, 80), wxSize(50, 30), wxALIGN_CENTRE);
	Note->SetBackgroundColour(wxT("#C311D6"));
}

void TuneRemote::Change_Octave_up(wxCommandEvent& event) {

	delete Note;
	if ( octaveid == 9) {
		octaveid =0;
	}
	else
		octaveid += 1;

	notename = Notenames[noteid] + Octavenames[octaveid];
	(*LightScreen).Notefrequency = notefrequency[octaveid][noteid];
	Note = new wxStaticText(this, wxID_ANY, notename, wxPoint(110, 80), wxSize(50, 30), wxALIGN_CENTRE);
	Note->SetBackgroundColour(wxT("#C311D6"));
}

void TuneRemote::Change_Octave_Down(wxCommandEvent& event) {

	delete Note;
	if (octaveid == 0) {
		octaveid = 9;
	}
	else
		octaveid -= 1;

	notename = Notenames[noteid] + Octavenames[octaveid];
	(*LightScreen).Notefrequency = notefrequency[octaveid][noteid];
	Note = new wxStaticText(this, wxID_ANY, notename, wxPoint(110, 80), wxSize(50, 30), wxALIGN_CENTRE);
	Note->SetBackgroundColour(wxT("#C311D6"));
}

void TuneRemote::OnExit(wxCommandEvent& event) {
	// function below deemed invalid but here for tests( used for check which windows are open)
	//structures::SetOpenWindows(3, false);
	(*LightScreen).exit = true;
	frame->Close(true);
	Sleep(1250);
	Toclose -> detach();
}

void TuneRemote::setframe(wxFrame* frame_m) {
	frame = frame_m;
}

// panel for light panel code --------------------------------
Light_screen::Light_screen(wxPanel* parent) : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(600, -1), wxBORDER_SUNKEN) {
	// errorlog 
	Error_screens::Error_log("\nFree tuner ============================================================\n\n\n\n");
	// ensure the exit is false so the audio starts
	exit = false;

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
	Notefrequency = 261.63; //c4
	// 1-4 is right side , 5-8 left side, 9 is mid
	Lightson = 0;
}


void Light_screen::Lights(int lightsnum){
	if (lightsnum == Lightson)
		return;
	// all below is testing in comment
	//wxStaticText* example = new wxStaticText(this, wxID_ANY, "working", wxPoint(10, B), wxDefaultSize, wxALIGN_CENTRE);

	// below is for the counter to say if the next iteration is same lightsnum skip
	Lightson = lightsnum;
	//Error_screens::Error_log(lightsnum);
	// resets lights
	for (int i = 0; i < 4; i++) {
		if((*Lightset1[i]).on != false)
		Lightset1[i]->Disable();
		if ((*Lightset2[i]).on != false)
		Lightset2[i]->Disable();
		Refresh();
	}

	// if voice is perfec (9) two lights show
	if (lightsnum == 9) {
		//for (int i = 1; i < 4; i++) {
			/*if ((*Lightset1[i]).on != false)
				Lightset1[i]->Disable();
			if ((*Lightset2[i]).on != false)
				Lightset2[i]->Disable();*/
			Lightset1[0]->Enable();
			Lightset2[0]->Enable();
		//}
		// show change
		Refresh();
	}

	// enabling the right side lights
	else if (lightsnum < 5) {
		//disable other side
		/*for (int i = 0; i < 4; i++) {
			//if ((*Lightset2[i]).on == true)
				Lightset2[i]->Disable();

		}*/
			for (int i = 0; i < lightsnum; i++) {
				// only do if it is false
				//if ((*Lightset1[i]).on == false) {
					Lightset1[i]->Enable();
					//Lightset1[i]->Enable();
			}
				// for smooth overlap
				/*for (int i = 0; i < 4-lightsnum; i++) {
					// only do if it is false
					if ((*Lightset1[3 - i]).on == true) {
						Lightset1[3 - i]->Disable();
						//Lightset1[i]->Enable();
					}
				}*/
		
			// show change
			Refresh();
	}


	// enabling left side lights
	else {
		//disable other side
		/*for (int i = 0; i < 4; i++) {
			if ((*Lightset1[i]).on == true)
				Lightset1[i]->Disable();

		}*/
		for (int i = 0; i < lightsnum-4; i++) {
			//if ((*Lightset2[i]).on == false) {
				Lightset2[i]->Enable();
				//Lightset2[i]->Enable()};
			
		}
		// disabling to make it smoother
		/*for (int i = 0;  i < 8-lightsnum; ) {
			// only do if it is false
			if ((*Lightset2[3 - i]).on == true) {
				Lightset2[3 - i]->Disable();
				//Lightset1[i]->Enable();
			}
		}*/
		// show change
		Refresh();
	}
	
}

void Light_screen::playingnote(wxCommandEvent& event) {

	//Light_screen::Lights();
}


// Voice tuner end ======================================================










// Tests tuner =====================================================
Voice_Tests_frame::Voice_Tests_frame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxPoint(40, 30), wxSize(250, 450)) {
	
	// instead of a panel i have a scroll panel
	Testroller = new wxScrolledWindow(this, wxID_ANY);
	Testroller->SetBackgroundColour(wxT("#C311D6"));
	// sizer for scroller
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	// title
	wxStaticText* Title = new wxStaticText(Testroller, wxID_ANY, "Choose you singing test to begin", wxDefaultPosition, wxSize(150, 40), wxALIGN_CENTRE);
	sizer->Add(Title, 0, wxALL, 3);

	// the key for the colours (test)
	wxStaticText* Key = new wxStaticText(Testroller, wxID_ANY, "\nBelow is the key for the colour:", wxDefaultPosition, wxSize(200, 30),wxALIGN_LEFT);
	sizer->Add(Key, 0, wxALL, 3);
	wxStaticText* Green = new wxStaticText(Testroller, wxID_ANY, "Above 90%", wxDefaultPosition, wxSize(150, 20), wxALIGN_LEFT);
	Green->SetBackgroundColour(wxT("#89EE36"));
	sizer->Add(Green, 0, wxALL, 3);
	wxStaticText* Orange = new wxStaticText(Testroller, wxID_ANY, "Between 60% - 90%", wxDefaultPosition, wxSize(150, 20), wxALIGN_LEFT);
	Orange->SetBackgroundColour(wxT("#EEE936"));
	sizer->Add(Orange, 0, wxALL, 3);
	wxStaticText* Red = new wxStaticText(Testroller, wxID_ANY, "Between 30% - 60%", wxDefaultPosition, wxSize(150, 20), wxALIGN_LEFT);
	Red->SetBackgroundColour(wxT("#EE5736"));
	sizer->Add(Red, 0, wxALL, 3);
	wxStaticText* Grey = new wxStaticText(Testroller, wxID_ANY, "Below 30%\n\n\n", wxDefaultPosition, wxSize(150, 30), wxALIGN_LEFT);
	//Grey->SetBackgroundColour(wxT("#FF0000"));
	sizer->Add(Grey, 0, wxALL, 3);


	// event for the buttons, so i dont have million button events that do the same thing
	//Game runs on event
	// code to print buttons 
	// array of buttons for tests
	wxButton* Button[21];
	std::string Names[21];
	std::ofstream ErrorLog1;
	ErrorLog1.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	Tests_backend::Get_tests_names(Names);
	for (int i = 0; i < 21; i++) {
		// when all names are outputted
		if (Names[i] == "") {
			wxButton* ExitButton = new wxButton(Testroller, Exit, "Exit");
			ExitButton->SetBackgroundColour(wxT("#FF0000"));
			sizer->Add(ExitButton, 0, wxALL, 3);
			Connect(Exit, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Voice_Tests_frame::OnExit));
			ErrorLog1 << "\n\nTestsNames captcha ============================================================\n\n";
			ErrorLog1 << "No users left to button\n";
			break;
		}
		// to output buttons
		else {
			Button[i] = new wxButton(Testroller, onwards + i, Names[i],wxDefaultPosition,wxSize(200,60));
			Connect(onwards+i, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Voice_Tests_frame::TestRun));
			// temp to show colours
			sizer->Add(Button[i], 0, wxALL, 3);
			if (i == 0 || i== 4 || i ==5) {
				Button[i]->SetBackgroundColour(wxT("#89EE36"));
			}
			if (i == 1 || i ==2 ) {
				Button[i]->SetBackgroundColour(wxT("#EEE936"));
			}
			if (i == 6 || i ==3) {
				Button[i]->SetBackgroundColour(wxT("#EE5736"));
			}
			ErrorLog1 << "\n\nTestsNames captcha ============================================================\n\n";
			ErrorLog1 << "buttoned" << Names[i];
		}
	}
	ErrorLog1.close();

	// Sertting sizer to panel
	Testroller->SetSizer(sizer);
	// this part makes the scrollbars show up
	Testroller->FitInside(); // ask the sizer about the needed size
	Testroller->SetScrollRate(5, 5);
}


// add this onexit structures::SetOpenWindows(4, false);
//functions
void Voice_Tests_frame::OnExit(wxCommandEvent& event) {
	// function below deemed invalid but here for tests( used for check which windows are open)
	structures::SetOpenWindows(4, false);
	Close(true);
}

void Voice_Tests_frame::TestRun(wxCommandEvent& event){
	// the code below gets what button was pressed by checking its id
	int ID;
	ID = event.GetId() - onwards;
	std::ofstream ErrorLog2;
	ErrorLog2.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	ErrorLog2 << "\nGame data being run is\n"<<ID;
	ErrorLog2.close();
	Voice_game* Game = new Voice_game(ID);
	Game->Show();
}

// Game class constructor

Voice_game::Voice_game(int DataID):wxFrame(nullptr, wxID_ANY, (wxString)"Game "<<DataID, wxPoint(30, 40), wxSize(900, 250)) {

	Gamepanel = new wxPanel(this, wxID_ANY);
	Gamepanel->SetBackgroundColour(wxT("#C311D6"));

}

void Voice_game::RunExitScoreWindow(int score) {
	return;
}


// Tests tuner end ======================================================












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
std::string Graph_frame_text[][6] = { {"Tests pitch","Lessons", "Tests Bass" , "Tests tenor", "Tests Alto" ,"Test Soprano"},{"Year","Month","Week","Day", "Hour","All time"},
	{"Bar","Line","Pie chart","Picturegram", "Feild graph","random"},{"Choose what to graph","Choose Time frame","Choose how to graph","Graphed"} };
Graph_frames::Graph_frames(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxPoint(40, 30), wxSize(250, 450)) {
	
	current_screen = 0;
	Main_panel = new wxPanel(this, wxID_ANY);
	Main_panel->SetBackgroundColour(wxT("#C311D6"));
	// for test b = 10;
	
	Set_buttons(true);
	// error log
	Error_screens::Error_log("Graph frames set===============================================");
	this->Show();
}


//functions 
void Graph_frames::Set_buttons(bool firstIntialize) {

	// reset buttons
	if (firstIntialize != true) {
		for (int i = 0; i < 6; i++) {
			delete Buttonset[i];
		}
		delete ButtonExit;
		delete title;
	}

	// make buttons
	if (current_screen != 3) {
		for (int i = 0; i < 6; i++) {
			if (i % 2 == 0) {
				Buttonset[i] = new wxButton(Main_panel, i + 1 + onwards, Graph_frame_text[current_screen][i], wxPoint(24, ((i + 1) * 20)+30));
			}
			else {
				Buttonset[i] = new wxButton(Main_panel, i + 1 + onwards, Graph_frame_text[current_screen][i], wxPoint(114.5, (i * 20)+30));

			}
		}
	}
	//add title
	title = new wxStaticText(Main_panel, wxID_ANY, Graph_frame_text[3][current_screen], wxPoint(50,25));

	// add a previous or exit button
	if (current_screen == 0 || current_screen == 3) {
		ButtonExit = new wxButton(Main_panel, Exit, "Exit", wxPoint(24, 160));
		ButtonExit->SetBackgroundColour(wxT("#D92C2C"));
	}
	else
		ButtonExit = new wxButton(Main_panel, Back_screen,"Previous");
	// set on screen
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

	//error log
	Error_screens::Error_log("Current selection is:",selection);
}

void Graph_frames::Buttonevent2(wxCommandEvent& event) {
	selection[current_screen] = 2;
	if (current_screen == 3)
		return;
	else {
		current_screen += 1;
		Set_buttons();
	}

	//error log
	Error_screens::Error_log("Current selection is:", selection);
}

void Graph_frames::Buttonevent3(wxCommandEvent& event) {
	selection[current_screen] = 3;
	if (current_screen == 3)
		return;
	else {
		current_screen += 1;
		Set_buttons();
	}

	//error log
	Error_screens::Error_log("Current selection is:", selection);
}

void Graph_frames::Buttonevent4(wxCommandEvent& event) {
	selection[current_screen] = 4;
	if (current_screen == 3)
		return;
	else {
		current_screen += 1;
		Set_buttons();
	}

	//error log
	Error_screens::Error_log("Current selection is:", selection);
}

void Graph_frames::Buttonevent5(wxCommandEvent& event) {
	selection[current_screen] = 5;
	if (current_screen == 3)
		return;
	else {
		current_screen += 1;
		Set_buttons();
	}
	//error log
	Error_screens::Error_log("Current selection is:", selection);

}

void Graph_frames::Buttonevent6(wxCommandEvent& event) {
	selection[current_screen] = 6;
	if (current_screen == 3)
		return;
	else {
		current_screen += 1;
		Set_buttons();
	}

	//error log
	Error_screens::Error_log("Current selection is:", selection);
}

void Graph_frames::Back(wxCommandEvent& event) {
	current_screen -= 1;
	Set_buttons();
}

void Graph_frames::OnExit(wxCommandEvent& event) {

	Error_screens::Error_log("Graphs end ==============================================");
	this -> ~Graph_frames();
	// function below deemed invalid but here for tests( used for check which windows are open)
	structures::SetOpenWindows(4, false);
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

void Error_screens::Error_log(std::string input, int x[]) {

	std::ofstream ErrorLog;
	ErrorLog.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	ErrorLog << input << x[0] << "," << x[1] << "," << x[2] << "\n";
	ErrorLog.close();

}

void Error_screens::Error_log(std::string input) {

	std::ofstream ErrorLog;
	ErrorLog.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	ErrorLog << input << "\n" << "\n";
	ErrorLog.close();

}

void Error_screens::Error_log(int input) {

	std::ofstream ErrorLog;
	ErrorLog.open("ErrorLog.txt", std::ofstream::out | std::ofstream::app);
	ErrorLog << input << "\n" << "\n";
	ErrorLog.close();

}