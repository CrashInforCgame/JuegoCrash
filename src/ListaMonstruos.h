#pragma once
#include "Monstruo.h"
#include "Interaccion.h"
#include "Personaje.h"
#define MAX_MONSTRUOS 30
class ListaMonstruos
{
public:
public:
	ListaMonstruos(void);
	~ListaMonstruos(void);
	bool agregar (Monstruo *e);
	void Dibuja();
	void Mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Monstruo *e);
	bool choque(Personaje &h);
	Monstruo* ataque(Personaje &h);
	Monstruo * operator [](int i);
	int getNumero(){return numero;}
private:
	Monstruo* lista[MAX_MONSTRUOS];
	int numero;
};

