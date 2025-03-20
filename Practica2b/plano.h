#include "freeglut.h"
#pragma once

class Plano {
private:
	double x;
	double y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setPos(double x, double y);
	void dibuja();
	//void mueve();
};