#include<iostream>
#include<stdio.h> 
#include<graphics.h> 

int abs (int n) 
{ 
    return ( (n>0) ? n : ( n * (-1))); 
} 
  

void DDA_line(int X0, int Y0, int X1, int Y1) 
{ 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
   
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
  
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
  
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) 
    { 
        putpixel (X,Y,WHITE);  
        X += Xinc;           
        Y += Yinc;         
        delay(100);          
                             
    } 
} 

main()
{ 
	
    int gd, gm = DETECT; 
  
    // Initialize graphics function 
    initwindow(800,800)  ;
  
    int X0 = 100, Y0 = 100, X1 = 10, Y1 =10; 
    DDA_line(X0,Y0,X1,Y1); 
    getch();
}
