#include "Monstruo.h"


Monstruo::Monstruo(void)
{
	radio=1.5f;
	estado=1;
	posicion.x=posicion.y=posicion.z=0;
}


Monstruo::~Monstruo(void)
{
}
void Monstruo::Dibuja()
{
	glColor3ub(0,255,0);
	glTranslatef(posicion.x,posicion.y,posicion.z);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x,-posicion.y,-posicion.z);
}
void Monstruo::SetPos(float ix, float iy, float iz)
{
	posicion.x=ix;
	posicion.y=iy;
	posicion.z=iz;
	limitestrayectoria[0]=posicion.x-3,
	limitestrayectoria[1]=posicion.x+3;
}
void Monstruo::Mueve(float t)//Esta parte ir� en la clase movimientos y habra que poner esto de forma m�s
							// simplificada como en lo comentado abajo
{
	if(posicion.x>limitestrayectoria[1]) estado=1;
	
	if(posicion.x<limitestrayectoria[0]) estado=2; 

	switch(estado)
	{
	case 1:
		posicion.x-=t*1.1;
		break;
	case 2:
		posicion.x+=t*1.1;
		break;
	}
}