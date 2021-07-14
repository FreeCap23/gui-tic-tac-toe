// To compile, simply run this command
// g++ main.cpp `wx-config --libs` `wx-config --cxxflags` -o build/TicTacToe
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif
#include "main.h"
#include "gameLogic.h"
#include <iostream>

BEGIN_EVENT_TABLE ( MainFrame, wxFrame )
END_EVENT_TABLE()

IMPLEMENT_APP(MainApp) // Macro that tells wxWidgets to create an instance of MainApp

bool MainApp::OnInit()
{
    // Create an instance of our frame, or window
    MainFrame *MainWin = new MainFrame(_("Tic Tac Toe"), wxDefaultPosition, wxSize(500,500));
    MainWin->Show(true); // Render the window
    SetTopWindow(MainWin); // Set it as the main window
    return true;
}

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
                    : wxFrame((wxFrame *) NULL, -1, title, pos, size)
{   // Initialize objects here, i.e buttons and text boxes
    CreateStatusBar(1);
    MainMenu = new wxMenuBar();
    wxMenu *GameMenu = new wxMenu();
    MainMenu->Append(GameMenu, "&Game");
    GameMenu->Append(MENU_Reset, "&Reset", "Reset the game.");
    GameMenu->Append(MENU_Quit, "&Quit", "Quit the application.");

    SetMenuBar(MainMenu);

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            int btnArrID[2] = {i,j};
            int btnID = i*10+j;
            unitButton = new wxButton(this, btnID, "sktr", wxPoint(i*200,j*180));
        }
    }
}

void MainFrame::Quit ( wxCommandEvent& event ){
    Close(true);
}