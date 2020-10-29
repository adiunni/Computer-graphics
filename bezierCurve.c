#include<stdio.h>
#include<graphics.h>
#include<math.h>

void bezierCurve(int x[4],int y[4])
{
    double xr,yr,t;
    for(t=0.0;t<1.0;t+=0.001)
    {
        xr = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*pow(t,2)*pow(1-t,1)*x[2] + pow(t,3)*x[3];
        yr = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*pow(t,2)*pow(1-t,1)*y[2] + pow(t,3)*y[3];
        putpixel((int)xr,(int)yr,RED);
    }
}

int main()
{
    int gd=DETECT,gm;
    int x[4],y[4],i;
    initgraph(&gd,&gm,"");
    initwindow(800,600);
    printf("\nEnter the 4 control points: ");
    for(i = 0;i<4;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    for(i = 0;i<4;i++)
    {
        putpixel(x[i],y[i],WHITE);
    }
    bezierCurve(x,y);
    getevent();
    closegraph();
    return 0;
}