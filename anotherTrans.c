#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>

void matrixMultiply(int a[3][3],int b[3][3],int c[3][3]) //Integer matrix multiplication
{
    for (int i = 0; i < 3; ++i) //To turn garbage value of the resultant matrix into null matrix.
    {
        for (int j = 0; j < 3; ++j) 
        {
            c[i][j] = 0;
        }
    }

    int i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           for(k=0;k<3;k++)
           {
                c[i][j] += (b[i][k]*a[k][j]); //k is used to equate rows and columns.
           }
        }
    }
}

void matrixMultiply2(double a[3][3],double b[3][3],double c[3][3]) //Double value matrix multiplication
{
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            c[i][j] = 0;
        }
    }

    int i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           for(k=0;k<3;k++)
           {
                c[i][j] += (b[i][k]*a[k][j]);
           }
        }
    }
}

void translateFn(int p[3][3],int tx, int ty) //Translation function
{
    int t[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};
    int p1[3][3];
    int x = getmaxx()/2; 
    int y = getmaxy()/2;
    line(x,0,x,y);  //Lines are used to split the co-ordinate systems.
    line(0,y,x,y);  
    line(x,y,getmaxx(),y);
    line(x,y,x,getmaxy());
    setcolor(WHITE);
    outtextxy(350,5,"INITIAL COORDINATES");
    line(p[0][0]+x,p[1][0]+y,p[0][1]+x,p[1][1]+y); //Initial triangle coordinates.
    line(p[0][1]+x,p[1][1]+y,p[0][2]+x,p[1][2]+y);
    line(p[0][2]+x,p[1][2]+y,p[0][0]+x,p[1][0]+y);
    matrixMultiply(p,t,p1);
    setcolor(RED);
    outtextxy(350,15,"TRANSLATED TRIANGLE");
    line(p1[0][0]+x,p1[1][0]+y,p1[0][1]+x,p1[1][1]+y); //Final triangle co-ordinates.
    line(p1[0][1]+x,p1[1][1]+y,p1[0][2]+x,p1[1][2]+y); 
    line(p1[0][2]+x,p1[1][2]+y,p1[0][0]+x,p1[1][0]+y); 
}

void genTrans(int p[3][3],int fx,int fy,int p1[3][3]) //General translation for scaling
{
    int f[3][3]={{1,0,fx},{0,1,fy},{0,0,1}};
    matrixMultiply(p,f,p1);
}

void genTrans1(double p[3][3],double fx,double fy,double p1[3][3]) //General translation for rotation
{
    double f[3][3]={{1,0,fx},{0,1,fy},{0,0,1}};
    matrixMultiply2(p,f,p1);
}

void scaleFn(int p[3][3], int sx, int sy)  //Scaling function
{
    int s[3][3] ={{sx,0,0},{0,sy,0},{0,0,1}};
    int p1[3][3],p2[3][3],p3[3][3];
    int x = getmaxx()/2;
    int y = getmaxy()/2;
    line(x,0,x,y);
    line(0,y,x,y);
    line(x,y,getmaxx(),y);
    line(x,y,x,getmaxy());
    int fx,fy;
    printf("Enter fixed point co-ordinates: ");
    scanf("%d %d",&fx,&fy);
    setcolor(WHITE);
    outtextxy(350,5,"INITIAL COORDINATES");
    line(p[0][0]+x,p[1][0]+y,p[0][1]+x,p[1][1]+y);
    line(p[0][1]+x,p[1][1]+y,p[0][2]+x,p[1][2]+y);
    line(p[0][2]+x,p[1][2]+y,p[0][0]+x,p[1][0]+y);
    genTrans(p,-fx,-fy,p2);
    matrixMultiply(p2,s,p3);
    genTrans(p3,fx+x,fy+y,p1);
    setcolor(BLUE);
    outtextxy(350,15,"SCALED TRIANGLE");
    line(p1[0][0],p1[1][0],p1[0][1],p1[1][1]);
    line(p1[0][1],p1[1][1],p1[0][2],p1[1][2]);
    line(p1[0][2],p1[1][2],p1[0][0],p1[1][0]); 
}

void rotateFn(int p[3][3],double theta)  //Rotation function
{
    double r[3][3] ={{cos(theta*3.14/180),-sin(theta*3.14/180),0},{sin(theta*3.14/180),cos(theta*3.14/180),0},{0,0,1}};
    int p1[3][3];
    double p0[3][3],p2[3][3],p3[3][3],p4[3][3];
    double fx, fy;
    int i,j;
    int x = getmaxx()/2;
    int y = getmaxy()/2;
    line(x,0,x,y);
    line(0,y,x,y);
    line(x,y,getmaxx(),y);
    line(x,y,x,getmaxy());
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            p0[i][j]=p[i][j];
        }
    }
    printf("Enter fixed point co-ordinates: ");
    scanf("%lf %lf",&fx,&fy);
    setcolor(WHITE);
    outtextxy(350,5,"INITIAL COORDINATES");
    line(p[0][0]+x,p[1][0]+y,p[0][1]+x,p[1][1]+y);
    line(p[0][1]+x,p[1][1]+y,p[0][2]+x,p[1][2]+y);
    line(p[0][2]+x,p[1][2]+y,p[0][0]+x,p[1][0]+y);
    genTrans1(p0,-fx,-fy,p2);
    matrixMultiply2(p2,r,p3);
    genTrans1(p3,fx,fy,p4);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            p1[i][j]=p4[i][j];
        }
    }
    setcolor(GREEN);
    outtextxy(350,15,"ROTATED TRIANGLE");
    line(p1[0][0]+x,p1[1][0]+y,p1[0][1]+x,p1[1][1]+y);
    line(p1[0][1]+x,p1[1][1]+y,p1[0][2]+x,p1[1][2]+y);
    line(p1[0][2]+x,p1[1][2]+y,p1[0][0]+x,p1[1][0]+y); 
}

