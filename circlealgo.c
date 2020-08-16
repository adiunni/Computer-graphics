#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>
void cir(int x0 , int y0 , int r);
int main()
{
    int gd = DETECT , gm;
    initgraph(&gd,&gm,"");
    setbkcolor(BLACK);
    int x0, y0, r;
    cleardevice();
    printf("CIRCLE GENERATING ALGORITHM");
    printf("\nEnter the center of the circle: ");
    scanf("%d %d",&x0,&y0);
    printf("\nEnter the radius of the circle: ");
    scanf("%d",&r);
    cir(x0,y0,r);
    getevent();
    closegraph();
    return 0;
}

void cir(int x0, int y0, int r)
{
    outtextxy(0,0,"CIRCLE GENERATING ALGORITHM");
    int p,m,n,x,y;
    m = 0;
    n = r;
    putpixel(x0,y0,WHITE);
    p = 1 - r;
    while(m<n)
    {
        if(p<0)
	        { 
                m += 1;
	            p += 2*m + 1;
	            putpixel(m+x0,n+y0,WHITE);
	            putpixel(-m+x0,-n+y0,RED);
	            putpixel(-m+x0,n+y0,CYAN);
	            putpixel(m+x0,-n+y0,GREEN);
	            putpixel(n+x0,m+y0,GREEN);
	            putpixel(-n+x0,-m+y0,MAGENTA);
	            putpixel(-n+x0,m+y0,BLUE);
	            putpixel(n+x0,-m+y0,YELLOW);
	        }
	    else
        	{ 
                m += 1;
	            n -= 1;
	            p += 2*m + 1 -2*n;
	            putpixel(m+x0,n+y0,WHITE);
	            putpixel(-m+x0,-n+y0,RED);
	            putpixel(-m+x0,n+y0,CYAN);
	            putpixel(m+x0,-n+y0,GREEN);
	            putpixel(n+x0,m+y0,GREEN);
	            putpixel(-n+x0,-m+y0,MAGENTA);
	            putpixel(-n+x0,m+y0,BLUE);
	            putpixel(n+x0,-m+y0,YELLOW);
	        }
    }
}