#include "programData.h"
#include <GL/glut.h>

ProgramData* programData;

// openGL methods
void display();
void reshape(int w,int h);
void keyboard(unsigned char key,int x,int y);
void mouseMove(int x,int y);
void mouseClick(int button,int state,int x,int y);
// display methods
void displayObjectView();
void displayVoxelView();
void displayCustomView();
void displayVoxelizedView();
void displayMapView();
// transition methods
void transitionToObjectView();
void transitionToVoxelView();
void transitionToCustomView();
void transitionToVoxelizedView();
void transitionToMapView();

int main(int argc,char** argv) {
  programData = new ProgramData();
  programData->setMapView(true);
  cout << "I AM DOING A THING" << endl;
  glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Zack Misso - Voxelizer");
	glutDisplayFunc(display);
	// to be implemented
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMove);
  transitionToMapView();
  glutMainLoop();

  return 0;
}

void display() {
  if(programData->getObjectView())
    displayObjectView();
  if(programData->getVoxelView())
    displayVoxelView();
  if(programData->getCustomView())
    displayCustomView();
  if(programData->getVoxelizedView())
    displayVoxelizedView();
  if(programData->getMapView())
    displayMapView();
  glutSwapBuffers();
}

void displayObjectView() {
  // to be implemented
}

void displayVoxelView() {
  // to be implemented
}

void displayCustomView() {
  // to be implemented
}

void displayVoxelizedView() {
  // to be implemented
}

void displayMapView() {
  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLineWidth(.5);
  glBegin(GL_LINES);
  glColor4f(0.7f,0.7f,0.7f,0.5f);
  // Draw Grid for Map
  for(float i=-1.0f;i<=1.0f;i+=2.0f/MAPDIM) {
    glVertex2f(i,1.0);
    glVertex2f(i,-1.0);
    glVertex2f(1.0f,i);
    glVertex2f(-1.0f,i);
  }
  glVertex2f(1.0,1.0);
  glVertex2f(1.0,-1.0);
  glVertex2f(1.0f,1.0);
  glVertex2f(-1.0f,1.0);

  programData->getCurrentVoxel()->drawMap();

  glEnd();
}

void reshape(int w,int h) {
	// reshapes the view after the window changes shape
  if(programData->getMapView())
    glViewport(0,0,w,h);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective(65.0,(float)h/w,.1,100);
	//glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void keyboard(unsigned char key,int x,int y) {
  if(key == 'o')
    transitionToObjectView();
  if(key == 'v')
    transitionToVoxelView();
  if(key == 'c')
    transitionToCustomView();
  if(key == 'd')
    transitionToVoxelizedView();
  if(key == 'm')
    transitionToMapView();
  glutPostRedisplay();
}

void mouseMove(int x,int y) {
  // to be implemented
}

void mouseClick(int button,int state,int x,int y) {
  if(programData->getMapView()) {
    int mapX;
    int mapY;

    // get stuff
  }
}

void transitionToObjectView() {
  // to be implemented
}

void transitionToVoxelView() {
  // to be implemented
}

void transitionToCustomView() {
  // to be implemented
}

void transitionToVoxelizedView() {
  // to be implemented
}

void transitionToMapView() {
  // to be implemented
}
