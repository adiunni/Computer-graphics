#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
static int l=1,r=2,b=4,t=8;
int getcode(int x, int y,int xwmax,int ywmax,int xwmin, int ywmin)
{
    int code=0;
    if(y>ywmax) code =t;
    if(y<ywmin) code =b;
    if(x<xwmin) code =l;
    if(x>xwmax) code =r;
    return code;
}
void cohsuth(int xwmin, int ywmin,int xwmax, int ywmax,int x1,int y1,int x2,int y2)
{
    outtext("COHEN-SUTHERLAND");
    int outcode1=getcode(x1,y1,xwmax,ywmax,xwmin,ywmin),outcode2=getcode(x2,y2,xwmax,ywmax,xwmin,ywmin);//Gives the region code for input lines.
    int x,y,temp;
    printf("%d %d",outcode1,outcode2);
    line(x1,y1,x2,y2);
    int accept=0; //A check condtion.
    while(1)
    {
        float m=(float)(y2-y1)/(x2-x1);
        if(outcode1==0 && outcode2==0) //Condtional operator
        {
            accept=1;
            break;
        }
        else if((outcode1 & outcode2)!=0) //Bitwise operator
        {
            printf("The line is completely outside the clipping border");
            break;
        }
        else
        {
            if(outcode1==0)
                temp=outcode2; //Sets the temporary variable to set region code.
            else
                temp=outcode1;
            if(temp & t) //Does the bitwise and operation with top(t)
            {
                x=x1+(ywmax-y1)/m; //Calculates the value of x and y.
                y=ywmax;
            }
            else if(temp & b) //Bitwise and operation with bottom(b)
            {
                x=x1+(ywmin-y1)/m;
                y=ywmin;
            }
            else if(temp & l) //Bitwise and operation with left.
            {
                x=xwmin;
                y=y1+(xwmin-x1)*m;
            }
            else if(temp & r) //Bitwise operation with right.
            {
                x=xwmax;
                y=y1+(xwmax-x1)*m;
            }
            if(temp==outcode1) //Check the corresponding value of temp.
            {
                x1=x; //Set the value of x back into x1
                y1=y; //Similar process back to y1
                outcode1=getcode(x1,y1,xwmax,ywmax,xwmin,ywmin);//Gets the region code for further operations.
            }
            else
            {
                x2=x; //Sets the value of x back to x2.
                y2=y; //Sets the value of y back to y2.
                outcode2=getcode(x2,y2,xwmax,ywmax,xwmin,ywmin); //Gets the region code for further operations.
            } 
        }   
    }  //Ultimately the value of accept becomes one and the while loop breaks.
    printf("\nx1=%d y1=%d x2=%d y2=%d",x1,y1,x2,y2);
    if(accept)
    {   
        setcolor(BLUE);
        line(x1,y1,x2,y2);
    }
    printf("\nThe following line has been clipped within the region co-ordinates");
}

void liabar(int xwmin, int ywmin,int xwmax, int ywmax,int x1,int y1,int x2,int y2)
{
    outtext("LIANG-BARSKY");
    int p[4],q[4],i,j,c,d;
    float r[4];
    float test1[4],test2[4];
    int dx=x2-x1;
    int dy=y2-y1;
    int x1n,y1n,x2n,y2n;
    float t1=0,t2=1;
    p[0]=-dx;
    p[1]=dx;
    p[2]=-dy;
    p[3]=dy;
    q[0]=x1-xwmin;
    q[1]=xwmax-x1;
    q[2]=y1-ywmin;
    q[3]=ywmax-y1;
    for(i=0;i<4;i++)
    {
        r[i]=(float)q[i]/(float)p[i];
    }

    for(c=0;c<4;c++)
    {
        printf("p: %d  q: %d  r: %f \n",p[c],q[c],r[c]);
    }

    for(d=0;d<4;d++)
    {
        if(p[d]==0)
        {
            if(q[d]<0)
            {   
                printf("The line is outside and parallel to boundary");
                break;
            }
            else
            {
                printf("Line is inside and parallel to boundary"); 
                break;
            }
        }
        else if(p[d]<0)
        {
            for(j=0;j<4;j++)
            {
                if(r[d]>t1)
                    t1=r[d];
            }
        }
        else if(p[d]>0)
        {
            for(j=0;j<4;j++)
            {
                if(r[d]<t2)
                    t2=r[d];
            }
        }
    }
    if(t1!=0)
    {
        x1n = x1 + t1*dx;
        y1n = y1 + t1*dy;
    }
    else
    {
        x1n=x1;
        y1n=y1;
    }
    printf("\nt1: %f x1: %d y1: %d",t1,x1n,y1n);
    if(t2!=1)
    {
        x2n = x1 + t2*dx;
        y2n = y1 + t2*dy;
    }
    else
    {
        x2n=x2;
        y2n=y2;
    }
    printf("\nt2: %f x2: %d y2: %d",t2,x2n,y2n);
    line(x1,y1,x2,y2);
    if((x1n!=x1) && (y1n != y1) && (x2n != x2) && (y2n != y2))
    {
        setcolor(RED);
        line(x1n,y1n,x2n,y2n);
    }
}
int main()
{
    int xwmin,ywmin,xwmax,ywmax;
    int x1,y1,x2,y2,option;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    printf("Enter the given window co-ordinates: ");
    scanf("%d %d %d %d",&xwmin,&ywmin,&xwmax,&ywmax);
    rectangle(xwmin,ywmin,xwmax,ywmax);
    printf("Enter the line coordinates: ");
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    printf("\n1.Cohen-Sutherland clipping algorithm");
    printf("\n2.Liang-Barsky clipping algorithm");
    printf("\n3.Exit");
    printf("\nEnter the option: ");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            cohsuth(xwmin,ywmin,xwmax,ywmax,x1,y1,x2,y2);
        break;
        case 2:
            liabar(xwmin,ywmin,xwmax,ywmax,x1,y1,x2,y2);
        break;
        case 3:
        break;
        default:
            printf("You have chosen the wrong option");
        break;
    }
    getevent();
    closegraph();
    return 0;
}
