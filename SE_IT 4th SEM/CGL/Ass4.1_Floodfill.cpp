#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void drawCircle(int x, int y) {
    int radius = 50;
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(x + cos(degInRad) * radius, y + sin(degInRad) * radius);
    }
    glEnd();
    glFlush();
}

void floodFill(int x, int y, float fill_color[], float old_color[]) {
    float current_color[4];
    glReadPixels(x, y, 1, 1, GL_RGBA, GL_FLOAT, current_color);
    
    if(current_color[0] == old_color[0] && current_color[1] == old_color[1] && current_color[2] == old_color[2]) {
        glColor4fv(fill_color);
        glBegin(GL_POINTS);
            glVertex2i(x, y);
        glEnd();
        glFlush();
        
        floodFill(x+1, y, fill_color, old_color);
        floodFill(x-1, y, fill_color, old_color);
        floodFill(x, y+1, fill_color, old_color);
        floodFill(x, y-1, fill_color, old_color);
    }
}

void onMouseClick(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float old_color[4] = {1.0, 1.0, 1.0, 1.0}; // White
        float fill_color[4] = {0.0, 1.0, 1.0, 1.0}; // Blue
        
        floodFill(x, 500-y, fill_color, old_color); // y-coordinates are inverted in OpenGL
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle(250, 250);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Flood Fill Algorithm");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(onMouseClick);
    glutMainLoop();
    return 0;
}