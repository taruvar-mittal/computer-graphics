#include<iostream>
#include <stdio.h> 
//#include <dos.h> 
#include <graphics.h> 
using namespace std;


void print(int xcenter, int ycenter, int x, int y) 
{ 
	putpixel(xcenter+x, ycenter+y, WHITE); 
	putpixel(xcenter-x, ycenter+y, WHITE); 
	putpixel(xcenter+x, ycenter-y, WHITE); 
	putpixel(xcenter-x, ycenter-y, WHITE); 
	putpixel(xcenter+y, ycenter+x, WHITE); 
	putpixel(xcenter-y, ycenter+x, WHITE); 
	putpixel(xcenter+y, ycenter-x, WHITE); 
	putpixel(xcenter-y, ycenter-x, WHITE); 
} 

void draw(int xcenter, int ycenter, int radius) 
{ 
	int x = 0;
	int y = radius; 
	int d = 3 - 2 * radius; 
	print(xcenter, ycenter, x, y); 
	x++;
	y--;
	while (y >= x) 
	{ 
		
		if (d > 0) 
		{ 
			d = d + 4 * (x - y) + 10; 
			y--;
		} 
		else
			d = d + 4 * x + 6; 
			
		print(xcenter, ycenter, x, y); 
		
		x++;
//		delay(20);
	} 
} 



int main() 
{ 
	int xcenter,ycenter,radius;
	cout<<"enter center coordinates"<<endl;
	cin>>xcenter>>ycenter;
	cout<<"enter radius"<<endl;
	cin>>radius;
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, ""); 
	draw(xcenter, ycenter, radius);
	
	getch(); 
	return 0; 
} 

