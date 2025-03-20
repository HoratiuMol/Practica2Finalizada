#include "freeglut.h"
#pragma once

class Esfera
{
private:
	double radio;
	double x;
	double y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setRadio(double r);
	void setPos(double ix, double iy);
	void dibuja();
	void mueve();
};
