#include "classes.h"
#include "function.h"
#include <iostream>
using namespace std;

int Cell:: type() {
	return 0;
};

int Round:: type() {
	return -1;
};

int Bubble:: type() {
	return 1;
};

int Ball:: type() {
	return 2;
}

SpecialButtons:: SpecialButtons() {
	static const char * const name[] = { "create ball", "create bubble", "delete ball", "delete bubble"};
	for (int i = 0; i < 4; i++) {
		rb[i] = new Fl_Radio_Button(0, 150 * i, 300, 150, name[i]);
		rb[i]->labelsize(300 / 10);
	}
};

int SpecialButtons:: SpecialButtons:: mode() {
	int m = -1;
	for (int i = 0; i < 4; i++) 
		if (rb[i]->value())
			m = i;
	return m;
};


Cell:: Cell (const int& x, const int& y, const int& size): x(x), y(y), size(size) {
	button = new Fl_Button (300 + x * size, y * size, size, size, "empty");
	button->labelsize(size / 6);
	button->color(FL_WHITE);
	
};

Cell:: Cell(const Cell& c): x(c.x), y(c.y), size(c.size) {
	button = new Fl_Button(300 + c.x * size, c.y * size, c.size, c.size, "empty");
	button->labelsize(c.size / 6);
	button->color(FL_WHITE);
};

Round:: Round():Cell() {
	button->label("round");
	button->color(FL_RED);
};
	

Round:: Round(const Cell& x): Cell(x) {
	
};

Bubble:: Bubble(const Cell& x): Round(x) {

};

Bubble:: Bubble(): Round() {
	button->label("bubble");
	button->color(FL_BLUE);
};

Ball:: Ball(const Cell& x) {
};

Ball:: Ball(): Round() {
	button->label("ball");
	button->color(FL_GREEN);
};

Cell:: ~Cell() {
	delete button;
};



Field:: Field (const int& n, const int& fieldsize): n(n) {
	a = new Cell ** [n];
	int sizecell = fieldsize / n;
	for (int i = 0; i < n; i++) 
		a[i] = new Cell * [n];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			a[j][i] = new Cell (j, i, sizecell);
};


void Field:: putcallback(SpecialButtons* status) {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			struct Help* help = new struct Help;
			help->field = this;
			help->s = status;
			help->xc = j;
			help->yc = i;
			a[j][i]->button->callback(Click, (void*) help);
		};
};

void Cell:: changedir() {
	if (this->type() != 0) {
		dir[0] = -1 + rand() % 3;
		dir[1] = -1 + rand() % 3;
	};
};


bool Cell:: infield(int n) {
	return ((x + dir[0]) < n && (y + dir[1]) < n && (x + dir[0]) >= 0 && (y + dir[1]) >= 0);
};
