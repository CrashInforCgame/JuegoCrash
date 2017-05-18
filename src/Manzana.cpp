#include "Manzana.h"


Manzana::Manzana(void)
{
	radio= 0.25f;
	estado=2;
}


Manzana::~Manzana(void)
{
}
void Manzana::dibuja() 
{
	glColor3ub(255,0,0);//azul oscura
	glTranslatef(posicion.x,posicion.y,posicion.z);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x,-posicion.y,-posicion.z);

}
void Manzana::SetPos(float x, float y, float z)
{
	posicion.x=x;
	posicion.y=y;
	posicion.z=z;
}
void Manzana::mueve(float t)
{
	//ESTADOS GRANDE 0 DECRECE 1 PEQUE�O 2 CRECE 3
	if(radio>0.3) estado=1;
	//if(radio<0.35 && estado==0) estado=1;
	if(radio<0.2) estado=2; 
	//if(radio<0.15 && estado==2) estado=3; // si viene del estado 0
	// esto se puede simplificar claramente
	switch(estado)
	{
	case 1:
		radio-=t*0.075;
		break;
	case 2:
		radio+=t*0.075;
		break;
	}
};