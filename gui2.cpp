/*
src/example2.cpp -- C++ version of an example application that shows
how to use the form helper class. For a Python implementation, see
'../python/example2.py'.

NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
The widget drawing code is based on the NanoVG demo application
by Mikko Mononen.

All rights reserved. Use of this source code is governed by a
BSD-style license that can be found in the LICENSE.txt file.
*/

#include <nanogui/nanogui.h>
#include <iostream>

using namespace nanogui;

enum test_enum {
	Item1 = 0,
	Item2,
	Item3
};
std::function<void()> f = []() { 
	std::cout << " button test" << std::endl;
	return 1; 
};

bool bvar = true;
int ivar = 5;
double dvar = 3.1415926;
float fvar = (float)dvar;
std::string strval = "A string";
test_enum enumval = Item2;
Color colval(0.5f, 0.5f, 0.7f, 1.f);

int main(int /* argc */, char ** /* argv */) {
	nanogui::init();

	/* scoped variables */ {
		bool use_gl_4_1 = false;// Set to true to create an OpenGL 4.1 context.
		Screen *screen = nullptr;

		if (use_gl_4_1) {
			// NanoGUI presents many options for you to utilize at your discretion.
			// See include/nanogui/screen.h for what all of these represent.
			std::cout << "use gl41" << std::endl;
			screen = new Screen(Vector2i(500, 700), "NanoGUI test [GL 4.1]",
				/*resizable*/true, /*fullscreen*/false, /*colorBits*/8,
				/*alphaBits*/8, /*depthBits*/24, /*stencilBits*/8,
				/*nSamples*/0, /*glMajor*/4, /*glMinor*/1);
		}
		else {
		
			screen = new Screen(Vector2i(500, 700), "NanoGUI test");
		}

		bool enabled = true;
		
		FormHelper *gui = new FormHelper(screen);
		ref<Window> window = gui->addWindow(Eigen::Vector2i(10, 10), "Form helper example");
		gui->addGroup("Basic types");
		gui->addVariable("bool", bvar);
		gui->addVariable("string", strval);
		gui->addVariable("string", std::string("game"));
		gui->addGroup("Validating fields");
		gui->addVariable("int", ivar)->setCallback([](const int &data) {
			std::cout << "int = " << data << std::endl;
		});
		
		
		gui->addVariable("double", dvar)->setSpinnable(true);

		gui->addGroup("Complex types");
		gui->addVariable("Enumeration", enumval, enabled)
			->setItems({ "Item 1", "Item 2", "Item 3" });
		
		gui->addVariable("Color", colval)
			->setFinalCallback([](const Color &c) {
			std::cout << "ColorPicker Final Callback: ["
				<< c.r() << ", "
				<< c.g() << ", "
				<< c.b() << ", "
				<< c.w() << "]" << std::endl;
		});

		gui->addGroup("Other widgets");
		gui->addButton("A button", []() { std::cout << "Button pressed." << std::endl; });
		//std::function<void(int)> a = f;
		ref<Button> button1 = gui->addButton("move",f);

		/*Widget *panel = new Widget(window);
		panel->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Middle, 0, 20));
		TextBox *textbox = new TextBox(panel);
		textbox->setFixedSize(Vector2i(60,25));
		textbox->setValue("50");
		textbox->setUnits("%");*/

		screen->setVisible(true);
		screen->performLayout();
		window->center();

		nanogui::mainloop();
	}

	nanogui::shutdown();
	return 0;
}
