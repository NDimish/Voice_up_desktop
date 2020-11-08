/////////////////////////////////////////////////////////////////////////////
// Name:        led.cpp
// Purpose:     wxLed implementation
// Author:      Thomas Monjalon
// Created:     09/06/2005
// Revision:    09/06/2005
// Licence:     wxWidgets
// adjusted for Voice_up
/////////////////////////////////////////////////////////////////////////////

#include "led.h"

#include <string.h>



BEGIN_EVENT_TABLE(wxLed, wxWindow)
EVT_PAINT(wxLed::OnPaint)
END_EVENT_TABLE()

//, wxColour dummyColour add
wxLed::wxLed(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, wxColour enableColour, wxColour disabledColor)
    :
    wxWindow(parent, id, pos, size),
    m_bitmap(NULL)
{
    this->m_isEnabled = true;
    m_Disable = disabledColor;
    m_Enable = enableColour;
    //m_Dummy = dummyColour; // Added by PJG
    Enable();
}


wxLed::~wxLed()
{
    delete this->m_bitmap;
}

void wxLed::Enable(void)
{
    wxWindow::Enable(true);
    this->SetBitmap(this->m_Enable.GetAsString(wxC2S_HTML_SYNTAX));
}

//Added by PJG
/*void wxLed::SwitchOn(void)
{
    //Enable();
}*/

//Added by PJG
/*void wxLed::SwitchOff(void)
{
    wxWindow::Enable(false);
    this->SetBitmap(this->m_Disable.GetAsString(wxC2S_HTML_SYNTAX));
}*/
void wxLed::Disable(void)
{
    wxWindow::Enable(false);
    this->SetBitmap(this->m_Disable.GetAsString(wxC2S_HTML_SYNTAX));
}

void wxLed::SetColor(wxColour rgb)
{
    m_Enable = rgb;
    if (this->m_isEnabled)
        this->SetBitmap(this->m_Enable.GetAsString(wxC2S_HTML_SYNTAX));
}

bool wxLed::IsEnabled(void)
{
    return this->m_isEnabled;
}




// actual button

void wxLed::OnPaint(wxPaintEvent& WXUNUSED(event))
{
    wxPaintDC dc(this);
    this->m_mutex.Lock();
    dc.DrawBitmap(*this->m_bitmap, 0, 0, true);
    this->m_mutex.Unlock();
}

#define WX_LED_WIDTH    17
#define WX_LED_HEIGHT   17
#define WX_LED_COLORS    5
#define WX_LED_XPM_COLS    (WX_LED_WIDTH + 1)
#define WX_LED_XPM_LINES   (1 + WX_LED_COLORS + WX_LED_HEIGHT)

//bitmap(picture to see button)

void wxLed::SetBitmap(wxString color)
{
    char** xpm = NULL;
    char* xpmData = NULL;
    xpm = new char* [WX_LED_XPM_LINES];
    if (xpm == NULL)
        goto end;
    xpmData = new char[WX_LED_XPM_LINES * WX_LED_XPM_COLS];
    if (xpmData == NULL)
        goto end;
    for (int i = 0; i < WX_LED_XPM_LINES; i++)
        xpm[i] = xpmData + i * WX_LED_XPM_COLS;
    // width height num_colors chars_per_pixel
    sprintf(xpm[0], "%d %d %d 1", WX_LED_WIDTH, WX_LED_HEIGHT, WX_LED_COLORS);
    // colors
    strncpy(xpm[1], "  c #C311D6", WX_LED_XPM_COLS);
    strncpy(xpm[2], "- c #C311D6", WX_LED_XPM_COLS);
    strncpy(xpm[3], "_ c #C311D6", WX_LED_XPM_COLS);
    strncpy(xpm[4], "* c #FFFFFF", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS], "X c ", WX_LED_XPM_COLS);
    strncpy((xpm[WX_LED_COLORS]) + 4, color.char_str(), 8);
    // pixels

    strncpy(xpm[WX_LED_COLORS + 1], "      -----------      ", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 2], "    ---------------    ", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 3], "   -----------------   ", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 4], "  -----XXXXXXXXX----_  ", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 5], " ----XXXX****XXXX-___ ", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 6], " ---XXX*****XXXXXXX___ ", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 7], "----XXX****XXXXXXXX____", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 8], "---XXX****XXXXXXXXXX___", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 9], "---XXXXXXXXXXXXXXXXXX___", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 10], "---XXXXXXXXXXXXXXXXX___", WX_LED_XPM_COLS);

    strncpy(xpm[WX_LED_COLORS + 11], "----XXXXXXXXXXXXXXX____", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 12], " ---XXXXXXXXXXXXXXX___ ", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 13], " ---_XXXXXXXXXXXXX____ ", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 14], "  _____XXXXXXXXX_____  ", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 15], "   _________________   ", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 16], "    _______________    ", WX_LED_XPM_COLS);
    strncpy(xpm[WX_LED_COLORS + 17], "      ___________      ", WX_LED_XPM_COLS);

    this->m_mutex.Lock();
    delete this->m_bitmap;
    this->m_bitmap = new wxBitmap(xpm);
    if (this->m_bitmap == NULL)
    {
        this->m_mutex.Unlock();
        goto end;
    }
    this->SetSize(wxSize(this->m_bitmap->GetWidth(), this->m_bitmap->GetHeight()));
    this->m_mutex.Unlock();
    this->Refresh();
end:
    delete[] xpm;
    delete[] xpmData;
}