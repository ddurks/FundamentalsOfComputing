#include <stdio.h>
#include "gfx4.h"
#include <math.h>
#include <stdlib.h>

void draw_triangle(int, int, int, int, int, int);
void draw_square_shrink(double, double, double, double, double, double, double, double);
void draw_square_spiral(double, double, double);
void sierpinski(int, int, int, int, int, int);
void shrinking_squares(double, double, double, double, double, double, double, double);
void spiral_squares(double, double, double, double, double);
void circular_lace(double, double, double);
void snowflake(double, double, double, double);
void tree(double, double, double, double);
void fern(double, double, double, double);

int main(void){

	//Opens the window and sets the line color to white
	gfx_open(800,800,"fractals.c");
	gfx_color(255,255,255);

	while(1){

		char c;

		//clears the screen and draws new fractal
		if(gfx_event_waiting()){

			c = gfx_wait();
			gfx_clear();

		}
		
		//exits graphics window
		if (c=='q') break;

		//Calls proper function call following user input
		switch(c){

			case '1':
				sierpinski(100,100,700,100,400,700);
				break;
			case '2':
				shrinking_squares(200,200,600,200,600,600,200,600);
				break;
			case '3':
				spiral_squares(400,400,50,300,-(2.0*M_PI/9));
				break;
			case '4':
				circular_lace(400,400,250);
				break;
			case '5':
				snowflake(400,400,200,2.0*M_PI/4.0);
				break;
			case '6':
				tree(400,700,150,M_PI/2.0);
				break;
			case '7':
				fern(400,700,400,M_PI/2.0);
			}
		
	}
}

//Draws a triangle with given vertices
void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3){

	gfx_line(x1, y1, x2, y2);
	gfx_line(x2, y2, x3, y3);
	gfx_line(x3, y3, x1, y1);

}

//Draws a square with given vertices
void draw_square_shrink(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){

	gfx_line(x1,y1,x2,y2);
	gfx_line(x2,y2,x3,y3);
	gfx_line(x3,y3,x4,y4);
	gfx_line(x4,y4,x1,y1);

}

//Draws a square with a given center point
void draw_square_spiral(double x, double y, double size){

	gfx_line(x-size, y+size, x+size, y+size);
	gfx_line(x+size, y+size, x+size, y-size);
	gfx_line(x+size, y-size, x-size, y-size);
	gfx_line(x-size, y-size, x-size, y+size);

}

//Draws the Sierpinski triangle
void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{
   // Base case. 
   if( abs(x2-x1) < 2 ) return;

   // Draw the triangle
   draw_triangle( x1, y1, x2, y2, x3, y3 );

   // Recursive calls
   sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
   sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
   sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}

//Draws the shrinking squares fractal
void shrinking_squares(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){

	//Base case
	if( abs((int)(x2-x1)) < 1) return;

	//Draw the square
	draw_square_shrink(x1, y1, x2, y2, x3, y3, x4, y4);

	//Recursive calls
	shrinking_squares(x1-((x2-x1)/5), y1+((x2-x1)/5), x1+((x2-x1)/5), y1+((x2-x1)/5), x1+((x2-x1)/5), y1-((x2-x1)/5), x1-((x2-x1)/5), y1-((x2-x1)/5));
	shrinking_squares(x2-((x2-x1)/5), y2+((x2-x1)/5), x2+((x2-x1)/5), y2+((x2-x1)/5), x2+((x2-x1)/5), y2-((x2-x1)/5), x2-((x2-x1)/5), y2-((x2-x1)/5));
	shrinking_squares(x3-((x2-x1)/5), y3+((x2-x1)/5), x3+((x2-x1)/5), y3+((x2-x1)/5), x3+((x2-x1)/5), y3-((x2-x1)/5), x3-((x2-x1)/5), y3-((x2-x1)/5));
	shrinking_squares(x4-((x2-x1)/5), y4+((x2-x1)/5), x4+((x2-x1)/5), y4+((x2-x1)/5), x4+((x2-x1)/5), y4-((x2-x1)/5), x4-((x2-x1)/5), y4-((x2-x1)/5));

}

//Draws the spiral Squares fractal
void spiral_squares(double x, double y, double size, double dist, double degrees){

	//Base case
	if( size < .5 ) return;

	//Draw the square
	draw_square_spiral(x + dist*cos(degrees), y - dist*sin(degrees), size);

	//Recursive call
	spiral_squares(x, y, (.9)*size, (.9)*dist, degrees-(2.0*M_PI/9.0));
}

