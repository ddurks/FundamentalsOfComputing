//Durkin and Joyce
//Flappy Bird n shit

#include "gfx4.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int drawBird(double, double, double, double);
void updateBird(double *, double *, double *, double, double, double);
void stationaryBird(double *, double);

int main(void){

	int width = 400;
	int height = 550;
	double r = 20;
	double x = 200;
	double y = 275;
	double v = 0;
	double t = .05;
	double degrees = 0;
	int flap = 0;

	gfx_open(width, height, "final.c");

	while(1){

		char c;

		//printf("%lf %lf\n",y,v);
		updateBird(&y,&v,&t,y,v,t);
		//stationaryBird(&y,degrees);
		gfx_color(255,255,255);
		gfx_fill_rectangle(0,0,400,550);
		flap = drawBird(x,y,r, flap);

		if(gfx_event_waiting()){

			c = gfx_wait();
			if(c=='q') break;

			if(c == ' '){
				v = -50;
			}

		}

		usleep(10000);
		gfx_clear();
		t+=.001;
		degrees+=(2*M_PI)/100;
	}
}

int drawBird(double x, double y, double r, int flap){

    gfx_color(255,255,0);
    gfx_fill_circle(x,y,r);

    gfx_color(0,0,0);
    gfx_circle(x,y,r+1);
    
    gfx_color(255,255,255);
    gfx_fill_circle(x+15,y-5,(0.45)*r);

    if(flap<=5){
    	gfx_fill_circle(x-18,y-4,(0.5)*r);
    	gfx_color(0,0,0);
		gfx_circle(x-18,y-4,(0.5)*r+1);
    	flap++;
    }
    else if( (flap>=5)&&(flap<=10) ){
    	gfx_fill_circle(x-18,y,(0.5)*r);
    	gfx_color(0,0,0);
		gfx_circle(x-18,y,(0.5)*r+1);
    	flap++;    	
    }
    else{
    	gfx_fill_circle(x-18,y+4,(0.5)*r);
    	gfx_color(0,0,0);
    	gfx_circle(x-18,y+4,(0.5)*r+1);
    	flap--;
    }
    
    gfx_fill_rectangle(x+19,y-7,3,7);
    gfx_circle(x+15,y-5,(0.45)*r+1);

    gfx_color(255,128,0);
    gfx_fill_rectangle(x+8,y+3,20,6);
    gfx_fill_rectangle(x+8,y+9,20,6);

    gfx_color(0,0,0);
    gfx_rectangle(x+8,y+9,20,6);
    gfx_rectangle(x+8,y+3,20,6);

    gfx_color(255,128,0);
    gfx_fill_rectangle(x+3,y+5,6,9);

    return flap;

}

void updateBird(double *y, double *v, double *t, double yval, double vval, double tval){

	double deltay;
	double vvalnew;

	deltay = vval*tval + (4.9)*pow(tval,2);
	yval = yval + deltay;
	vvalnew = vval + (10)*tval;

	if((vvalnew>=0&&vval<=0)||(vval>=0&&vvalnew<=0)){
		*t = .05;
	}

	*y = yval;
	*v = vvalnew;
}

void stationaryBird(double *y, double degrees){

	*y = 250 + 20*sin(degrees);

}




