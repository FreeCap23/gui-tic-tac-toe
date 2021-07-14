// To compile, simply run this command
// g++ main.cpp `wx-config --libs` `wx-config --cxxflags` -o build/TicTacToe
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif
#include "main.h"

IMPLEMENT_APP(MainApp) // Macro that tells wxWidgets to create an instance of MainApp

bool MainApp::OnInit()
{
    // Create an instance of our frame, or window
    MainFrame *MainWin = new MainFrame(_("Tic Tac Toe"), wxDefaultPosition, wxSize(300,300));
    MainWin->Show(true); // Render the window
    SetTopWindow(MainWin); // Set it as the main window
    return true;
}

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame((wxFrame *) NULL, -1, title, pos, size)
{
    // Initialize objects here, i.e buttons and text boxes
}