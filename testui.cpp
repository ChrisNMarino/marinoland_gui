#include "ui_framework/MApplication.hpp"

class MainApp : public MApplication {
public:
	MainApp() : MApplication ("com.marinoland.testgui") {}
	void Ready(MGuiFactory *gui) {
		mainWindow = gui->window();
		buttonBox = gui->buttonBox();
		exitButton = gui->button("Clicky");

		buttonBox->AddChild(*exitButton);
		mainWindow->SetTitle("Super Window");
		mainWindow->SetDimensions(400, 200);
		mainWindow->AddChild(*buttonBox);
		mainWindow->Show();
		exitButton->OnClick([&] () { mainWindow->Close(); });
	}
private:
	MWindowRef mainWindow;
	MButtonBoxRef buttonBox;
	MButtonRef exitButton;
} Main;