/***************************************************************
 * Name:      svgnest_exampleApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Jacob Gustafson, and the wikihouseproject/SVGnest authors ()
 * Created:   2017-12-09
 * Copyright: Jacob Gustafson, and the wikihouseproject/SVGnest authors (http://www.expertmultimedia.com)
 * License:
 **************************************************************/

#include "svgnest_exampleApp.h"

//(*AppHeaders
#include "svgnest_exampleMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(svgnest_exampleApp);

bool svgnest_exampleApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    svgnest_exampleFrame* Frame = new svgnest_exampleFrame(0);
    Frame->Show();
    wxWindowList *parts = Frame.StatusBar1.GetChildren();
    parts[2].set
    SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
