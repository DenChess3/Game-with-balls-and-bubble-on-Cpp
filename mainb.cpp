#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Box.H>
#include <iostream>
#include "classes.h"
#include "function.h"
using namespace std;

int main(int argc, char* argv[]) {
	double k = 1;
	// k = atof(argv[2]);
	const int fieldsize = 800;
	const int windowsizew = 1100;
	const int windowsizel = 800;
	//int n = atoi(argv[3]);
	int n = 7;

	//srand(atoi(argv[1]));
	Fl_Window window (windowsizew, windowsizel, nullptr);
	window.begin();
	Field* field = new Field(n, fieldsize);
	SpecialButtons* status = new SpecialButtons();
	field->putcallback(status);
	
	Fl_Button* go = new Fl_Button(0, 600, 300, 200, "GO!");
	go->labelsize(300 / 4);
	go->callback(Clickgo, (void*) field);
	
	
	window.end();
	window.show();
	Fl:: run();
	return 0;
};
