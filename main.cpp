#include "programData.h"

ProgramData* programData;

// openGL methods
void display();
void reshape(int w,int h);
void keyboard(unsigned char key,int x,int y);
void mouseMove(int x,int y);
void mouseClick(int button, int state, int x,int y);
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

int main() {
  programData = new ProgramData();
  cout << "I AM DOING A THING" << endl;
  glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Zack Misso");
	glutDisplayFunc(display);
	// to be implemented
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMove);
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
  // to be implemented
}

void reshape(int w,int h) {
	// reshapes the view after the window changes shape
	//glViewport(0,0,w,h);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective(65.0,(float)h/w,.1,100);
	//glMatrixMode(GL_MODELVIEW);
	//glutPostRedisplay();
}

void keyboard(unsigned char key,int x,int y) {
  // to be implemented
}

void mouseMove(int x,int y) {
  // to be implemented
}

void mouseClick(int button, int state, int x,int y) {
  // to be implemented
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
