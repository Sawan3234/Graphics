#include <stdio.h>
#include<GL/glut.h>
#include<math.h>
void Draw()
{
    GLfloat x1 = 100, y1 = 200, x2 = 300, y2 = 250;
    GLfloat dx, dy, x, y, p;
    glClearColor(0.25f, 0.75f, 0.45f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    //code for bla
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if ((x2 - x1) < 0 || (y2 - y1) < 0)
    {
        x = x2;
        y = y2;
    }


    if (dx < dy)
    {
        p = 2 * dx - dy;
        x = x1;
        y = y1;
        while (y <= y2)
        {
            glPointSize(3);
            glBegin(GL_POINTS);
            glColor3d(1.0f, 0.0f, 0.0f);
            glVertex2d(x, y);
            glEnd();
            y = y + 1;
            if (p < 0)
            {
                p = p + 2 * dx;

            }
            else {
                p = p + 2 * dx - 2 * dy;
                x = x + 1;
            }
        }
    }
    else {
        p = 2 * dy - dx;
        x = x1;
        y = y1;
        while (x <= x2)
        {
            glPointSize(3);
            glBegin(GL_POINTS);
            glColor3d(1.0f, 0.0f, 0.0f);
            glVertex2d(x, y);
            glEnd();
            x = x + 1;
            if (p < 0)
            {
                p = p + 2 * dy;

            }
            else {
                p = p + 2 * dy - 2 * dx;
                y = y + 1;
            }
        }

    }

    glFlush();
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
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