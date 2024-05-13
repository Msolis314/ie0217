#include <wx/wx.h>
class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
private:
	/// Eventos 
	//Deben recibir un wxCommandEvent
	void OnButtonClicked(wxCommandEvent& evt);
	void OnSliderChanged(wxCommandEvent& evt);
	void OnTextChange(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();

};