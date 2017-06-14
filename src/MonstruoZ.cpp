#include "MonstruoZ.h"


MonstruoZ::MonstruoZ()
{
	radio=1.5f;
	estado=1;
	posicion.x=posicion.y=posicion.z=0;
	color[0]=0;
	color[1]=255;
	color[2]=3;

}


MonstruoZ::~MonstruoZ(void)
{
}


void MonstruoZ::SetPos(float ix, float iy, float iz)
{
	posicion.x=ix;
	posicion.y=iy;
	posicion.z=iz;
	limitestrayectoria[0]=posicion.z-3,
	limitestrayectoria[1]=posicion.z+3;
}


void MonstruoZ::Mueve(float t)//Esta parte irá en la clase movimientos y habra que poner esto de forma más
							// simplificada como en lo comentado abajo
{
		if(posicion.z>limitestrayectoria[1]) estado=1;
	
		if(posicion.z<limitestrayectoria[0]) estado=2; 

		switch(estado)
		{
		case 1:
			posicion.z-=t*1.1;
			break;
		case 2:
			posicion.z+=t*1.1;
			break;
		}

}