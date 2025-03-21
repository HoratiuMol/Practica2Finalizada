#include "freeglut.h"
#pragma once

class Mundo
{
private:
	// Variables para la c�mara
	float theta;          // �ngulo de la �rbita de la c�mara
	float radio_camara;  // Distancia de la c�mara al origen (escena)
	float altura_camara; // Altura de la c�mara sobre el plano XY
public:
	Mundo();
	void camara();
	void rotarOjo(float incremento);
};