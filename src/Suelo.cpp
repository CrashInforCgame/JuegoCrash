#include "Suelo.h"
#include "glut.h"
#include "math.h"

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
float Suelo::distancia(Personaje &h) // Hallamos el vector normal al plano haciendo el producto vectorial de dos vectores que estan en este y normalizando
	// Luego hallamos un vector que vaya del personaje a un punto del plano (Cogemos algun punto limite1 o limite2 de esos)
	// Por ultimo proyectamos ese vector sobre la normal al plano para tener la distancia (Producto escalar)
{
	Vector3D Pos_personaje = h.GetPos();
	Vector3D pnj_plano = Pos_personaje-limite1; 
	Vector3D v_plano1= limite1-limite2;
	Vector3D v_plano2= limite1-limite3;
	Vector3D normal = v_plano1.pvectorial(v_plano2).unitario(); // Aqui sacamos la normal al plano
	float distancia = abs(pnj_plano*normal);
	return distancia;
}