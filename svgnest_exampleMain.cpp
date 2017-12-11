/***************************************************************
 * Name:      svgnest_exampleMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Jacob Gustafson, and the wikihouseproject/SVGnest authors ()
 * Created:   2017-12-09
 * Copyright: Jacob Gustafson, and the wikihouseproject/SVGnest authors (http://www.expertmultimedia.com)
 * License:
 **************************************************************/

#include "svgnest_exampleMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(svgnest_exampleFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(svgnest_exampleFrame)
const long svgnest_exampleFrame::idMenuQuit = wxNewId();
const long svgnest_exampleFrame::idMenuNest = wxNewId();
const long svgnest_exampleFrame::idMenuAbout = wxNewId();
const long svgnest_exampleFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(svgnest_exampleFrame,wxFrame)
    //(*EventTable(svgnest_exampleFrame)
    //*)
END_EVENT_TABLE()

svgnest_exampleFrame::svgnest_exampleFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(svgnest_exampleFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("svgnest-example"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,338));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, idMenuNest, _("Nest All Objects"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuBar1->Append(Menu3, _("Plater"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, wxST_SIZEGRIP|wxSIMPLE_BORDER, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[3] = { -80, -10, -10 };
    int __wxStatusBarStyles_1[3] = { wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL };
    StatusBar1->SetFieldsCount(3,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(3,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&svgnest_exampleFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&svgnest_exampleFrame::OnAbout);
    //*)
}

svgnest_exampleFrame::~svgnest_exampleFrame()
{
    //(*Destroy(svgnest_exampleFrame)
    //*)
}

void svgnest_exampleFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void svgnest_exampleFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
