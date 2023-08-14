#include "ButtonFactory.h"
#include "Window.h"

wxButton* ButtonFactory::CreateButton(Window* win, wxWindowID id, const wxString str, const wxPoint point, const wxSize size, const wxFont font)
{
    wxButton* button = new wxButton(win, id, str, point, size);
    button->SetFont(font);
    button->Bind(wxEVT_BUTTON, &Window::OnButtonClicked, win);
    return button;
}

wxButton* ButtonFactory::CreateClearButton(Window* win, wxWindowID id, const wxString str, const wxPoint point, const wxSize size)
{
    wxButton* button = new wxButton(win, id, str, point, size);
    button->Bind(wxEVT_BUTTON, &Window::OnButtonClear, win);
    return button;
}

wxButton* ButtonFactory::CreateEqualsButton(Window* win, wxWindowID id, const wxString str, const wxPoint point, const wxSize size)
{
    wxButton* button = new wxButton(win, id, str, point, size);
    button->Bind(wxEVT_BUTTON, &Window::OnButtonEquals, win);
    return button;
}

wxButton* ButtonFactory::CreateNegativeButton(Window* win, wxWindowID id, const wxString str, const wxPoint point, const wxSize size, const wxFont font)
{
    wxButton* button = new wxButton(win, id, str, point, size);
    button->SetFont(font);
    button->Bind(wxEVT_BUTTON, &Window::OnButtonNegative, win);
    return button;


}
