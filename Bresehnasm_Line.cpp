#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

float X1,X2,Y1,Y2;
float x,y,length,dx,dy,xin,yin,e;
int i;


void simpleline()
{
	cout<<"Enter the starting coordintes :";
	cin>>X1;
	cin>>Y1;
	cout<<"Enter the ending coordinates :";
	cin>>X2;
	cin>>Y2;
	
	dx=X2-X1;
	dy=Y2-Y1;
	
	x=X1;
	y=Y1;
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	
	e=2*dy-dx;
	
	for(i=1;i<=dx;i++)
	{
		while(e>=0)
		{
			y=y+1;
			e=e-2*dx;
		}
		x=x+1;
		e=e+2*dy;
		
		glBegin(GL_POINTS);
		glVertex2i(x,y);
	}
	glEnd();
	glFlush();
}

void dottedline()
{
	cout<<"Enter the starting coordintes :";
	cin>>X1;
	cin>>Y1;
	cout<<"Enter the ending coordinates :";
	cin>>X2;
	cin>>Y2;
	
	dx=X2-X1;
	dy=Y2-Y1;
	
	x=X1;
	y=Y1;
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	
	e=2*dy-dx;
	
	for(i=1;i<=dx;i++)
	{
		while(e>=0)
		{
			y=y+1;
			e=e-2*dx;
		}
		x=x+1;
		e=e+2*dy;
		if(i%2==0)
		{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		}
	}
	glEnd();
	glFlush();
}

void dashedline()
{
	cout<<"Enter the starting coordintes :";
	cin>>X1;
	cin>>Y1;
	cout<<"Enter the ending coordinates :";
	cin>>X2;
	cin>>Y2;
	
	dx=X2-X1;
	dy=Y2-Y1;
	
	x=X1;
	y=Y1;
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	
	e=2*dy-dx;
	
	for(i=1;i<=dx;i++)
	{
		while(e>=0)
		{
			y=y+1;
			e=e-2*dx;
		}
		x=x+1;
		e=e+2*dy;
		if(i%5==0)
		{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		}
	}
	glEnd();
	glFlush();
}

void display()
{
	cout<<"\nSimple Line\n";
	simpleline();
	cout<<"\nDotted Line\n";
	dottedline();
	cout<<"\nDashed Line\n";
	dashedline();
}

void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}

int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Bresenhams");
	init();
	glutDisplayFunc(display);	
	glutMainLoop();
	return 0;
}
