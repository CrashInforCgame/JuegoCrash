#include "Suelo.h"
#include "glut.h"

void Suelo::setColor( unsigned char r,unsigned char v, unsigned char a)
{
	rojo=r;
	verde=v;
	azul=a;
}

void Suelo::Dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(rojo,verde,azul);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x,limite1.y,10);
	glVertex3d(limite2.x,limite2.y,10);
	glVertex3d(limite2.x,limite2.y,-10);
	glVertex3d(limite1.x,limite1.y,-10);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Suelo::SetPos(float x1, float y1, float x2, float y2)
{
	limite1.x=x1;
	limite1.y=y1;
	limite2.x=x2;
	limite2.y=y2; 
}