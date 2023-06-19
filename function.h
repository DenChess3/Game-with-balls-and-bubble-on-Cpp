#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Box.H>
#include "classes.h"
#include <iostream>
using namespace std;
class Field;
void clickerr(Fl_Widget* w, void*);
void windowerror(const char* err);
void Click (Fl_Widget* pb, void * h);
int** createwantlist(Field* field);
bool cango(int** wantlist, Field* field, int x, int y);
void ballgo(Field* field, int x, int y);
void burstbubble(Field* field, int x, int y);
void Clickgo (Fl_Widget* pb, void* f);

