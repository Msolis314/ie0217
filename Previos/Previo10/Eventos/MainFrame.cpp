#include "MainFrame.hpp"
#include <wx/wx.h>


// IDs de los controles
/* Reg;as para los IDs
* 1. Deben ser positivos
* 2. No pueden ser 0 o 1
* 3. No deben ser de wxID_LOWEST ni wxID_HIGHEST
*/
enum IDs {
	BUTTON_ID = 1,
	SLIDER_ID = 3,
	TEXT_ID = 4
};

// Tabla de eventos
//Clase y de quien heredo
wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
//Evento, ID, Funcion
	EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
	EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderChanged)
	EVT_TEXT(TEXT_ID, MainFrame::OnTextChange)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY,title) {
	// Crear un panel
	//Misma sintaxis que antes, pero ahora se agrega el ID
	wxPanel* panel = new wxPanel(this);

	wxButton* button = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));
	wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
	wxTextCtrl* text = new wxTextCtrl(panel, TEXT_ID, "", wxPoint(300, 375), wxSize(200, -1));

	// Crear barra de estado
	CreateStatusBar();
}

void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	//Si se presiona el boton, se mostrara un mensaje en la status bar
	wxLogStatus("Button clicked");
}

void MainFrame::OnSliderChanged(wxCommandEvent& evt) {
	//Formatea como un string el valor del slider
	wxString str = wxString::Format("Slider value: %d", evt.GetInt());
	//Muestra el valor en la status bar
	wxLogStatus(str);
}

void MainFrame::OnTextChange(wxCommandEvent& evt) {
	//Formatea como un string el valor del texto
	wxString str = wxString::Format("Text: %s", evt.GetString());
	//Muestra el valor en la status bar
	wxLogStatus(str);
}