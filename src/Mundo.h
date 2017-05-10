#include"Escenario.h"
#include"Personaje.h"

class Mundo
{
	float x_ojo;
	float y_ojo;
	float z_ojo;

	Escenario escenario;
	Personaje personaje;
	Personaje personaje2;
public: 
	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();
};
