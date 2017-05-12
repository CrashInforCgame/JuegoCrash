#include "Interaccion.h"
#include "Escenario.h"
#include "math.h"


Interaccion::Interaccion(void)
{
}

Interaccion::~Interaccion(void)
{

}

void Interaccion::rebote(Personaje &h, Escenario c)
{
	int j=1;
	if(c.suelo2.limite3.z>(h.posicion.z))
	{
		j=2;
		if(c.suelo3.limite2.x<(h.posicion.x))
		{
			j=3;
		}
		if(c.suelo4.limite3.z>(h.posicion.z))
		{
			j=4;
			if(c.suelo5.limite3.x>(h.posicion.x))
					j=5;
		}
	}
	if(j==1)
	{
		rebote(h,c.suelo1); //PODEMOS INTENTAR SIMPLIFICAR EL RESTO DE ALGUNA FORMA PARECIDA
		// ESTA FUNCION YA ESTA HECHA PARA QUE SE VEA LA ESFERA ENTERA
							
	}

	// EN J=2 NO SE VERA LA ESFERA ENTERA. SE VERA MEDIA. EN EL RESTO NO HE AÑADIDO EL ULTIMO CONDICIONAL QUE EVITA QUE NO CAIGA

	if(j==2)
	{
		float yplano=c.suelo2.Ypuntoplano(h);
		float xmax=c.suelo2.limite3.x;
		float xmin=c.suelo1.limite1.x;
		float zmax=c.suelo2.limite2.z;
		float zmin=c.suelo2.limite1.z;
		if(h.posicion.x>xmax)h.posicion.x=xmax;
		if(h.posicion.x<xmin)h.posicion.x=xmin;
		if(h.posicion.z>zmax)h.posicion.z=zmax;
		if(h.posicion.z<zmin)h.posicion.z=zmin;
		if(yplano>h.posicion.y)h.posicion.y=yplano;  //PARA QUE NO SE CAIGA DEL PLANO
	}
	if(j==3)
	{
		float xmax=c.suelo3.limite3.x;
		float xmin=c.suelo3.limite1.x;
		float zmax=c.suelo2.limite2.z;
		float zmin=c.suelo3.limite1.z;
		if(h.posicion.x>xmax)h.posicion.x=xmax;
		if(h.posicion.x<xmin)h.posicion.x=xmin;
		if(h.posicion.z>zmax)h.posicion.z=zmax;
		if(h.posicion.z<zmin)h.posicion.z=zmin;
	}
	if(j==4)
	{
		float xmax=c.suelo3.limite3.x;
		float xmin=c.suelo3.limite2.x;
		float zmax=c.suelo4.limite3.z;
		float zmin=c.suelo4.limite4.z;
		if(h.posicion.x>xmax)h.posicion.x=xmax;
		if(h.posicion.x<xmin)h.posicion.x=xmin;
		if(h.posicion.z>zmax)h.posicion.z=zmax;
		if(h.posicion.z<zmin)h.posicion.z=zmin;
	}
	if(j==5)
	{
		float xmax=c.suelo5.limite3.x;
		float xmin=c.suelo5.limite1.x;
		float zmax=c.suelo4.limite2.z;
		float zmin=c.suelo5.limite1.z;
		if(h.posicion.x>xmax)h.posicion.x=xmax;
		if(h.posicion.x<xmin)h.posicion.x=xmin;
		if(h.posicion.z>zmax)h.posicion.z=zmax;
		if(h.posicion.z<zmin)h.posicion.z=zmin;
	}
}


void Interaccion::rebote(Personaje &h, Suelo s) //FUNCION PLANTEADA PARA TODO
{
		float xmax=s.limite3.x;
		float xmin=s.limite2.x;
		float yplano=s.Ypuntoplano(h); // Esta funcion nos da la Y DEL PLANO EN ESA COORDENADA para que no caiga
		float ypersonaje=yplano+h.radio; //PARA QUE SE VEA EL RADIO ENTERO LUEGO
	// float ymin=s.limite1.y; // ESTO FUNCIONA SIEMPRE QUE SEAN PLANOS CON Y CONSTANTE SOLO
		float zmax=s.limite2.z;
		float zmin=s.limite1.z;
		if(h.posicion.x>xmax)h.posicion.x=xmax;
		if(h.posicion.x<xmin)h.posicion.x=xmin;
	// if(h.posicion.y<ymin)h.posicion.x=ymin; //PARA LA Y
		if(h.posicion.z>zmax)h.posicion.z=zmax;
		if(h.posicion.z<zmin)h.posicion.z=zmin;
		if(ypersonaje>h.posicion.y)h.posicion.y= ypersonaje;  //PARA QUE NO SE CAIGA DEL PLANO Y SE VEA LA ESFERA ENTERA
		// YPERSONAJE está cogido como la y del plano + el radio
}