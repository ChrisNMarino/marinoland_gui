#include "ui_framework/MApplication.hpp"

class MainApp : public MApplication {
public:
	MainApp() : MApplication ("com.marinoland.testgui") {}
	void Ready(MGuiFactory *gui) {

		gui->messageBox("Starting...", "Hello World");

		mainWindow = gui->window();
		setTitleButton = gui->button(*mainWindow, "Set Title");
		setTitleButton->SetDimensions(100, 40);
		exitButton = gui->button(*mainWindow, "Exit");
		exitButton->SetDimensions(100, 40);

		textBox = gui->textBox(*mainWindow);
		textBox->SetDimensions(300, 40);
		textBox->SetText("Hello World");

		mainWindow->SetTitle("Super Window");
		mainWindow->SetDimensions(600, 400);
		mainWindow->Show();

		int w, h;
		mainWindow->GetClientRect(w, h);
		setTitleButton->SetPosition(w-105, h-45);
		exitButton->SetPosition(5, 5);
		textBox->SetPosition(w-410, h-45);

		setTitleButton->OnClick([&] () {
			mainWindow->SetTitle(textBox->GetText().c_str());
		});
		exitButton->OnClick([&] () {
			gui->messageBox(*mainWindow, "Exit Clicked", "Goodbye!");
			mainWindow->Close();
		});
		mainWindow->OnResize([&] (int w, int h) {
			int width = 100, height = 100;
			mainWindow->GetClientRect(width, height);
			setTitleButton->SetPosition(width-105, height-45);
			textBox->SetPosition(width-410, height-45);
		});
	}
private:
	MWindowRef mainWindow;
	MButtonRef setTitleButton;
	MButtonRef exitButton;
	MTextBoxRef textBox;
};

RUN(MainApp)