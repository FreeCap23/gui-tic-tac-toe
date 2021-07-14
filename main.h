#ifndef __BASE_H
#define __BASE_h

class MainApp: public wxApp
{
public:
    virtual bool OnInit();
};

// Class of our window. Contains the window and all objects inside it
class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
    wxMenuBar *MainMenu;
    wxButton *unitButton[3][3];

    void Quit(wxCommandEvent& event);
    void Reset(wxCommandEvent& event);
    void Place(wxCommandEvent& event);
    DECLARE_EVENT_TABLE()
};

enum
{   // Use this to declare the IDs of the objects
    MENU_Reset = 30,
    MENU_Quit = 31,
    GAME_Unit = 1
};

BEGIN_EVENT_TABLE ( MainFrame, wxFrame )
EVT_MENU ( MENU_Quit, MainFrame::Quit )
EVT_MENU ( MENU_Reset, MainFrame::Reset )
EVT_BUTTON ( wxID_ANY, MainFrame::Place )
END_EVENT_TABLE()

#endif