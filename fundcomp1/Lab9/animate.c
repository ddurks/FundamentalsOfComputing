//animate.c
//animation involving circular motion, shapes, colors
//David Durkin

#include <stdio.h>
#include "gfx4.h"
#include <unistd.h>
#include <math.h>

int main(){

	int width = 500;
	int height = 500;
	double x_0 = 250;
	double y_0 = 250;
	double x;
	double y;
	double incr = .001;
	
	printf("Type 1, 2 or 3 on the keyboard to speed up/slow down the revolution.");
	
	gfx_open(width,height,"animate.c");

	double degree = .0005;

	while(1){

		gfx_clear();

		x = x_0 + 100*cos(degree);
		y = y_0 + 100*sin(degree);

		degree = degree + incr;

		gfx_color(0,255,0);
		gfx_circle(x,y,10);

		gfx_color(255,255,0);
		gfx_line(200,205,300,205);
		gfx_line(200,205,250,295);
		gfx_line(300,205,250,295);

		gfx_flush();
		usleep(300);

        if (gfx_event_waiting()){
        	char c = gfx_wait();
            	switch(c){
                	case '1': incr = .001; break;
                    case '2': incr = .003; break;
                    case '3': incr = .006; break;
    	    	}
        }
	}
}
