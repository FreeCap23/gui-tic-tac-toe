// To compile, simply run this command
// g++ main.cpp `wx-config --libs` `wx-config --cxxflags` -o build/TicTacToe
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif
#include "main.h"
#include "gameLogic.h"
#include <iostream>

// Macro that tells wxWidgets to create an instance of MainApp
IMPLEMENT_APP(MainApp)

bool MainApp::OnInit()
{
    // Create an instance of our frame, or window
    MainFrame *MainWin = new MainFrame(
        _("Tic Tac Toe"), wxDefaultPosition, wxSize(500,500)
        );
    MainWin->Show(true); // Render the window
    SetTopWindow(MainWin); // Set it as the main window
    std::cout << "Initialized!\n";
    return true;
}

MainFrame::MainFrame(
    const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame((wxFrame *) NULL, -1, title, pos, size
    )
{   // Initialize objects here, i.e buttons and text boxes
    CreateStatusBar(1);
    MainMenu = new wxMenuBar();
    wxMenu *GameMenu = new wxMenu();
    MainMenu->Append(GameMenu, "&Game");
    GameMenu->Append(MENU_Reset, "&Reset", "Reset the game.");
    GameMenu->Append(MENU_Quit, "&Quit", "Quit the application.");

    SetMenuBar(MainMenu);

    // Create the 2D array of buttons
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int btnID = j * 10 + i;
            unitButton = new wxButton(this, btnID, unitArray[i][j].getState(), wxPoint(i*200,j*180), wxDefaultSize, 0,
            wxDefaultValidator);
            /* 200 and 180 are arbitrary numbers.
             * TODO: Make some kind of function that chooses
             * these two numbers based on the size of the window. */
        }
    }
}

void MainFrame::Quit(wxCommandEvent& event)
{
    Close(TRUE);
}

void MainFrame::Reset(wxCommandEvent& event)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            unitArray[i][j].reset();
}

void MainFrame::Place(wxCommandEvent& event)
{
    std::string id = std::to_string(event.GetId());
    if (id.length() == 1)
    {
        id.insert(0, 1, '0'); // Format the position to work with tryPlace()
    }
    std::cout << "Tried to place! " << id << std::endl;
    if (tryPlace(id, 'X') == 0) // 0 means the place was successful.
    {
        std::cout << "Placed\n";
    } 
    else 
    {
        std::cout << "Not Placed\n";
    }    
}