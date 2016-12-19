//Durkin and Joyce
//Flappy Bird n shit

#include "gfx4.h"
#include <stdio.h>
#include <math.h>

void draw_bird(double, double, double);
int bird_motion(double *, double, double);

int main(void){

	int width = 500;
	int height = 500;
	double r = 10;
	double x = 250;
	double y = 250;
	double v = 0;
	double t = 0;

	gfx_open(width, height, "final.c");

	while(1){

		char c;

		v = bird_motion(&y,v,t);
		draw_bird(x, y,r);

		if(gfx_event_waiting()){

			c = gfx_wait();
			if(c=='q') break;

		}

		t++;
	}
}

void draw_bird(double x, double y, double r){

	gfx_color(255,255,255);
	gfx_fill_circle(x,y,r);

}

int birt_motion(double *y, double v, double t){

	double deltay;
	double why = *y;

	deltay = (4.9)*pow(t,2) + (v)*(t);
	*y = why+deltay;

	v = v + (9.8)*(t);

	return v;
}