void reflect(int p[3][3],long int m,int c) //General line reflection function
{
    int p1[3][3];
    int p2[3][3];
    int ref3[3][3]= {{(1-m*m)/(1+m*m),2*m/(1+m*m),-2*c*m/(1+m*m)},{2*m/(1+m*m),(m*m -1)/(1+m*m),2*c/(1+m*m)},{0,0,1}};
    int x = getmaxx()/2;
    int y = getmaxy()/2;
    line(x,0,x,y);
    line(0,y,x,y);
    line(x,y,getmaxx(),y);
    line(x,y,x,getmaxy());
    setcolor(WHITE);
    outtextxy(350,5,"INITIAL COORDINATES");
    line(p[0][0]+x,p[1][0]+y,p[0][1]+x,p[1][1]+y);
    line(p[0][1]+x,p[1][1]+y,p[0][2]+x,p[1][2]+y);
    line(p[0][2]+x,p[1][2]+y,p[0][0]+x,p[1][0]+y);
    matrixMultiply(p,ref3,p2);
    genTrans(p2,x,y,p1);
    setcolor(YELLOW);
    outtextxy(350,15,"REFLECTED TRIANGLE");
    line(p1[0][0],p1[1][0],p1[0][1],p1[1][1]);
    line(p1[0][1],p1[1][1],p1[0][2],p1[1][2]);
    line(p1[0][2],p1[1][2],p1[0][0],p1[1][0]); 
}

void reflecty(int p[3][3]) //Reflection w.r.t. y-axis function
{
    int p1[3][3];
    int p2[3][3];
    int ref[3][3]= {{-1,0,0},{0,1,0},{0,0,1}};
    int x = getmaxx()/2;
    int y = getmaxy()/2;
    line(x,0,x,y);
    line(0,y,x,y);
    line(x,y,getmaxx(),y);
    line(x,y,x,getmaxy());
    setcolor(WHITE);
    outtextxy(350,5,"INITIAL COORDINATES");
    line(p[0][0]+x,p[1][0]+y,p[0][1]+x,p[1][1]+y);
    line(p[0][1]+x,p[1][1]+y,p[0][2]+x,p[1][2]+y);
    line(p[0][2]+x,p[1][2]+y,p[0][0]+x,p[1][0]+y);
    matrixMultiply(p,ref,p2);
    genTrans(p2,x,y,p1);
    setcolor(YELLOW);
    outtextxy(350,15,"REFLECTED TRIANGLE");
    line(p1[0][0],p1[1][0],p1[0][1],p1[1][1]);
    line(p1[0][1],p1[1][1],p1[0][2],p1[1][2]);
    line(p1[0][2],p1[1][2],p1[0][0],p1[1][0]); 
}

void reflecto(int p[3][3])  //Reflection w.r.t. origin function.
{
    int p1[3][3];
    int p2[3][3];
    int ref[3][3]= {{-1,0,0},{0,-1,0},{0,0,1}};
    int x = getmaxx()/2;
    int y = getmaxy()/2;
    line(x,0,x,y);
    line(0,y,x,y);
    line(x,y,getmaxx(),y);
    line(x,y,x,getmaxy());
    setcolor(WHITE);
    outtextxy(350,5,"INITIAL COORDINATES");
    line(p[0][0]+x,p[1][0]+y,p[0][1]+x,p[1][1]+y);
    line(p[0][1]+x,p[1][1]+y,p[0][2]+x,p[1][2]+y);
    line(p[0][2]+x,p[1][2]+y,p[0][0]+x,p[1][0]+y);
    matrixMultiply(p,ref,p2);
    genTrans(p2,x,y,p1);
    setcolor(YELLOW);
    outtextxy(350,15,"REFLECTED TRIANGLE");
    line(p1[0][0],p1[1][0],p1[0][1],p1[1][1]);
    line(p1[0][1],p1[1][1],p1[0][2],p1[1][2]);
    line(p1[0][2],p1[1][2],p1[0][0],p1[1][0]);    
}

