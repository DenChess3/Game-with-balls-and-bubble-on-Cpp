#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Box.H>
#include "function.h"
#include <iostream>
using namespace std;



class Cell {
	public:
	int x;
	int y;
	int size;
	int dir[2] = {0, 0};
	Fl_Button *button;
	Cell(const int& x = 0, const int& y = 0, const int& size = 0);
	Cell(const Cell& x);
	void changedir();
	virtual int type();
	bool infield(int n);
	~Cell();
};

class Round : public Cell {
	public:
	Round();
	Round(const Cell& x);
	virtual int type();
};

class Bubble : public Round {
	public:
	Bubble();
	Bubble(const Cell& x);
	virtual int type();
};

class Ball : public Round {
	public:
	Ball();
	Ball(const Cell& x);
	virtual int type();
};


class SpecialButtons {
	public:
	Fl_Radio_Button * rb[4];
	SpecialButtons();
	int mode();
};

class Field {
	public:
	int n; 
	Cell *** a;
	Field(const int& n, const int& fieldsize);
	void putcallback(SpecialButtons* status);
};


struct Help {
	Field* field;
	int xc, yc;
	SpecialButtons* s;
};
