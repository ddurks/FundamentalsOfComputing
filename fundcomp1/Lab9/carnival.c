//David Durkin
//carnvival.c
//Carnival Ride with 4 axes of motion

#include <stdio.h>
#include "gfx4.h"
#include "carnival.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

	int width = 700;
	int height = 700;

	//Coordinates of linearly moving rectangle
	double xrect1 = 350;
	double yrect1 = 350;

	//Coordinates of line rotating around moving rectangle
	double xline1 = 300;
	double yline1 = 350;

	//Coordinates of wheel spokes
	double xspoke1;
	double yspoke1;

	double xspoke2;
	double yspoke2;

	double xspoke3;
	double yspoke3;

	double spokedegrees = 0;

	double rectangledegrees = 0;

	double linedegrees = 0;

	double line2length = 50;

	int dir = 1;

	gfx_open(width,height,"carnival.c");

	//Places and moves shapes incrementally
	while(1){

		gfx_clear();

		move_r1(&xrect1, &yrect1, rectangledegrees);

		move_l1(&xline1, &yline1, &xrect1, &yrect1, linedegrees);

		move_spoke1(&xspoke1, &yspoke1, &xline1, &yline1, spokedegrees, line2length);
		move_spoke2(&xspoke2, &yspoke2, &xline1, &yline1, spokedegrees);
		move_spoke3(&xspoke3, &yspoke3, &xline1, &yline1, spokedegrees);

		spokedegrees += (2*M_PI / 1000);
		rectangledegrees += (2*M_PI / 4000);
		linedegrees += (2*M_PI / 2500);

		if(line2length<=50){
			dir = 1;
		}
		if(line2length>=100){
			dir = -1;
		}
		line2length += (double)dir*(60.0/2000.0);

		if(gfx_event_waiting()){
			char c = gfx_wait();
			if(c=='q') break;
		}

		gfx_flush();
		usleep(1500);

		return 0;

	}

}
