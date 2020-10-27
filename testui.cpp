#include "ui_framework/MApplication.hpp"

class MainApp : public MApplication {
public:
	MainApp() : MApplication ("com.marinoland.testgui") {}
	void Ready(MGuiFactory *gui) {

		mainWindow = gui->window();
		//buttonBox = gui->buttonBox(*mainWindow);
		exitButton = gui->button(*mainWindow, "Clicky");
		exitButton->SetDimensions(100, 40);
		exitButton->SetPosition(295, 155);

		mainWindow->SetTitle("Super Window");
		mainWindow->SetDimensions(400, 200);
		mainWindow->Show();
		exitButton->OnClick([&] () { mainWindow->Close(); });
		mainWindow->OnResize([&] (int w, int h) {
			int width = 100, height = 100;
			mainWindow->GetClientRect(width, height);
			exitButton->SetPosition(width-105, height-45);
		 });
	}
private:
	MWindowRef mainWindow;
	//MButtonBoxRef buttonBox;
	MButtonRef exitButton;
};

RUN(MainApp)