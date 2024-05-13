#include <wx/wx.h>
class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
private:
	/// Eventos 
	//Deben recibir un wxCommandEvent
	void OnButtonClicked(wxCommandEvent& evt);
	void OnButtonClicked2(wxCommandEvent& evt);

	//Eventos para ejemplificar propagacion de eventos
	void OnAnyButtonClicked(wxCommandEvent& evt);
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);

	void OnSliderChanged(wxCommandEvent& evt);
	void OnTextChange(wxCommandEvent& evt);

	//Eventos del Mouse
	void OnMouseEvent(wxMouseEvent& evt);

	//Eventos del Teclado
	void OnKeyEvent(wxKeyEvent& evt);

	//Cerrar la aplicacion
	void OnClose(wxCloseEvent& evt);

};