#include <stdio.h>
#include<GL/glut.h>
void Draw()
{
    glClearColor(0.25f, 0.75f, 0.45f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    glBegin(GL_POINTS);

    glColor3d(1.0f, 0.0f, 0.0f);
    glVertex2d(25, 25);
    glEnd();
    glFlush();
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250, 250, -250, 250);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char* argV[])
{
    glutInit(&argc, argV);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(520, 520);
    glutCreateWindow("Bresenhem's line drawing algorithm");
    myinit();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}