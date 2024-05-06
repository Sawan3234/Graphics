#include<GL/glut.h>
GLfloat C1[3] = { 1.0f,0.0f,0.0f };//red
GLfloat C2[3] = { 0.0f,0.0f,1.0f };//blue
GLfloat C3[3] = { 0.0f,1.0f,0.0f };//green
GLfloat C4[3] = { 1.0f,1.0f,1.0f };//white
GLfloat C5[3] = { 0.2f,0.75f,0.75f };//light blue for BG
void CreatePolygun(GLfloat V[3][2], GLfloat Pic_color[3])
{
    glBegin(GL_LINE_LOOP);
    glColor3fv(Pic_color);
    for (int i = 0;i < 3;i++)
    {
        glVertex2fv(V[i]);

    }
    glEnd();
}
//defining a scalling function
void scale2d(GLfloat V[3][2]) {
    //variable for scaling factors
    GLfloat Sx = 1.75;
    GLfloat Sy = 1.0;
    for (int i = 0;i < 3;i++)
    {
        V[i][0] *= Sx;
        V[i][1] *= Sy;
    }
    CreatePolygun(V, C3);

}
//defining draw function
void Draw()
{
    glClearColor(0.25f, 0.75f, 0.75f, 0.1f);
    glClear(GL_COLOR_BUFFER_BIT);

    //defining the vetex matrix for co-ordinate
    GLfloat Vertex[3][2] = {
    {100,200},
    {-20,50},
    {200,80},
    };
    // calling a polygun create function
    CreatePolygun(Vertex, C1);
    //calling scale function
    scale2d(Vertex);
    glBegin(GL_LINES);
    glColor3fv(C2);
    glVertex2f(-350, 0);
    glVertex2f(350, 0);
    glVertex2f(0, 350);
    glVertex2f(0, -350);
    glEnd();
    glFlush();
}
void MyInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-350, 350, -350, 350);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(150, 150);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(720, 720);
    glutCreateWindow("2D scalling in opengl");
    MyInit();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}