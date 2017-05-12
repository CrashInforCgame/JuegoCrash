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
	glVertex3d(limite1.x,limite1.y,limite1.z);
	glVertex3d(limite2.x,limite2.y,limite2.z);
	glVertex3d(limite3.x,limite3.y,limite3.z);
	glVertex3d(limite4.x,limite4.y,limite4.z);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Suelo::SetPos(float x1, float y1, float z1,float x2, float y2, float z2,float x3, float y3,
				   float z3,float x4, float y4, float z4)
{
	limite1.x=x1;
	limite1.y=y1;
	limite1.z=z1;
	limite2.x=x2;
	limite2.y=y2;
	limite2.z=z2;
	limite3.x=x3;
	limite3.y=y3;
	limite3.z=z3;
	limite4.x=x4;
	limite4.y=y4;
	limite4.z=z4;

}
