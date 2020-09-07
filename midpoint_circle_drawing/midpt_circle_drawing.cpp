#include<iostream>
#include <stdio.h> 
#include <graphics.h> 
using namespace std;




void print_midpt(int xcenter, int ycenter, int x, int y) 
{ 
	putpixel(xcenter+x, ycenter+y, YELLOW); 
	putpixel(xcenter-x, ycenter+y, YELLOW); 
	putpixel(xcenter+x, ycenter-y, YELLOW); 
	putpixel(xcenter-x, ycenter-y, YELLOW); 
	putpixel(xcenter+y, ycenter+x, YELLOW); 
	putpixel(xcenter-y, ycenter+x, YELLOW); 
	putpixel(xcenter+y, ycenter-x, YELLOW); 
	putpixel(xcenter-y, ycenter-x, YELLOW); 
} 


void draw_midpt(int xcenter, int ycenter,int radius){
	int x,y;
	x=0;
	y=radius;
	
    print_midpt(xcenter, ycenter, x, y); 
	float d = (5/4) -  radius;
	while(y>=x){
	
		x++;
		if(d>0){
			y--;
			 d = d + 2 * (x - y) + 1;  
			 
			
		}
		else{
		
			d = d + (2 * x) + 1; 
			
		}
		print_midpt(xcenter, ycenter, x, y); 
			
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
	
	draw_midpt(xcenter,ycenter,radius);
	
	getch(); 
	return 0; 
} 
