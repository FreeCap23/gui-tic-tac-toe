#ifndef __BASE_H
#define __BASE_h

class MainApp: public wxApp
{
public:
    virtual bool OnInit();
};

class MainFrame: public wxFrame // Class of our window. Contains the window and all objects inside it
{
public:
    MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
    wxMenuBar *MainMenu;
    wxButton *unitButton;

    void Quit(wxCommandEvent& event);
    void Reset(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};
enum
{
    // Use this to declare the IDs of the objects
    MENU_Reset,
    MENU_Quit
};

#endif