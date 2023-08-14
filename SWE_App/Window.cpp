#include "Window.h"
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"

wxBEGIN_EVENT_TABLE(Window, wxFrame)
EVT_CLOSE(Window::OnCloseWindow)
wxEND_EVENT_TABLE()

#define WINDOW_WIDTH 390
#define WINDOW_HEIGHT 600

Window::Window() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200, 200), wxSize(WINDOW_WIDTH, WINDOW_HEIGHT)) {

	// Creates a font to apply it to textbox and buttons
	wxFont font(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	// Creates a textbox at the top of the window
	textbox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(20, 10), wxSize(330, 40));

	// Sets the font of the textbox
	textbox->SetFont(font);

	// Code calls the Button Factory to create buttons based on passed parameters
	// row 1
	ButtonFactory::CreateButton(this, SIN, "Sin", wxPoint(20, 60), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, COS, "Cos", wxPoint(105, 60), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, TAN, "Tan", wxPoint(190, 60), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, PLUS, "+", wxPoint(275, 60), wxSize(75, 75), font);
	// row 2
	ButtonFactory::CreateButton(this, ONE, "1", wxPoint(20, 140), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, TWO, "2", wxPoint(105, 140), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, THREE, "3", wxPoint(190, 140), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, MINUS, "-", wxPoint(275, 140), wxSize(75, 75), font);
	// row 3
	ButtonFactory::CreateButton(this, FOUR, "4", wxPoint(20, 220), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, FIVE, "5", wxPoint(105, 220), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, SIX, "6", wxPoint(190, 220), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, MULTIPLY, "*", wxPoint(275, 220), wxSize(75, 75), font);
	// row 4
	ButtonFactory::CreateButton(this, SEVEN, "7", wxPoint(20, 300), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, EIGHT, "8", wxPoint(105, 300), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, NINE, "9", wxPoint(190, 300), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, DIVIDE, "/", wxPoint(275, 300), wxSize(75, 75), font);
	//row 5
	ButtonFactory::CreateNegativeButton(this, NEGATIVE, "-/+", wxPoint(20, 380), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, ZERO, "0", wxPoint(105, 380), wxSize(75, 75), font);
	ButtonFactory::CreateClearButton(this, CLEAR, "C", wxPoint(190, 380), wxSize(75, 75));
	ButtonFactory::CreateButton(this, MODULUS, "%", wxPoint(275, 380), wxSize(75, 75), font);
	//row 6
	ButtonFactory::CreateEqualsButton(this, EQUALS, "=", wxPoint(20, 460), wxSize(160, 75));
	ButtonFactory::CreateButton(this, LEFT, "(", wxPoint(190, 460), wxSize(75, 75), font);
	ButtonFactory::CreateButton(this, RIGHT, ")", wxPoint(275, 460), wxSize(75, 75), font);


	// Avoids user from resizing the window and disables minize and maximize window buttons
	this->SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER) & ~(wxMAXIMIZE_BOX));
}

Window::~Window() {

}

void Window::OnButtonClicked(wxCommandEvent& evt)
{
	// Gets the button ID and stores it on a BUTTONS enumerator
	BUTTONS id = (BUTTONS)evt.GetId();

	switch (id)
	{
	case Window::ONE:
		textbox->AppendText("1");
		break;
	case Window::TWO:
		textbox->AppendText("2");
		break;
	case Window::THREE:
		textbox->AppendText("3");
		break;
	case Window::FOUR:
		textbox->AppendText("4");
		break;
	case Window::FIVE:
		textbox->AppendText("5");
		break;
	case Window::SIX:
		textbox->AppendText("6");
		break;
	case Window::SEVEN:
		textbox->AppendText("7");
		break;
	case Window::EIGHT:
		textbox->AppendText("8");
		break;
	case Window::NINE:
		textbox->AppendText("9");
		break;
	case Window::ZERO:
		textbox->AppendText("0");
		break;
	case Window::PLUS:
		textbox->AppendText("+");
		break;
	case Window::MINUS:
		textbox->AppendText("-");
		break;
	case Window::MULTIPLY:
		textbox->AppendText("*");
		break;
	case Window::DIVIDE:
		textbox->AppendText("/");
		break;
	case Window::MODULUS:
		textbox->AppendText("%");
		break;
	case Window::LEFT:
		textbox->AppendText("(");
		break;
	case Window::RIGHT:
		textbox->AppendText(")");
		break;
	case Window::SIN:
		textbox->AppendText("Sin");
		break;
	case Window::COS:
		textbox->AppendText("Cos");
		break;
	case Window::TAN:
		textbox->AppendText("Tan");
		break;
	}
	evt.Skip();
}

void Window::OnButtonClear(wxCommandEvent& evt)
{
	// Clears the textbox
	textbox->Clear();

	CalculatorProcessor::GetInstance()->ClearError();

	evt.Skip();
}

void Window::OnButtonNegative(wxCommandEvent& evt)
{
	std::string cal = "";
	cal.append(textbox->GetValue());
	for (int i = 0; i < cal.size(); i++)
	{
		if (cal[i] == '-' || cal[i] == '+' || cal[i] == '*' || cal[i] == '/' || cal[i] == '%')
		{
			if (cal[i + 1] == '-')
			{
				cal.erase(cal.begin() + i + 1);
				break;
			}
			else {
				cal.insert(i + 1, 1, '-');
				break;
			}
		}
	}
	textbox->Clear();
	textbox->AppendText(cal);
	evt.Skip();
}

void Window::OnButtonEquals(wxCommandEvent& evt)
{
	// Creates a string to store wxString value from textbox(convert it to std::string)
	std::string calculation = "";
	calculation.append(textbox->GetValue());

	// Calls the Singleton calculator processor instance along with method to calculate the passed string
	double total = CalculatorProcessor::GetInstance()->Calculate(calculation);

	// Stores the equation solution as a float


	wxString str;

	// Converts float to wxString to append it to the textbox
	str << total;

	// Clears the textbox and append updated calculation
	textbox->Clear();
	textbox->AppendText(str);

	// Clears the data in the tokens vector and output vector to avoid numbers to pile up and give incorrect calculations
	/*CalculatorProcessor::GetInstance()->ClearCalculator();*/

	evt.Skip();
}

void Window::OnCloseWindow(wxCloseEvent& evt)
{
	// Deletes the Singleton when closing main window to avoid memory leak
	delete CalculatorProcessor::GetInstance();
	evt.Skip();
}
