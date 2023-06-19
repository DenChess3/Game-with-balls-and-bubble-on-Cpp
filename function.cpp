#include "function.h"
#include "classes.h"
#include <iostream>
using namespace std;

void clickerr(Fl_Widget* w, void*) {
	w->parent()->hide();
};

void windowerror(const char* err) {
	Fl_Window winerr(300, 150, "Error");
	winerr.begin();
	Fl_Box box(0, 0, 300, 100, err);
	Fl_Button ok(90, 100, 120, 50, "ok");
	ok.callback(clickerr, nullptr);
	winerr.end();
	winerr.show();
	Fl::run();
};


void Click (Fl_Widget* pb, void * h) {
	struct Help * help = new struct Help;
	help = (struct Help*) h;
	switch (help->s->mode()) {
		case 0: {// create ball
			if (help->field->a[help->xc][help->yc]->type() == 0) {
				Ball* tmp = new Ball;
				tmp->x = help->xc;
				tmp->y = help->yc;
				tmp->size = help->field->a[help->xc][help->yc]->size;
				tmp->button = (Fl_Button*)pb;
				tmp->button->color(FL_GREEN);
				tmp->button->label("ball");
				tmp->button->redraw();
				help->field->a[help->xc][help->yc] = tmp;	
			} else 
				windowerror("please, choose empty cell");
		} break;
		case 1: {// create bubble
			if (help->field->a[help->xc][help->yc]->type() == 0) {
				Bubble* tmp = new Bubble;
				tmp->x = help->xc;
				tmp->y = help->yc;
				tmp->size = help->field->a[help->xc][help->yc]->size;
				tmp->button = (Fl_Button*)pb;
				tmp->button->color(FL_BLUE);
				tmp->button->label("bubble");
				tmp->button->redraw();
				help->field->a[help->xc][help->yc] = tmp;
			} else
				windowerror("please, choose empty cell");
		} break;
		case 2: {// delete ball
			if (help->field->a[help->xc][help->yc]->type() == 2) {
				Cell* tmp = new Cell;
				tmp->x = help->xc;
				tmp->y = help->yc;
				tmp->size = help->field->a[help->xc][help->yc]->size;
				tmp->button = (Fl_Button*)pb;
				tmp->button->color(FL_WHITE);
				tmp->button->label("empty");
				tmp->button->redraw();
				help->field->a[help->xc][help->yc] = tmp;
			} else 
				windowerror("please, choose ball");
		} break;
		case 3: {// delete bubble
			if (help->field->a[help->xc][help->yc]->type() == 1) {
				Cell* tmp = new Cell;
				tmp->x = help->xc;
				tmp->y = help->yc;
				tmp->size = help->field->a[help->xc][help->yc]->size;
				tmp->button = (Fl_Button*)pb;
				tmp->button->color(FL_WHITE);
				tmp->button->label("empty");
				tmp->button->redraw();
				help->field->a[help->xc][help->yc] = tmp;
			} else 
				windowerror("please, choose bubble");
		} break;
	};
};

int** createwantlist(Field* field) {
	int** arr = new int*[field->n];
	for (int i = 0; i < field->n; i++)
		arr[i] = new int[field->n];
		
	for (int i = 0; i < field->n; i++)
		for (int j = 0; j < field->n; j++)
			arr[j][i] = 0;
	
	for (int i = 0; i < field->n; i++)
		for (int j = 0; j < field->n; j++)
			if (field->a[j][i]->type() != 0)
				if (field->a[j][i]->infield(field->n))
					arr[j + field->a[j][i]->dir[0]][i + field->a[j][i]->dir[0]] += 1;
				else 
					arr[j][i] += 1;
				
	return arr;			
};


bool cango(int** wantlist, Field* field, int x, int y) {
	bool f = false;
	int dirx = field->a[x][y]->dir[0], diry = field->a[x][y]->dir[1];
	if (dirx != 0 || diry != 0) {
		if (field->a[x][y]->infield(field->n))
			if (field->a[x + dirx][y + diry]->type() == 0 && wantlist[x + dirx][y + diry] <= 1)
				f = true;
			/*else
				f = cango(wantlist, field, x + dirx, y + diry);*/
	} else
		f = true;
	return f;
}

