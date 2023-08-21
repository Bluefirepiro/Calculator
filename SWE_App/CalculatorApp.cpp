#include "CalculatorApp.h"
#include "Window.h"

wxIMPLEMENT_APP(CalculatorApp);

CalculatorApp::CalculatorApp() {

}

CalculatorApp::~CalculatorApp() {

}

bool CalculatorApp::OnInit() {
    window = new Window();
    window->Show();
    return true;
}
