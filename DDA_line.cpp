#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

float x1,   y1, x2, y2;
void simpleline();
void DashLine();
void DottedLine();

float x,y,dy,dy,xin,yin;k,length;

void display()
{
    cout<<"\n Simple line\n";
    simpleline();
    cout<<"\n Dotted line\n";
    DottedLine();
    cout<<"\nDash line\n";
    DashLine();
}

void simpleline()
{
    cout<<"\n Enter The Value Of x1:";
    cin>>x1;
    cout<<"\n Enter The Value Of y1:";
    cin>>y1;
    cout<<"\n Enter The Value Of x2:";
    cin>>x2;
    cout<<"\n Enter The valued of y2:";
    cin>>y2;

    dx=x2-x1;
    dy=y2-y1;
    
    if(abs(dx)>abs(dy))
    {
        length=abs(dx);
    }
    else
    length=abs(dy);

    xin=dx/length;
    yin=dy/length;

    x=x1;
    y=y1;

    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();

    for(k=1; k<=length;k++)
    {
        x=x+xin;
        y=y+yin;

        glBegin(GL_POINTS);
        geVertex2i(x,y);
        glEnd();
    }
    glFlush();
}

void DashLine()
{
    cout<<"\n Enter The Value Of x1:";
    cin>>x1;
    cout<<"\n Enter The Value Of y1:";
    cin>>y1;
    cout<<"\n Enter The Value Of x2:";
    cin>>x2;
    cout<<"\n Enter The valued of y2:";
    cin>>y2; 

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
    {
        length=abs(dx);
    }
    else
        length=abs(dy);
    
    xin=dx/length;
    yin=dy/length;

    x=x1;
    y=y1;

    glBegin(GL_POINTS);
    glVertex2i(x,y);


    for(int i=1;k<=length;k++)
    {
        x=x+xin;
        y=y+yin;

        if(i%5==0)
        {
            glVertex2i(x,y);
        }
    }
        glEnd(); 
    glFlush();
}

void DottedLine()
{
    cout<<"\n Enter The Value Of x1:";
    cin>>x1;
    cout<<"\n Enter The Value Of y1:";
    cin>>y1;
    cout<<"\n Enter The Value Of x2:";
    cin>>x2;
    cout<<"\n Enter The valued of y2:";
    cin>>y2;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
    {
        length=dx;
    }
    else    
        length=dy;

    xin=dx/length;
    yin=dy/length;

    x=x1;
    y=y1;

    glBegin(GL_POINTS);
    glVertex2i(x,y);
    for(int i=0;i<=length;i++)
    {
        x=x+xin;
        y=y+yin;
        if(i %2==0)
        {
            glVertex2i(x,y);
        }
    }
    glEnd();
    glFlush();
}

void init(void)
{
    glClearColor(1.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrthod2D(-100,100,-100,100);
}

int main(int argc, char** argv)
{
    glutInit(&argv,argc);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(500,500);
    glutInitWindowPosition(500,500);
    glutCreateWindow("DDA Algorithms");

    init(); //
    glutDisplayFunc(display); //
    glutMainLoop();

    return 0;
}