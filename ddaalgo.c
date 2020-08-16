#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
void ddanormal(int x1, int y1, int x2, int y2);
void ddadotted(int x1, int y1, int x2, int y2);
void ddashed(int x1, int y1, int x2, int y2);
int main()
{   int gd = DETECT, gm;
    int x1,x2,y1,y2,option;
    initgraph(&gd, &gm,"");
    initwindow(600,600);
    setbkcolor(BLACK);
    setcolor(WHITE);
    cleardevice();
    printf("\nDDA LINE ALGORITHM");
    printf("\nEnter the coordinates for the first point: ");
    scanf("%d %d",&x1,&y1);
    printf("Enter the ending coordinates: ");
    scanf("%d %d",&x2,&y2);
    printf("Enter the option:\n1 for thick\n2 for dotted \n3 for dashed\n");
    printf("Option: ");
    scanf("%d",&option);
    switch(option)
    { 
        case 1:
	        printf("DDA Thick lined");
	        ddanormal(x1,y1,x2,y2);
        break;
        case 2:
	        printf("DDA Dotted lined");
	        ddadotted(x1,y1,x2,y2);
        break;
        case 3:
	        printf("DDA Dashed line");
	        ddashed(x1, y1,x2,y2);
        break;
  }
  getevent();
  closegraph();
  return 0;
}

void ddanormal(int x1, int y1, int x2, int y2)
{   outtextxy(0,0,"DDA Normal");
    int i,dx,dy,steps;
    float x,y;
    float xinc,yinc;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx)>abs(dy))
	    steps = dx;
    else
	    steps = dy;
    xinc = (float) dx/steps;
    yinc = (float) dy/steps;
    x = x1;
    y = y1;
    putpixel(x,y,WHITE);
    for(i=1;i<steps;i++)
    {
        x += xinc;
        y += yinc;
        putpixel(x,y,WHITE);
    }
}

void ddadotted(int x1, int y1, int x2, int y2)
{ 
    outtextxy(0,0,"DDA dotted");
    int i,dx,dy,steps;
    float x,y;
    float xinc, yinc;
    dx = (x2 - x1);
    dy = (y2 - y1);
    if(abs(dx)>abs(dy))
	    steps = dx;
    else
	    steps = dy;
    xinc =(float) dx/steps;
    yinc =(float) dy/steps;
    x = x1;
    y = y1;
    putpixel(x,y,WHITE);
    for(i=0;i<=steps;i++)
    {   x += xinc;
        y += yinc;
        if(i%3 == 0)
	        putpixel(x,y,WHITE);
    }
}

void ddashed(int x1, int y1, int x2, int y2)
{  
    outtextxy(0,0,"DDA Dashed");
    int i,dx,dy,steps;
    float x,y,xinc,yinc;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx)>abs(dy))
	    steps = dx;
    else
	    steps = dy;
    xinc = (float)dx/steps;
    yinc = (float)dy/steps;
    x = x1;
    y = y1;
    putpixel(x,y,WHITE);
    for(i=0;i<= steps;i++)
    {   x += xinc;
        y += yinc;
        if(i%5 != 0)
	        putpixel(x,y,WHITE);
    }
 }


