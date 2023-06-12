#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int length, xi, yi, choice;
double angle, ET[3][3], ETResult[3][3];
void drawET(double ET[3][3])
{
    int i;
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 3; i++)
    {
        glVertex2i(ET[i][0], ET[i][1]);
    }
    glEnd();
}

void Display()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-320, 320, -240, 240);
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex2d(-320, 0);
    glVertex2d(320, 0);
    glVertex2d(0, -240);
    glVertex2d(0, 240);
    glEnd();
    glColor3f(1, 0, 0);
    drawET(ET);
    glFlush();
}

void mult3X3(double ET[3][3], double temp[3][3])
{
    double sum;
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum = 0;
            for (int k = 0; k < 3; k++)
            {
                sum = sum + ET[i][k] * temp[k][j];
            }
            ETResult[i][j] = sum;
        }
    }
}
void translationET()
{
    double tx, ty, temp[3][3];
    cout << "\nTranslating Equilateral triangle";
    cout << "\nEnter Tx: ";
    // cin>>("%lf", &tx);
    cin >> tx;
    cout << "\nEnter Ty: ";
    // cin>>("%lf", &ty);
    cin >> ty;
    temp[3][3] = {0};
    temp[0][0] = 1;
    temp[1][1] = 1;
    temp[2][2] = 1;
    temp[2][0] = tx;
    temp[2][1] = ty;
    mult3X3(ET, temp);
    glColor3f(0.0, 1.0, 0.0);
    drawET(ETResult);
}
void rotationET()
{
    double rx, ry, angle, temp[3][3];
    cout << "\n**ROTATION**\n";
    // cout<<"\nArbitrary Point (x,y) : ");
    // cin>>("%lf %lf", &rx, &ry);
    cout << "\nAngle (in degrees) : ";
    cin >> angle;
    angle = angle * (M_PI / 180);
    temp[3][3] = {0};
    // anti clock
    temp[0][0] = cos(angle);
    temp[0][1] = sin(angle);  //(clock -> -sin)
    temp[1][0] = -sin(angle); // clock -> sin
    temp[1][1] = cos(angle);
    temp[2][0] = 0;
    temp[2][1] = 0;
    temp[0][2] = 0;
    temp[1][2] = 0;
    temp[2][2] = 1;
    mult3X3(ET, temp);
    glColor3f(0.0, 1.0, 0.0);
    drawET(ETResult);
}
//----------Reflection-------------//
void reflectX() // creation of reflection to X axix matrix
{
    double temp[3][3];
    temp[0][0] = 1;
    temp[0][1] = 0;
    temp[0][2] = 0;
    temp[1][0] = 0;
    temp[1][1] = -1;
    temp[1][2] = 0;
    temp[2][0] = 0;
    temp[2][1] = 0;
    temp[2][2] = 1;
    mult3X3(ET, temp);
    glColor3f(0.0, 1.0, 0.0);
    drawET(ETResult);
}
void reflectY() // creation of reflection to X axix matrix
{
    double temp[3][3];
    temp[0][0] = -1;
    temp[0][1] = 0;
    temp[0][2] = 0;
    temp[1][0] = 0;
    temp[1][1] = 1;
    temp[1][2] = 0;
    temp[2][0] = 0;
    temp[2][1] = 0;
    temp[2][2] = 1;
    mult3X3(ET, temp);
    glColor3f(0.0, 1.0, 0.0);
    drawET(ETResult);
}
//----------Scaling-------------//
void scaleET()
{
    double sx, sy, temp[3][3];
    cout << "\nScaling Equilateral triangle";
    cout << "\nSx: ";
    cin >> sx;
    cout << "\nSy: ";
    cin >> sy;
    temp[3][3] = {0};
    temp[0][0] = sx;
    temp[1][1] = sy;
    temp[2][2] = 1;
    mult3X3(ET, temp);
    glColor3f(1.0, 1.0, 0.0);
    drawET(ETResult);
}
//----------Shearing-------------//
void shearET()
{
    double xs, ys, temp[3][3];

    cout<<"\nShear Equilateral triangle";
    cout<<"\nPress 1: X - Shear";
    cout<<"\nPress 2: Y - Shear";
    cout<<"\nEnter your Choice: ";
    cin>>choice;

    temp[3][3] = {0};

    switch (choice)
    {
    case 1:
        cout<<"\nX-shear value: ";
        cin>>xs;
        temp[0][0] = 1;
        temp[1][0] = xs;
        temp[1][1] = 1;
        temp[2][2] = 1;
        break;
    case 2:
        cout<<"\nY-shear value: ";
        cin>>ys;
        temp[0][0] = 1;
        temp[0][1] = ys;
        temp[1][1] = 1;
        temp[2][2] = 1;
        break;
    }
    mult3X3(ET, temp);
    glColor3f(1.0, 1.0, 0.0);
    drawET(ETResult);
}
//----------MENU--------------//
void Menu(int item)
{
    switch (item)
    {
    case 1:
        translationET();
        break;
    case 2:
        rotationET();
        break;
    case 3:
        reflectX();
        break;
    case 4:
        reflectY();
        break;
    case 5:
        scaleET();
        break;
    case 6:
        shearET();
        break;
    case 7:
        exit(0);
        break;
    }
}
int main(int argc, char **argv)
{
    int i, j;
    cout << "\nEnter X co-ordinate of a Base point: ";
    cin >> xi;
    cout << "\nEnter Y co-ordinate of the Base point:";
    cin >> yi;
    cout << "\nEnter length of sides: ";
    cin >> length;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            ET[i][j] = 1;
        }
    }
    ET[0][0] = xi;
    ET[0][1] = yi;
    ET[1][0] = xi + length;
    ET[1][1] = yi;
    ET[2][0] = xi + (length / 2);
    ET[2][1] = (sqrt(3) / 2 * length) + yi;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2D-TRANSFORMATIONS");
    glutDisplayFunc(Display);
    glutCreateMenu(Menu);
    glutAddMenuEntry("1.Translation", 1);
    glutAddMenuEntry("2.Rotation", 2);
    glutAddMenuEntry("3.ReflectX", 3);
    glutAddMenuEntry("4.ReflectY", 4);
    glutAddMenuEntry("5.Scaling", 5);
    glutAddMenuEntry("6.Shearing", 6);
    glutAddMenuEntry("7.EXIT", 7);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}