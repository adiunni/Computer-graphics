#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
//#include "boundaryFill.c"

void animate(int x0,int y0,int r,int n)
{ 
    int i;
    for(i=0;i<n;i++)
    {   
        y0++;
        circle(x0,y0,r);
        floodfill(x0,y0,YELLOW); 
        delay(30);
        cleardevice();
    }
    printf("\nThe circle has been animated to a cylinder.");
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    int x0,y0,r,n;
    printf("Enter the circle coordinates: ");
    scanf("%d %d",&x0,&y0);
    printf("Enter the radius of the circle: ");
    scanf("%d",&r);
    printf("Enter the maximum coordinates to animate the polygon: ");
    scanf("%d",&n);
    getevent();
    circle(x0,y0,r);
    floodfill(x0,y0,WHITE);
    animate(x0,y0,r,n);
    closegraph();
    return 0;
}