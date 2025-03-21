#include "freeglut.h"
#pragma once

class Mundo
{
private:
	// Variables para la cámara
	float theta;          // Ángulo de la órbita de la cámara
	float radio_camara;  // Distancia de la cámara al origen (escena)
	float altura_camara; // Altura de la cámara sobre el plano XY
public:
	Mundo();
	void camara();
	void rotarOjo(float incremento);
};