#include"Escenario.h"
#include"Personaje.h"

class Mundo
{
public: 
	void Tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve();
	void Dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;

	Escenario escenario;
	Personaje personaje;
};
