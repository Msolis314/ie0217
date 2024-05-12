#include "MainFrame.hpp"
#include <wx/wx.h>
#include <wx/spinctrl.h>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	//Puntero al control de panel 
	//Ventana donde se posicionan otros controles
	//Recibe por param al padre
	//Abarca todo el main frame
	wxPanel* panel = new wxPanel(this);

	//lleva a quien pertenece, id , nombre, posicion basada en el padre
	// Se cuentan los pixeles desde la esquina izquierda
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35),wxBU_LEFT);

	//Caja para chequear
	wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox", 
		wxPoint(550, 55),wxDefaultSize,wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

	// -1 indica size por defecto
	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText-NOT editable", wxPoint(120, 150));
	staticText->SetBackgroundColour(*wxLIGHT_GREY);

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable",
		wxPoint(500, 145), wxSize(200, -1),wxTE_PASSWORD);
	//25 ( donde empiza), 0 (min) , 100 (max)
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1),wxSL_VALUE_LABEL);



	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1),wxGA_VERTICAL);

	gauge->SetValue(50);

	wxArrayString choices;
	choices.Add("Item A");
	choices.Add("Item B");
	choices.Add("Item C");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices,wxCB_SORT);
	choice->Select(0);

	//hay que incluir otro header para usarlo
	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY,"", wxPoint(550, 375), wxSize(100, -1),wxSP_WRAP);

	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices,wxLB_MULTIPLE);


	//Solo se puede seleccionar uno a la vez
	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox",
		wxPoint(485, 475), wxDefaultSize, choices,wxLB_MULTIPLE);	

}
