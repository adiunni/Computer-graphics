#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
void bresenham(int x1, int y1, int x2, int y2);
void bresdotted(int x1, int y1, int x2, int y2);
void bresdashed(int x1, int y1, int x2, int y2);
int main()
{
    int gd= DETECT ,gm;
    int x1,y1,x2,y2,option;
    initgraph(&gd,&gm,"");
    initwindow(700,700);
    setbkcolor(BLACK);
    cleardevice();
    printf("BRESENHAM's LINE ALGORITHM\n");
    printf("Enter the initial co-ordinates: ");
    scanf("%d %d",&x1,&y1);
    printf("\nEnter the final co-ordinates: ");
    scanf("%d %d",&x2,&y2);
    printf("###OPTIONS AVAILABLE###\n 1.Thick line\n 2.Dotted line\n 3.Dashed line\n");
    printf("Enter the option: ");
    scanf("%d",&option);
    switch(option)
    {   case 1:
            printf("Bresenham's normal");
	        bresenham(x1,y1,x2,y2);
        break;
        case 2:
            printf("Bresenham's dotted");
	        bresdotted(x1,y1,x2,y2);
        break;
        case 3:
            printf("Bresenham's dashed");
	        bresdashed(x1,y1,x2,y2);
        break;
    }
    getevent();
    closegraph();
    return 0;
}

void bresenham(int x1, int y1, int x2, int y2)
{ 
    outtextxy(0,0,"BRESENHAM'S NORMAL");
    int x,y,option,p,q,dx,dy,i;
    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;
    p = 2*dy - dx;
    q = 2*dx - dy;
    putpixel(x,y,WHITE);
    if(abs(dx)>abs(dy))
    {
        for(i=0;i<=dx;i++)
	    {   if ( p < 0 )
		    {   x++;
		        p += 2*dy;
		        putpixel(x,y,WHITE);
		    }
	        else
		    {   x++;
		        y++;
		        p += 2*dy -2*dx;
		        putpixel(x,y,WHITE);
		    }
	    }      
    }
    else
    {   for(i = 0 ; i<=dy;i++)
        {   if(q<0)
	        {   y++;
	            q += 2*dx;
	            putpixel(x,y,WHITE);
	        }
	        else
	        {   x++;
	            y++;
	            q += 2*dx -2*dy;
	            putpixel(x,y,WHITE);
	        }
        }
    }
    putpixel(x2,y2,WHITE);
    }

void bresdashed(int x1, int y1, int x2, int y2)
{ 
    outtextxy(0,0,"BRESENHAM'S DASHED");
    int x,y,option,p,q,dx,dy,i;
    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;
    p = 2*dy - dx;
    q = 2*dx - dy;
    putpixel(x,y,WHITE);
    if(abs(dx)>abs(dy))
    {
        for(i=0;i<=dx;i++)
	    {    
            if ( p < 0 )
		    {
                 x ++;
		        p += 2*dy;
		        if (i%4 != 0)
			        putpixel(x,y,WHITE);
            }    
	        else
		    {   x++;
		        y++;
		        p += 2*dy -2*dx;
		        if (i%4 != 0)
			    putpixel(x,y,WHITE);
		    }
	    }
    }
    else
    {   for(i = 0 ; i<=dy;i++)
        {
           if(q<0)
	        {
                y++;
	            q += 2*dx;
	            if(i%4 != 0)
		        putpixel(x,y,WHITE);
	        }
	        else
	        {
                x++;
	            y++;
	            q += 2*dx -2*dy;
	            if(i%4 != 0)
		            putpixel(x,y,WHITE);
	        }
        }
    }
    putpixel(x2,y2,WHITE);
}

void bresdotted(int x1, int y1, int x2, int y2)
{
    outtextxy(0,0,"BRESENHAM'S DOTTED");
    int x,y,option,p,q,dx,dy,i;
    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;
    p = 2*dy - dx;
    q = 2*dx - dy;
    putpixel(x,y,WHITE);
    if(abs(dx)>abs(dy))
    {
        for(i=0;i<=dx;i++)
	    {
            if ( p < 0 )
		    {
                x ++;
		        p += 2*dy;
		        if(i%3 == 0)
			    putpixel(x,y,WHITE);
		    }
	        else
		    {
                x++;
		        y++;
		        p += 2*dy -2*dx;
		        if(i%3 == 0)
			        putpixel(x,y,WHITE);
		    }
	    }
    }
    else
    {
        for(i = 0 ; i<=dy;i++)
        {
           if(q<0)
	        {  
                y++;
	            q += 2*dx;
	            if (i%3 ==0)
		            putpixel(x,y,WHITE);
	        }
	    else
	    {   
            x++;
	        y++;
	        q += 2*dx -2*dy;
	        if(i%3 == 0)
		        putpixel(x,y,WHITE);
	    }
    }
    }
    putpixel(x2,y2,WHITE);
}
