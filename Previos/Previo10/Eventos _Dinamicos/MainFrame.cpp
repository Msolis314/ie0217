#include "MainFrame.hpp"
#include <wx/wx.h>


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY,title) {
	
	
	// Crear un panel
	//Misma sintaxis que antes, pero ahora se agrega el ID
	wxPanel* panel = new wxPanel(this);
	//Evento del Mouse
	this->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseEvent, this);

	//Evento del Teclado
	this->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyEvent, this);

	//Evento del Mouse para detectar movimiento
	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	
	//Crear controles del panel
	wxButton* button = new wxButton(panel,wxID_ANY ,"Button", wxPoint(300, 275), wxSize(200, 50));
	wxSlider* slider = new wxSlider(panel,wxID_ANY , 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
	wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 375), wxSize(200, -1));

	//Conectar eventos
	//Se ligar el boton, cuando se presione (wxEVT_BUTTON) se ejecutara la funcion OnButtonClicked
	button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

	//Como la posicion es relativa se debe ligar el evento mouse al objeto
	button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);

	//Propagacion de eventos
	// Si existe un boton en el panel, se ejecutara el evento
	//panel->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	// Si en el frame se presiona un boton, se ejecutara el evento
	//this->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
	text->Bind(wxEVT_TEXT, &MainFrame::OnTextChange, this);

	//Como es dinamico, se puede desligar el evento
	button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

	// Crear barra de estado
	//Para evitar parpadeos
	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetDoubleBuffered(true);

	//Nuevo Panel
	//Ejemplo de propagacion de eventos I
	wxPanel* panel2 = new wxPanel(panel,wxID_ANY,wxPoint(400,0),wxSize(1000,1000),wxTAB_TRAVERSAL,"Propagacion Eventos I");
	panel2->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	wxButton* button1 = new wxButton(panel2, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));
	wxButton* button2 = new wxButton(panel2, wxID_ANY, "Button 2", wxPoint(300, 200), wxSize(200, 50));

	//Si cualquier boton en el panel2 es presionado, se ejecutara el evento
	panel2->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked2, this);
	
	//Nuevo panel
	//Ejemplo de propagacion de eventos II
	wxPanel* panel3 = new wxPanel(panel2, wxID_ANY, wxPoint(0, 200), wxSize(500, 500));
	panel3->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	wxButton* button3 = new wxButton(panel3, wxID_ANY, "Button 3", wxPoint(300, 275), wxSize(200, 50));
	wxButton* button4 = new wxButton(panel3, wxID_ANY, "Button 4", wxPoint(300, 200), wxSize(200, 50));

	//Si cualquier boton de panel3 es presionado, se ejecutara
	panel3->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);

	//Si el boton 3 es presionado, se ejecutara
	button3->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
	//Si el boton 4 es presionado, se ejecutara
	button4->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);

	//Si se cierra el frame, se ejecutara
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

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

void MainFrame::OnButtonClicked2(wxCommandEvent& evt) {
	//Se muestra un mensaje en la consola
	wxLogMessage("Button clicked 2");
}
void MainFrame::OnTextChange(wxCommandEvent& evt) {
	//Formatea como un string el valor del texto
	wxString str = wxString::Format("Text: %s", evt.GetString());
	//Muestra el valor en la status bar
	wxLogStatus(str);
	evt.Skip();

}

void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt) {
	wxLogMessage("Button Clicked");
	
}

void MainFrame::OnButton1Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button 1 Clicked");
	//Propagacion de eventos
	evt.Skip();
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt) {
	wxLogStatus("Button 2 Clicked");
}

void MainFrame::OnMouseEvent(wxMouseEvent& evt) {
	//Variable del tipo wxPoint que guarda la posicion del mouse
	//Obcion para obtener la posicion del mouse absoluta
	wxPoint mousePos = wxGetMousePosition();
	mousePos = this->ScreenToClient(mousePos); //Posicion relativa basada en el frame
	wxString message = wxString::Format("Mouse Event Detected! (x=%d, y=%d)", mousePos.x, mousePos.y);
	wxLogStatus(message);
}

void MainFrame::OnKeyEvent(wxKeyEvent& evt) {
	//Obtener el caracter de la tecla presionada
	wxChar keyChar = evt.GetUnicodeKey();

	//Si no se puede obtener el caracter, se obtiene el codigo de la tecla
	if (keyChar == WXK_NONE) {
		int keyCode = evt.GetKeyCode();
		wxLogStatus("Key Event %d", keyCode);
	}
	else {
		wxLogStatus("Key Event %c", keyChar);
	}
}

void MainFrame::OnClose(wxCloseEvent& evt) {
	//Mensaje en la consola
	wxLogMessage("Frame Close");
	//Cierra el frame
	//Se debe usar Skip para que el evento se propague
	evt.Skip();
}