void shearx(int p[3][3],int yref, int shx) //Shearing with a y-reference line
{
    int shrx[3][3] = {{1,shx,-shx*yref},{0,1,0},{0,0,1}};
    int p1[3][3];
    int x = getmaxx()/2;
    int y = getmaxy()/2;
    line(x,0,x,y);
    line(0,y,x,y);
    line(x,y,getmaxx(),y);
    line(x,y,x,getmaxy());
    setcolor(WHITE);
    outtextxy(350,5,"INITIAL COORDINATES");
    line(p[0][0]+x,p[1][0]+y,p[0][1]+x,p[1][1]+y);
    line(p[0][1]+x,p[1][1]+y,p[0][2]+x,p[1][2]+y);
    line(p[0][2]+x,p[1][2]+y,p[0][0]+x,p[1][0]+y);
    matrixMultiply(p,shrx,p1);
    for(int i =0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf(" %d",p1[i][j]);
        }
        printf("\n");
    }
    setcolor(MAGENTA);
    outtextxy(350,15,"SHEARED TRIANGLE");
    line(p1[0][0]+x,p1[1][0]+y,p1[0][1]+x,p1[1][1]+y);
    line(p1[0][1]+x,p1[1][1]+y,p1[0][2]+x,p1[1][2]+y);
    line(p1[0][2]+x,p1[1][2]+y,p1[0][0]+x,p1[1][0]+y);
    delay(100);
}

void sheary(int p[3][3],int xref, int shy)  //Shearing with a x reference line
{
    int shry[3][3] = {{1,0,0},{shy,1,-shy*xref},{0,0,1}};
    int p1[3][3];
    int x = getmaxx()/2;
    int y = getmaxy()/2;
    line(x,0,x,y);
    line(0,y,x,y);
    line(x,y,getmaxx(),y);
    line(x,y,x,getmaxy());
    setcolor(WHITE);
    outtextxy(350,5,"INITIAL COORDINATES");
    line(p[0][0]+x,p[1][0]+y,p[0][1]+x,p[1][1]+y);
    line(p[0][1]+x,p[1][1]+y,p[0][2]+x,p[1][2]+y);
    line(p[0][2]+x,p[1][2]+y,p[0][0]+x,p[1][0]+y);
    matrixMultiply(p,shry,p1);
    for(int i =0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf(" %d",p1[i][j]);
        }
        printf("\n");
    }
    setcolor(MAGENTA);
    outtextxy(350,15,"SHEARED TRIANGLE");
    line(p1[0][0]+x,p1[1][0]+y,p1[0][1]+x,p1[1][1]+y);
    line(p1[0][1]+x,p1[1][1]+y,p1[0][2]+x,p1[1][2]+y);
    line(p1[0][2]+x,p1[1][2]+y,p1[0][0]+x,p1[1][0]+y);
    delay(100);
}

int main()
{
    int gd= DETECT,gm;
    int choice,option;
    int tx,ty,sx,sy,c,shx,shy,yref,xref,m;
    double theta;
    int p[3][3];
    initgraph(&gd,&gm,"");
    initwindow(1300,800);
    printf("Enter the coordinates of the triangle: ");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&p[j][i]);
        }
    }
    p[2][0] = p[2][1] = p[2][2] = 1;
    printf("\n1.Translation\n2.Scaling\n3.Rotation\n4.Reflection\n5.Shearing");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter the transalation co-ordinates: ");
            scanf("%d %d",&tx,&ty);
            translateFn(p,tx,ty);
        break;
        case 2:
            printf("\nEnter the scaling factors: ");
            scanf("%d %d",&sx,&sy);
            scaleFn(p,sx,sy);
        break;
        case 3:
            printf("\nEnter the angle of rotation: ");
            scanf("%lf",&theta);
            rotateFn(p,theta);
        break;
        case 4:
            printf("\n1.Reflection w.r.t y-axis.\n2.Reflection about origin.\n3.Reflection about a line\n");
            printf("Option: ");
            scanf("%d",&option);
            switch(option)
            {
                case 1:
                    reflecty(p);
                break;
                case 2:
                    reflecto(p);
                break;
                case 3:
                    printf("\nINFORMATION\n");
                    printf("For reflection about x-axis Slope = 0 and y-intercept = 0\n");
                    printf("Enter the reflection parameters\n");
                    printf("Slope: ");
                    scanf("%d",&m);
                    printf("y-intercept: ");
                    scanf("%d",&c);
                    reflect(p,m,c);
                break;
                default:
                    printf("\nWrong option");
                break;
            }
        break;
        case 5:
            printf("\n1.y-reference shear\n2.x-reference shear");
            printf("\nChoose the type of shear: ");
            scanf("%d",&option);
            switch(option)
            {
                case 1:
                    printf("\nEnter the y-reference line: ");
                    scanf("%d",&yref);
                    printf("Enter the shearing factor: ");
                    scanf("%d",&shx);
                    sheary(p,yref,shx);
                break;
                case 2:
                    printf("\nEnter the x-reference line: ");
                    scanf("%d",&xref);
                    printf("Enter the shearing factor: ");
                    scanf("%d",&shy);
                    shearx(p,xref,shy);
                break;
                default:
                    printf("\nWrong choice");
                break;
            }
        break;
        default:
            printf("\nWrong choice");
        break;
    }
    printf("\nThe following transformation occured and the output is shown");
    getevent();
    closegraph();
    return 0;
}