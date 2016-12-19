//David Durkin
//carnival.h

#include <math.h>
#include "gfx4.h"

void *move_r1(double *xrect1,double *yrect1,double degrees);
void *move_l1(double *xline1,double *yline1,double *xrect1,double *yrect1,double degrees);
void *move_spoke1(double *xspoke1, double *yspoke1, double *xline1, double *yline1, double 
spokedegrees, double line2length);
void *move_spoke2(double *xspoke2, double *yspoke2, double *xline1, double *yline1, double 
spokedegrees);
void *move_spoke3(double *xspoke3, double *yspoke3, double *xline1, double *yline1, double 
spokedegrees);

//Move main rectangle left and right and display it
void *move_r1(double *xrect1,double *yrect1,double degrees){

	*yrect1 = 350;
	*xrect1 = 350 + 100*cos(degrees);

    gfx_color(255,0,0);
    gfx_fill_rectangle(*xrect1-10, *yrect1-10, 20,20);

    return 0;
}

//Move the main line in a circle around the rectangle and display it
void *move_l1(double *xline1,double *yline1,double *xrect1,double *yrect1,double degrees){

	*yline1 = *yrect1 - 160*sin(degrees);
	*xline1 = *xrect1 - 160*cos(degrees);

    gfx_color(255,0,255);
    gfx_line(*xrect1, *yrect1, *xline1, *yline1);

    gfx_color(255,255,255);
    gfx_circle(*xline1, *yline1, 40);

    return 0;

}

//Move spoke1 around in a circle and display it
void *move_spoke1(double *xspoke1, double *yspoke1, double *xline1, double *yline1, double 
spokedegrees, double line2length){

	*xspoke1 = *xline1 - line2length*cos(spokedegrees);
	*yspoke1 = *yline1 + line2length*sin(spokedegrees);

    gfx_color(255,255,255);
    gfx_line(*xline1, *yline1, *xspoke1, *yspoke1);

    gfx_color(255,191,127);
    gfx_fill_rectangle(*xspoke1-10,*yspoke1,20,10);
    return 0;
}

//Move spoke2 around in a circle and display it
void *move_spoke2(double *xspoke2, double *yspoke2, double *xline1, double *yline1, double 
spokedegrees){

    *xspoke2 = *xline1 - 40*cos(spokedegrees+(2*M_PI/3));
    *yspoke2 = *yline1 + 40*sin(spokedegrees+(2*M_PI/3));

    gfx_color(0,255,0);
    gfx_line(*xline1, *yline1, *xspoke2, *yspoke2);
    return 0;
}

//Move spoke3 around in a circle and display it
void *move_spoke3(double *xspoke3, double *yspoke3, double *xline1, double *yline1, double 
spokedegrees){

    *xspoke3 = *xline1 - 40*cos(spokedegrees+(4*M_PI/3));
    *yspoke3 = *yline1 + 40*sin(spokedegrees+(4*M_PI/3));

	gfx_color(0,255,0);
    gfx_line(*xline1, *yline1, *xspoke3, *yspoke3);
    return 0;
}


