#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
void eli(int x0, int y0,int rx, int ry);
int main()
{
    int gd= DETECT ,gm;
    initgraph(&gd,&gm,"");
    setbkcolor(BLACK);
    int x0,y0,rx,ry;
    cleardevice();
    printf("\nELLIPSE GENERATING ALGORITHM");
    printf("\nEnter the center points of the ellipse: ");
    scanf("%d %d",&x0,&y0);
    printf("Enter the semi major axis length and semi minor axis length: ");
    scanf("%d %d",&rx,&ry);
    eli(x0,y0,rx,ry);
    getevent();
    printf("OUTPUT HAS SHOWN");
    closegraph();
    return 0;
}

void eli(int x0, int y0, int rx, int ry)
{
    outtextxy(0,0,"ELLIPSE GENERATING ALGORITHM");
    int m,n,p1,p2;
    m = 0;
    n = ry;
    p1 = (ry)*(ry) - (rx)*(rx)*(ry) + (1/4)*(rx)*(rx);
    while((2*(ry)*(ry)*(m))<= (2*(rx)*(rx)*(n)))
    {
        if(p1<0)
        {
            m += 1;
            p1 += 2*ry*ry*m + ry*ry;
            putpixel(x0+m,y0+n,WHITE);
            putpixel(x0-m,y0+n,WHITE);
            putpixel(x0+m,y0-n,WHITE);
            putpixel(x0-m,y0-n,WHITE);
        }
        else
        {
            m += 1;
            n -= 1;
            p1 += 2*ry*ry*m - 2*rx*rx*n + ry*ry;
            putpixel(x0+m,y0+n,WHITE);
            putpixel(x0-m,y0+n,WHITE);
            putpixel(x0+m,y0-n,WHITE);
            putpixel(x0-m,y0-n,WHITE);
        }
    }
    p2 = ry*ry*(m+(1/2))*(m+(1/2)) + (rx*rx)*(n-1)*(n-1) - rx*rx*ry*ry;
    while(n>=0)
    {
        if(p2 >0)
        {
            n--;
            p2 += -(2*rx*rx*n) + (rx*rx);
            putpixel(x0+m,y0+n,WHITE);
            putpixel(x0-m,y0+n,WHITE);
            putpixel(x0+m,y0-n,WHITE);
            putpixel(x0-m,y0-n,WHITE);
        }
        else
        {
            m++;
            n--;
            p2 += (2*ry*ry*m) - (2*rx*rx*n) + (rx*rx);
            putpixel(x0+m,y0+n,WHITE);
            putpixel(x0-m,y0+n,WHITE);
            putpixel(x0+m,y0-n,WHITE);
            putpixel(x0-m,y0-n,WHITE);
        }
        
    }
}