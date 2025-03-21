#include "freeglut.h"
#include "cmath"
#include "mundo.h"
#pragma once

Mundo::Mundo() {
	theta = 0.0f;
	radio_camara = 20.0f;
	altura_camara = 10.0f;
}

void Mundo:: camara()
{
	// Calculamos la posici�n de la c�mara en funci�n del �ngulo theta
	float x = radio_camara * cos(theta);
	float z = radio_camara * sin(theta);
	float y = altura_camara; // Altura fija de la c�mara

	// Definimos la vista con gluLookAt
	gluLookAt(x, y, z,   // Posici�n de la c�mara (orbita alrededor del origen)
		0.0, 0.0, 0.0, // Punto al que mira (centro de la escena)
		0.0, 1.0, 0.0); // Vector "up" (hacia arriba en el eje Y)
}
void Mundo::rotarOjo(float incremento)
{
	theta += incremento; // Incrementamos el �ngulo para hacer la rotaci�n
	if (theta > 2 * 3.14) {
		theta -= 2 * 3.14; // Reseteamos el �ngulo si pasa de 360�
	}
	// Poner aqu� el c�digo de animaci�n
}
