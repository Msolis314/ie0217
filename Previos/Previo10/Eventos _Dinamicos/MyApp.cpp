#include "MyApp.hpp"
#include "MainFrame.hpp"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* frame = new MainFrame("Eventos Dinamicos");
	frame->Show(true);
	return true;
}