void ballgo(Field* field, int x, int y) {
	int dirx = field->a[x][y]->dir[0], diry = field->a[x][y]->dir[1];
	
	if (!field->a[x][y]->infield(field->n)) {
		field->a[x][y]->dir[0] = 0;
		field->a[x][y]->dir[1] = 0;
	} else {
	
	if (dirx != 0 || diry != 0) {
	
	if (field->a[x][y]->type() == 2) {
		Ball* tmp = new Ball;
		tmp->x = x + dirx;
		tmp->y = y + diry;
		tmp->size = field->a[x][y]->size;
		tmp->dir[0] = 0;
		tmp->dir[1] = 0;
		tmp->button = field->a[x + dirx][y + diry]->button;
		tmp->button->label("ball");
		tmp->button->color(FL_GREEN);
		field->a[x + dirx][y + diry] = tmp;
		
		Cell* tmp1 = new Cell; 
		tmp1->x = x;
		tmp1->y = y;
		tmp1->size = field->a[x][y]->size;
		tmp1->dir[0] = 0;
		tmp1->dir[1] = 0;
		tmp1->button = field->a[x][y]->button;
		tmp1->button->label("empty");
		tmp1->button->color(FL_WHITE);
		field->a[x][y] = tmp1;
		};
		
	if (field->a[x][y]->type() == 1) {
	
		Bubble* tmp = new Bubble;
		tmp->x = x + dirx;
		tmp->y = y + diry;
		tmp->size = field->a[x][y]->size;
		tmp->dir[0] = 0;
		tmp->dir[1] = 0;
		tmp->button = field->a[x + dirx][y + diry]->button;
		tmp->button->label("Bubble");
		tmp->button->color(FL_BLUE);
		field->a[x + dirx][y + diry] = tmp;
		
		Cell* tmp1 = new Cell; 
		tmp1->x = x;
		tmp1->y = y;
		tmp1->size = field->a[x][y]->size;
		tmp1->dir[0] = 0;
		tmp1->dir[1] = 0;
		tmp1->button = field->a[x][y]->button;
		tmp1->button->label("empty");
		tmp1->button->color(FL_WHITE);
		field->a[x][y] = tmp1;
	
	};
	
	};
	};
};

void burstbubble(Field* field, int x, int y) {
	Cell* tmp1 = new Cell; 
	tmp1->x = x;
	tmp1->y = y;
	tmp1->size = field->a[x][y]->size;
	tmp1->dir[0] = 0;
	tmp1->dir[1] = 0;
	tmp1->button = field->a[x][y]->button;
	tmp1->button->label("empty");
	tmp1->button->color(FL_WHITE);
	field->a[x][y] = tmp1;
};


void Clickgo (Fl_Widget* pb, void* f) {
	Field* field = (Field*) f;
	
	
	for (int i = 0; i < field->n; i++) //change direction
		for (int j = 0; j < field->n; j++)
			field->a[j][i]->changedir();
			
			
	for (int i = 0; i < field->n; i++) {
		for (int j = 0; j < field->n; j++) 
			std:: cout << field->a[j][i]->type()<< "," << field->a[j][i]->dir[0] << "," << field->a[j][i]->dir[1] << " ";
		std:: cout << endl;
	};
	
	int ** wantlist = createwantlist(field);
	
	for (int i = 0; i < field->n; i++)
		for (int j = 0; j < field->n; j++) {
			
			if (cango(wantlist, field, j, i)) {
				if (wantlist[ j + field->a[j][i]->dir[0] ][ i + field->a[j][i]->dir[1] ] > 1) {
					if (field->a[j][i]->type() == 1)
						burstbubble(field, j, i);
					else if (field->a[j][i]->type() == 2) {
						field->a[j][i]->dir[0] = (-1) * field->a[j][i]->dir[0];
						field->a[j][i]->dir[1] = (-1) * field->a[j][i]->dir[1];
					};
				} else 
					ballgo(field, j, i);
			};
					
		};
	
	delete[] wantlist;
	std::cout<<endl;
};
