#pragma once
#include "wx/wx.h"
#include "Window.h"

static class ButtonFactory

{
public:
    static wxButton* CreateButton(Window* win, wxWindowID id, const wxString str, const wxPoint point, const wxSize size, const wxFont font);
    static wxButton* CreateClearButton(Window* win, wxWindowID id, const wxString str, const wxPoint point, const wxSize size);
    static wxButton* CreateEqualsButton(Window* win, wxWindowID id, const wxString str, const wxPoint point, const wxSize size);
    static wxButton* CreateNegativeButton(Window* win, wxWindowID id, const wxString str, const wxPoint point, const wxSize size, const wxFont font);


};
