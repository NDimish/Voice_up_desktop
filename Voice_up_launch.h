#pragma once
//This is the launcher of the app

//imports
#include "wx/wx.h"
#include "Vmain.h"



class Voice_up_launch : public wxApp {
private:
	Vmain* start_frames = nullptr;

public:
	Voice_up_launch();
	~Voice_up_launch();

	//funcions
	virtual bool OnInit();


};

