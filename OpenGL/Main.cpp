#define _USE_MATH_DEFINES

#include <cctype> 

#include"AdditionState.h"
#include"EditionState.h"

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

AdditionState* additionState;
EditionState* editionState;

ApplicationState* applicationState;

GLint gJanelaPrincipal = 0;

GraphicWorld graphicWorld;

bool edicao = false;

void inicializa(void) {
	editionState = new EditionState(&graphicWorld);
	additionState = new AdditionState(&graphicWorld);

	applicationState = additionState;

	glClearColor(0.75f,0.75f,0.75f,1.0);
}

void redimensiona(int w, int h) {
	glutPostRedisplay();
}

double paraRadianos(int angulo)
{
	return (M_PI/180) * angulo;
}

double RetornaX(double angulo, double raio) {
	return raio * cos(paraRadianos(angulo));
}
double RetornaY(double angulo, double raio) {
	return raio * sin(paraRadianos(angulo));
}

void desenha(void) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	graphicWorld.setOrtho2d();
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1, 0, 0);
	glLineWidth(1.0f);
	graphicWorld.draw();

	glutSwapBuffers();
}

int normalizeYCoordinate(int y)
{
	return -y;
}

void keyboardSpecialKeyEvent(int key, GLint px, GLint py)
{
	applicationState->handleKeyBoardSpecialKeyCommand(key, px, py);

	desenha();
}

void keyboardEvent(unsigned char key, int x, int y)
{
	y = normalizeYCoordinate(y);
	key = std::toupper(key);

	switch(key)
	{
	case'=':
		graphicWorld.zoomIn();
		break;

	case'-':
		graphicWorld.zoomOut();
		break;

	case 'E':
		applicationState = editionState;
		break;

	case 'A':
		applicationState = additionState;
		break;

	default:
		applicationState->handleKeyBoardCommand(key, x, y);
		break;
	}
	glutPostRedisplay();
	desenha();
}

void mouseMoveEvent(int x, int y)
{
	y = normalizeYCoordinate(y);

	applicationState->handleMouseMoveCommand(x, y);

	desenha();
}


void mouseEvent (int button,int state, int x, int y)
{
	y = normalizeYCoordinate(y);

	applicationState->handleMouseClickCommand(button, state, x, y);

	desenha();
}

int main (int argc, const char * argv[]) {
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition (300, 250);
	glutInitWindowSize (500, 500);
	gJanelaPrincipal = glutCreateWindow("N2_Exec-04");
	inicializa();

	glutMouseFunc(mouseEvent);
	glutPassiveMotionFunc(mouseMoveEvent);
	glutKeyboardFunc(keyboardEvent);
	glutSpecialFunc(keyboardSpecialKeyEvent);
	glutReshapeFunc(redimensiona);
	glutDisplayFunc(desenha);

	glutMainLoop();

	return 0;
}