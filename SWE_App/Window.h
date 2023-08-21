#pragma once
#include "wx/wx.h"


class Window : public wxFrame
{
public:
    Window();
    ~Window();

public:
    wxTextCtrl* textbox = nullptr;
    wxButton* button = nullptr;
    wxButton* clearButton = nullptr;
    wxButton* equalsButton = nullptr;

    void OnButtonClicked(wxCommandEvent& evt);
    void OnButtonClear(wxCommandEvent& evt);
    void OnButtonNegative(wxCommandEvent& evt);
    void OnButtonEquals(wxCommandEvent& evt);
    void OnCloseWindow(wxCloseEvent& evt);
    wxDECLARE_EVENT_TABLE();

    enum BUTTONS
    {
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        ZERO,
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        MODULUS,
        EQUALS,
        RIGHT,
        LEFT,
        NEGATIVE,
        COS,
        SIN,
        TAN,
        CLEAR
    };
};
