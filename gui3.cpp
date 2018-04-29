#include <iostream>
#include <nanogui/screen.h>
#include <nanogui/window.h>
#include <nanogui/layout.h>
#include <nanogui/button.h>
#include <nanogui/glutil.h>
#include <nanogui/label.h>
#include <nanogui/theme.h>
#include <nanogui/formhelper.h>
#include <nanogui/slider.h>
#include <Windows.h>
#include <nanogui/textbox.h>
#include <nanogui/vscrollpanel.h>
#include <nanogui/checkbox.h>
#include <nanogui/combobox.h>
#include <nanogui/progressbar.h>
#include <thread>
using namespace std;
using nanogui::Screen;
using nanogui::Window;
using nanogui::GroupLayout;
using nanogui::Button;
using nanogui::Vector2f;
using nanogui::MatrixXu;
using nanogui::MatrixXf;
using nanogui::Label;
using nanogui::TextBox;
using nanogui::Widget;
using nanogui::VScrollPanel;
using nanogui::CheckBox;
using nanogui::ComboBox;
using nanogui::ProgressBar;
std::string str1;
int b=0;

std::function<bool(const std::string& str)> f = [](std::string str) {
	
	
	std::cout << str<<std::endl;
	return true;
};

void gui_loop(void) {
	Screen *screen = nullptr;
	nanogui::init();
	std::cout << "gui launch" << std::endl;
	//create a screen
	screen = new Screen(nanogui::Vector2i(500, 700), "NanoGUI test");
	//create a formhelpler window
	nanogui::FormHelper *gui = new nanogui::FormHelper(screen);
	gui->addWindow(Eigen::Vector2i(10, 10), "Form helper example");
	gui->addGroup("New Group");
	bool is;
	gui->addVariable("bool", is);

	//create a window
	Window window{ screen, "window helper" };
	window.setPosition({ 15, 15 });
	window.setLayout(new GroupLayout(50, 50, 0, 0));

	//create an another window
	Window *win1 = new Window(screen, "new window ");
	win1->setLayout(new GroupLayout(50, 50, 0, 0));


	//create a textbox and set its property
	TextBox *text = new TextBox(win1, "gergerg");
	text->setEditable(true);
	std::string str1;
	/*text->setCallback([&str1](string str) {
	str1.clear();
	str1.append(str);
	std::cout<<str1<<std::endl;
	return true;
	});*/
	text->setCallback([text](string str) {

		std::cout << text->value() << std::endl;

		return true;
	});


	//create a checkbox and set its property
	CheckBox *checkbox = new CheckBox(win1, "check");
	checkbox->setChecked(true);
	checkbox->setCallback([checkbox](bool ischeck) {
		if (checkbox->checked()) {
			checkbox->setCaption("checked");
			
			std::cout << ischeck << std::endl;
		}
		else {
			checkbox->setCaption("unchecked");
			std::cout << ischeck << std::endl;
		}
	});

	//create a combobox and set its property
	std::vector<std::string> list;
	list.push_back(std::string("num1"));
	list.push_back(std::string("num2"));
	ComboBox *combo = new ComboBox(win1, list);
	combo->setBackgroundColor({ 255,255,0,255 });
	combo->setCallback([combo](int id) {
		if (id) {
			combo->setBackgroundColor({ 255,255,0,255 });
		}
		else {
			combo->setBackgroundColor({ 255,0,255,255 });
		}
	});
	combo->setTooltip("short tooltip");

	//create a progress bar
	ProgressBar *bar = new ProgressBar(win1);
	bar->setValue(0.5);




	//create a label and set its property
	Label *l = new Label(&window, "MODULATION", "sans-bold");
	l->setFontSize(20);


	//create a slider and set its property
	nanogui::Slider *slider = new nanogui::Slider(&window);
	std::pair<float, float> range(0, 1.0f);
	slider->setRange(range);
	slider->setHighlightColor({ 255,255,0,255 });
	slider->setValue(0);
	slider->setCallback([slider](float value) {
		std::cout << value << std::endl;
		std::pair<float, float> rangeh(0, value);
		slider->setHighlightedRange(rangeh);
	});
	
	int *a ;
	a = &b ;
	Button *button = new Button(&window, "test");
	button->setCallback([a]() {
		*a = *a + 1;
		std::cout << *a << std::endl;
	});
	button->setTooltip("short tooltip");


	//set screen property and perfomr layout
	screen->setVisible(true);
	screen->performLayout();
	screen->drawAll();

	nanogui::mainloop();
	nanogui::shutdown();
}




int main() {
	
	std::thread gui_thread(gui_loop);
	std::cout << "test" << std::endl;
	while (1) {

		std::cout << "test" << std::endl;
		std::cout << b <<std::endl;

	}
	gui_thread.join();
	return 0;
}