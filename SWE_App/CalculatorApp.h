#pragma once
#include "wx/wx.h"

class Window;

class CalculatorApp : public wxApp
{

private:
    Window* window = nullptr;

public:
    CalculatorApp();
    ~CalculatorApp();
    virtual bool OnInit();
};
