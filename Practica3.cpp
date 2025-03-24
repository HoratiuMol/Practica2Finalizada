#include <iostream> // para usar cout
#include <cstring>  // para las funciones de C
#include <afx.h>    // para usar las MFC: CStringA
#include <afxdlgs.h>
#include "esfera.h"
#include "toroide.h"
#include "plano.h"
#include "mundo.h"

#include "freeglut.h"

#pragma warning(disable : 4996) // deshabilita el error por unsafe

using namespace std;

// Espacio de nombres para las variables globales
namespace Global {
    Esfera esfera;
    Esfera esfera2;
	Toroide toroide;
    Plano plano;
    Mundo mundo;
}

// Declaraciones de funciones
void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);

int main(int argc, char* argv[]) {
    // Inicializar el gestor de ventanas GLUT y crear la ventana
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("MiJuego");

    // Habilitar luces y definir perspectiva
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

    // Registrar los callbacks
    glutDisplayFunc(OnDraw);
    glutTimerFunc(25, OnTimer, 0); // le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
    glutKeyboardFunc(OnKeyboardDown);

    // Inicialización de los datos de la simulación
    Global::esfera.setColor(200, 0, 0);
    Global::esfera.setRadio(1);
    Global::esfera.setPos(2, 0);
    Global::esfera2.setColor(0, 200, 0);
    Global::esfera2.setRadio(1);
    Global::esfera2.setPos(3, 0);

	// Inicialización del toroide
	Global::toroide.setColor(0, 0, 200);
	Global::toroide.setRadioInterior(1);
	Global::toroide.setRadioExterior(5);
	Global::toroide.setSides(20);
	Global::toroide.setRings(20);
	Global::toroide.setPos(0, 0);

    //inicializamos Plano
    Global::plano.setColor(200, 255, 255);
    //Global::plano.setPos(0, 0);

    // Pasarle el control a FREEGLUT, que llamará a los callbacks
    //siempre llamar los callbacks antes de glutMainLoop
    glutMainLoop();

    return 0;
}

void OnDraw(void) {
    // Borrado de la pantalla
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Para definir el punto de vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Invocamos cámara
    Global::mundo.camara();

    // Llamadas a los métodos de Esfera
    Global::esfera.dibuja();
    Global::esfera2.dibuja();
	Global::toroide.dibuja();
    Global::plano.dibuja();
    // Llamada a método de Esfera
    Global::esfera2.mueve();

    // No borrar esta línea ni poner nada después
    glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x, int y) {
    if (key == 'r')
        Global::esfera.setColor(255, 0, 0);
    if (key == 'g')
        Global::esfera.setColor(0, 255, 0);
    if (key == 'b')
        Global::esfera.setColor(0, 0, 255);

    glutPostRedisplay();
}

void OnTimer(int value) {
    Global::mundo.rotarOjo(0.05f);
    glutTimerFunc(25, OnTimer, 0);
    glutPostRedisplay();
}

