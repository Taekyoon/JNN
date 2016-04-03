/* 2016.03.28 started by junodeveloper
JNN
 */
#include "OpenGL.h"
#include "JNN.h"
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

JNN* jnn;

void CStart();
void CRender();
void CInit(int, char**);
void CGLInit(int, char**);
void CJnnInit();

void CStart() {
    glutMainLoop();
}
void CRender() {
    glClear (GL_COLOR_BUFFER_BIT);
    /* render */
    jnn->update();
    jnn->render();
    glFlush();
}
void CKeyboard(unsigned char key, int x, int y) {
    jnn->keyEvent(key);
}
void CInit(int argc, char** argv) {
    srand( time(NULL) );
    CGLInit(argc, argv);
    CJnnInit();
}
void CGLInit(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
    glutInitWindowSize (WINDOW_WIDTH,WINDOW_HEIGHT);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("JNN");
    //glClearColor (0.15, 0.15, 0.15, 0.0);
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    glutDisplayFunc(CRender);
    glutKeyboardFunc(CKeyboard);
    glutIdleFunc(CRender);
}
void CJnnInit() {
    jnn = new JNN();
    jnn->init();
}
int main(int argc,char** argv) {
    CInit(argc, argv);
    CStart();
    return 0;
}
