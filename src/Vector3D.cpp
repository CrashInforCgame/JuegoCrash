#include "Vector3D.h"
#include "glut.h"
#include <math.h>


Vector3D::Vector3D(float xv,float yv, float zv)
{
	x=xv;
	y=yv;
	z=zv;
}

float Vector3D::modulo()
{
	return (float)sqrt(x*x+y*y);
}

float Vector3D::argumento()
{
	return (float)atan2(y,x);
}

Vector3D Vector3D::Unitario()
{
	Vector3D retorno(x,y);
	float mod=modulo();
	if(mod>0.00001)
	{
		retorno.x/=mod;
		retorno.y/=mod;
	}
	return retorno;
}

Vector3D Vector3D::operator - (Vector3D &v)
{
	Vector3D res;
	res.x=x-v.x;
	res.y=y-v.y;
	return res;
}

Vector3D Vector3D::operator + (Vector3D &v)
{
	Vector3D res;
	res.x=x+v.x;
	res.y=y+v.y;
	return res;
}

float Vector3D::operator *(Vector3D &v)
{
	float res;
	res = (x*v.x)+(y*v.y);
	return res;
}


Vector3D Vector3D::operator *(float k)
{
	Vector3D res;
	res.x = x*k;
	res.y = y*k;
	res.z = z*k;
	return res;
}
