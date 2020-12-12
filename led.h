/////////////////////////////////////////////////////////////////////////////
// Name:        led.h
// Purpose:     wxLed class
// Author:      Thomas Monjalon
// Created:     09/06/2005
// Revision:    09/06/2005
// Licence:     wxWidgets
// adjusted for Voice_up
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_LED_H_
#define _WX_LED_H_

#include <wx/window.h>
#include <wx/bitmap.h>
#include <wx/dcclient.h>
#include <wx/thread.h>

class wxLed : public wxWindow
{
public:

	//add , wxColour dummycoulur
	wxLed(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, wxColour enableColour = wxColour(00, 255, 00), wxColour disabledColor = wxColour(00, 00, 00));
	~wxLed();

	void Enable(void);
	void Disable(void);
	void SetColor(wxColour rgb);
	bool IsEnabled(void);
	bool on;

protected:

	wxColour m_Enable;
	wxColour m_Disable;
	wxBitmap* m_bitmap;
	wxMutex m_mutex;
	bool m_IsEnable;

	void OnPaint(wxPaintEvent& event);

	virtual void SetBitmap(wxString color);
	//extra
	//void SwitchOn(void);
	//void SwitchOff();
	//void Disable(void);

private:

	DECLARE_EVENT_TABLE()
};

#endif // _WX_LED_H_

