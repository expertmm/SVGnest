/***************************************************************
 * Name:      svgnest_exampleMain.h
 * Purpose:   Defines Application Frame
 * Author:    Jacob Gustafson, and the wikihouseproject/SVGnest authors ()
 * Created:   2017-12-09
 * Copyright: Jacob Gustafson, and the wikihouseproject/SVGnest authors (http://www.expertmultimedia.com)
 * License:
 **************************************************************/

#ifndef SVGNEST_EXAMPLEMAIN_H
#define SVGNEST_EXAMPLEMAIN_H

//(*Headers(svgnest_exampleFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class svgnest_exampleFrame: public wxFrame
{
    public:

        svgnest_exampleFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~svgnest_exampleFrame();

    private:

        //(*Handlers(svgnest_exampleFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(svgnest_exampleFrame)
        static const long idMenuQuit;
        static const long idMenuNest;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(svgnest_exampleFrame)
        wxMenu* Menu3;
        wxMenuItem* MenuItem3;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SVGNEST_EXAMPLEMAIN_H
