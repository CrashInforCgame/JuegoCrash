#include "Vector3D.h"
#include "glut.h"
#include <math.h>


Vector3D::Vector3D(float xv,float yv, float zv)
{
	x=xv;
	y=yv;
	z=zv;
}


Vector3D Vector3D::operator - (Vector3D &v)
{
	Vector3D res;
	res.x=x-v.x;
	res.y=y-v.y;
	res.z=z-v.z;
	return res;
}

Vector3D Vector3D::operator + (Vector3D &v)
{
	Vector3D res;
	res.x=x+v.x;
	res.y=y+v.y;
	res.z=z+v.z;
	return res;
}

float Vector3D::operator *(Vector3D &v)
{
	float res;
	res = (x*v.x)+(y*v.y)+(z*v.z);
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
