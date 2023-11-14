#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <time.h>

void draw() {

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glColor3f(0.0f, 1.0f, 0.0f);


// desenho de uma face do quadrado
glBegin(GL_QUADS);
/*
glColor3f(1.0, 0.0, 0.0);
glVertex2f(-0.1f, 0.1f);  // vertex 1
glVertex2f(-0.1f, -0.1f); // vertex 2
glVertex2f(0.1f, -0.1f);  // vertex 3
glVertex2f(0.1f, 0.1f);   // vertex 4
*/

//CUBO

// parte BAIXO cubo (y = 1.0f)

glColor3f(0.0f, 1.0f, 0.0f);	 // Green
glVertex3f(1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f,  1.0f);
glVertex3f( 1.0f, 1.0f,  1.0f);

// parte CIMA cubo

glColor3f(1.0f, 0.1f, 0.0f);	 // Orange
glVertex3f( 1.0f, -1.0f,  1.0f);
glVertex3f(-1.0f, -1.0f,  1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f( 1.0f, -1.0f, -1.0f);


// parte FRENTE cubo (z = 1.0f)

glColor3f(0.0f, 1.0f, 0.0f);	 // Red
glVertex3f( 1.0f,  1.0f, 1.0f);
glVertex3f(-1.0f,  1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f( 1.0f, -1.0f, 1.0f);

// parte TRÁS cubo (z = -1.0f)
glColor3f(1.0f, 1.0f, 0.0f);	 // Yellow
glVertex3f( 1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f,  1.0f, -1.0f);
glVertex3f( 1.0f,  1.0f, -1.0f);

// parte ESQUERDA cubo (x = -1.0f)


glVertex3f(-1.0f,  1.0f,  1.0f);
glVertex3f(-1.0f,  1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f,  1.0f);

// parte DIREITA cubo (x = 1.0f)
glColor3f(1.0f, 0.0f, 1.0f);	 // Magenta
glVertex3f(1.0f,  1.0f, -1.0f);
glVertex3f(1.0f,  1.0f,  1.0f);
glVertex3f(1.0f, -1.0f,  1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);

glEnd();
glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
if(key==27) exit(0); // Keyboard method to allow ESC key to quit
}

void keys(int key, int x, int y) {

switch (key) {

	case GLUT_KEY_LEFT:
		glTranslatef(0.45, 0, 0.0);
		break;

	case GLUT_KEY_RIGHT:
		glTranslatef(-0.45, 0.0, 0.0);
		break;

	case GLUT_KEY_UP:
		glTranslatef(0.0, -0.45, 0.0);
		break;

	case GLUT_KEY_DOWN:
		glTranslatef(0.0, 0.45, 0.0);
		break;

	default:
		break;
}


glutPostRedisplay();

}

void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60000.0, (GLfloat) w/(GLfloat) h, 0.20, 60000.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0.0, 0.0, -5.0); // muda tamanho do cubo
}

void animacao(int x){

int posicao = rand() % 5 + 1;

if (posicao==1) {
	glTranslatef(1.0, 0, 0.0);

}

if (posicao == 2) {
	glTranslatef(-1.0, 0, 0.0);

}

if (posicao == 3) {
	glTranslatef(0, 1.0, 0.0);

}

if (posicao == 4) {
	glTranslatef(0, -1.0, 0.0);

}
glutPostRedisplay();
glutTimerFunc(200, animacao, 1);
}

/*
fprintf(stdout, "cenas");

int positivo = rand() % 5 + 1;

//se for 0, então o valor vai ser negativo
if (positivo == 0) {
	glPushMatrix();
	float posicao = -(rand() % 100) / 100;
	x = posicao;
	glutDisplayFunc(draw_animacao);
	printf("OLA");
	glPopMatrix();

}
//vai ser positivo
else{
	float posicao = -(rand() % 100) / 100;
	x = posicao;
	glutDisplayFunc(draw_animacao);
}

keyboard(GLUT_KEY_LEFT, 1, 1);
glutPostRedisplay();
glutTimerFunc(250, animacao, 1);
}
*/

int main(int argc, char ** argv) {

glutInit(&argc, argv);
// tamanho da janela
glutInitWindowSize(500,500);
glutCreateWindow("Cube");

glEnable(GL_DEPTH_TEST);

// declarar funções de teclado e ecrã
glutDisplayFunc(draw);
glutDisplayFunc(draw);
glutKeyboardFunc(keyboard); // apenas para ESC
glutSpecialFunc(keys);   // teclas CIMA, BAIXO, ESQUERDA, DIREITA
glutReshapeFunc(reshape);

glutTimerFunc(200, animacao,1);

// Start the Main Loop
glutMainLoop();
return 0;
}
