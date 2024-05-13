#include "MyApp.hpp"
#include "MainFrame.hpp"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("C++ GUI");
	//mainFrame->SetClientSize(800,600);
	//mainFrame->Center();
	mainFrame->Show();
	return true;
}