#include<graphics.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<dos.h>
#include<math.h>
using namespace std;

typedef long int LI;
void plot(LI x1,LI y1,LI cx,LI cy)
{ putpixel(cx+x1,cy+y1,WHITE);
  putpixel(cx+x1,cy-y1,WHITE);
  putpixel(cx-x1,cy-y1,WHITE);
  putpixel(cx-x1,cy+y1,WHITE);

}

int main()
{
 
   int gd = DETECT, gm;
  long int xc,yc,x,y,rx,ry;
   float p;
   
   cout<<"Enter coordinates of centre : ";
   cin>>xc>>yc;
   cout<<"Enter semi-major radius of ellipse: ";
   cin>>rx; cout<<"Enter semi-minor radius of ellipse: ";
   cin>>ry;
   initgraph(&gd, &gm, "");

   p=ry*ry-rx*rx*ry+rx*rx/4;
   x=0;y=ry;
   while(2.0*ry*ry*x <= 2.0*rx*rx*y)
   { plot(x,y,xc,yc);
     plot(y,x,xc,yc);
     plot((x+y)/sqrt(2),(y-x)/sqrt(2),xc,yc);
     plot((x-y)/sqrt(2),(y+x)/sqrt(2),xc,yc);
       x++;
	if(p < 0)
	{
	p+= 2*ry*ry*x+ry*ry;
	}
	else
	{
	 y--;
	 p+= 2*ry*ry*x-2*rx*rx*y+ry*ry;
	}
   }

   p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
   while(y >= 0)
   { plot(x,y,xc,yc);
     plot(y,x,xc,yc);
     plot((x+y)/sqrt(2),(y-x)/sqrt(2),xc,yc);
     plot((x-y)/sqrt(2),(y+x)/sqrt(2),xc,yc);
	   y--;
	if(p <= 0)
	{
	x++;
	p+=2*ry*ry*x-2*rx*rx*y+rx*rx;
	}
	else
	{
	   p = p-2*rx*rx*y+rx*rx;
	}

   }
   getch();

   
   return 0;
}
