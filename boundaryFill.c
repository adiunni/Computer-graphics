#include<stdio.h>
#include<graphics.h>
#include<math.h>


void boundFill4(int x, int y, int fillColor, int borderColor)
{
    outtextxy(350,6,"BOUNDARY FILL 4 ALGORITHM");
    int interiorColor = getpixel(x,y);
    if((interiorColor != borderColor)&&(interiorColor != fillColor))
    {
        putpixel(x,y,fillColor);
        boundFill4(x+1,y,fillColor,borderColor);
        boundFill4(x-1,y,fillColor,borderColor);
        boundFill4(x,y+1,fillColor,borderColor);
        boundFill4(x,y-1,fillColor,borderColor);
    }
}

void boundFill8(int x, int y, int fillColor, int borderColor)
{
    outtextxy(350,16,"BOUNDARY FILL 8 ALGORITHM");
    int interiorColor = getpixel(x,y);
    if((interiorColor != borderColor)&&(interiorColor != fillColor))
    {
        putpixel(x,y,fillColor);
        boundFill8(x+1,y,fillColor,borderColor);
        boundFill8(x-1,y,fillColor,borderColor);
        boundFill8(x,y+1,fillColor,borderColor);
        boundFill8(x,y-1,fillColor,borderColor);
        boundFill8(x+1,y+1,fillColor,borderColor);
        boundFill8(x+1,y-1,fillColor,borderColor);
        boundFill8(x-1,y-1,fillColor,borderColor);
        boundFill8(x-1,y+1,fillColor,borderColor);
    }
}

void floodFill4 (int x, int y, int fillColor,int oldColor)
{
    outtextxy(350,26,"FLOOD FILL 4 ALGORITHM");
    if (getpixel(x, y) == oldColor)
    {
        setcolor(fillColor);
        putpixel(x, y,fillColor);
        floodFill4 (x,y+1, fillColor, oldColor);
        floodFill4 (x,y-1, fillColor, oldColor);
        floodFill4 (x+1,y, fillColor, oldColor);
        floodFill4 (x-1,y, fillColor, oldColor);
    }
}

void floodFill8(int x, int y, int fillColor, int oldColor)
{
    outtextxy(350,36,"FLOOD FILL 8 ALGORITHM");
    if (getpixel(x, y) == oldColor)
    {
        setcolor(fillColor);
        putpixel(x, y,fillColor);
        floodFill8(x+1,y,fillColor,oldColor);
        floodFill8(x-1,y,fillColor,oldColor);
        floodFill8(x,y+1,fillColor,oldColor);
        floodFill8(x,y-1,fillColor,oldColor);
        floodFill8(x+1,y+1,fillColor,oldColor);
        floodFill8(x+1,y-1,fillColor,oldColor);
        floodFill8(x-1,y+1,fillColor,oldColor);
        floodFill8(x-1,y-1,fillColor,oldColor);
    }
}

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    setbkcolor(BLACK);
    int x0, y0, r;
    cleardevice();
    printf("\nEnter the center of the circle: ");
    scanf("%d %d",&x0,&y0);
    printf("\nEnter the radius of the circle: ");
    scanf("%d",&r);

    getevent();
    circle(x0,y0,r);
    boundFill4(x0,y0,2,15);
    floodFill4(x0,y0,15,2);
    floodFill8(x0,y0,6,15);
    
    printf("\nThe circle is generated with the fill");
    closegraph();
    return 0;
}

