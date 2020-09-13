#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>

using namespace std;

void print(int xcenter, int ycenter, int x, int y, int color)
{
	putpixel(xcenter+x, ycenter+y, color);
	putpixel(xcenter-x, ycenter+y, color);
	putpixel(xcenter+x, ycenter-y, color);
	putpixel(xcenter-x, ycenter-y, color);
	putpixel(xcenter+y, ycenter+x, color);
	putpixel(xcenter-y, ycenter+x, color);
	putpixel(xcenter+y, ycenter-x, color);
	putpixel(xcenter-y, ycenter-x, color);
}

int color = 1;

void circl(int a, int b,int r){
    while(true){
        int x,y;
        x=0;
        y=r;
    print(a, b, x, y,color);
        float d = 1 -  r;
        int cnt = 0;
        while(y>=x){

            x++;
            if(d>0){
                y--;
                 d = d + 2 * (x - y) + 1;
            }
            else{

                d = d + (2 * x) + 1;

            }
            print(a, b, x, y,color);
            
            if(color==10)
            color=1;
            else
            color++;
        }

        delay(25);

    }

}
main(){
    int x, y, r;
    cout<<"Enter center coordinates";
    cin>>x>>y;
    cout<<"\nEnter radius:";
    cin>>r;
    initwindow(800,800);
    circl(x,y,r);
    getch();

}