//draws the circular lace fractal
void circular_lace(double x, double y, double r){

	//angle variable
	double degrees = (2.0*M_PI/6.0);

	//base case
	if( r < .1) return;

	//draws circle
	gfx_circle(x, y, r);

	//recursive calls using multiple of the angle variable and the length variable
	circular_lace(x + r*cos(degrees), y + r*sin(degrees), .34*r);
	circular_lace(x + r*cos(2*degrees), y + r*sin(2*degrees), .34*r);
	circular_lace(x + r*cos(3*degrees), y + r*sin(3*degrees), .34*r);
	circular_lace(x + r*cos(4*degrees), y + r*sin(4*degrees), .34*r);
	circular_lace(x + r*cos(5*degrees), y + r*sin(5*degrees), .34*r);
	circular_lace(x + r*cos(6*degrees), y + r*sin(6*degrees), .34*r);
}

//draws the snowflake fractal
void snowflake(double x, double y, double r, double degrees){

	//incrementing angle variable
	double change = (2.0*M_PI/5.0);

	//base case
	if( r < 1 ) return;

	//draws the snowflake lines using the incrementing angle
	gfx_line(x, y, x+r*cos(degrees), y+r*sin(degrees));
	gfx_line(x, y, x+r*cos(degrees+change), y+r*sin(degrees+change));
	gfx_line(x, y, x+r*cos(degrees+2*change), y+r*sin(degrees+2*change));
	gfx_line(x, y, x+r*cos(degrees+3*change), y+r*sin(degrees+3*change));
	gfx_line(x, y, x+r*cos(degrees+4*change), y+r*sin(degrees+4*change));

	//recursive calls using the incrementing angle
	snowflake(x+r*cos(degrees), y+r*sin(degrees), .33333*r, degrees);
	snowflake(x+r*cos(degrees+change), y+r*sin(degrees+change), .33333*r, degrees);
	snowflake(x+r*cos(degrees+2.0*change), y+r*sin(degrees+ 2.0*change), .33333*r, degrees);
	snowflake(x+r*cos(degrees+3.0*change), y+r*sin(degrees+ 3.0*change), .33333*r, degrees);
	snowflake(x+r*cos(degrees+4.0*change), y+r*sin(degrees+ 4.0*change), .33333*r, degrees);

}

//draws the tree fractal
void tree(double x, double y, double len, double degrees){

	//base case
	if (len < 4) return;

	//incrementing angle
	double change = M_PI/5.0;

	//creates new x and y for other endpoints of line
	double x2 = x + len*cos(degrees);
	double y2 = y - len*sin(degrees);

	//draws line
	gfx_line(x, y, x2, y2);

	//recursive calls, adjusting angle with the incrementing angle
	tree(x2, y2, .75*len, degrees-change);
	tree(x2, y2, .75*len, degrees+change);
	
}

//draws the fern fractal
void fern(double x, double y, double len, double degrees){

	//base case
	if(len < 4) return;

	//incrementing angle
	double change = M_PI/6.0;

	//creates new x and y points for each 'branch'
	double x1 = x + (len/4)*cos(degrees);
	double y1 = y - (len/4)*sin(degrees);
	double x2 = x + (len/2)*cos(degrees);
	double y2 = y - (len/2)*sin(degrees);
	double x3 = x + (3.0*len/4)*cos(degrees);
	double y3 = y - (3.0*len/4)*sin(degrees);
	double x4 = x + (len)*cos(degrees);
	double y4 = y - (len)*sin(degrees);

	//draws the 'branches'
	gfx_line(x, y, x1, y1);
	gfx_line(x, y, x2, y2);
	gfx_line(x, y, x3, y3);
	gfx_line(x, y, x4, y4);

	//recursive calls
	fern(x1, y1, .333*len, degrees-change);
	fern(x1, y1, .333*len, degrees+change);
	fern(x2, y2, .333*len, degrees-change);
	fern(x2, y2, .333*len, degrees+change);
	fern(x3, y3, .333*len, degrees-change);
	fern(x3, y3, .333*len, degrees+change);
	fern(x4, y4, .333*len, degrees-change);
	fern(x4, y4, .333*len, degrees+change);
}








