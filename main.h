#ifndef __BASE_H
#define __BASE_h

class MainApp: public wxApp
{
public:
    virtual bool OnInit();
};

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
};

DECLARE_APP(MainApp)

#endif