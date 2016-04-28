#include "programData.h"
#include "control.h"
#include "modeler.h"

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

ProgramData* programData;
Control* control;

// debug code
double dt;

// openGL methods
void display();
void reshape(int w,int h);
void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods);
void mouseMove(GLFWwindow* window,double x,double y);
void mouseClick(GLFWwindow* window,int button,int action,int mods);
void error(int error, const char* description);
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
  // initialize needed data
  programData = new ProgramData();
  programData->setMapView(true);
  control = new Control();
  // initialize glfw
  if(!glfwInit())
    exit(EXIT_FAILURE);
  GLFWwindow* window = glfwCreateWindow(1000,1000,"Zack Misso - Voxelizer",NULL,NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  int width;
  int height;
  glfwSetErrorCallback(error);
  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window,keyboard);
  glfwSetCursorPosCallback(window,mouseMove);
  glfwSetMouseButtonCallback(window,mouseClick);
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0,0,width,height);
  glfwSwapInterval(1);
  transitionToMapView();
  programData->setWinW(width);
  programData->setWinH(height);
  // main loop
  while (!glfwWindowShouldClose(window))
  {
    dt+=.1;
    // Main Loop
    display();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  glfwTerminate();
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
}

void displayObjectView() {
  // to be implemented
}

void displayVoxelView() {
  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(35.0,(float)programData->getWinH()/programData->getWinW(),.1,10);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0,0.0,-6.0,0.0,0.0,0.0,0.0,1.0,0.0);
  // test by drawing a cube
  glRotatef(dt,0.0,1.0,0.0);
  glRotatef(30,1.0,0.0,0.0);
  glScalef(0.4f,0.4f,0.4f);
  glTranslatef(0.0f,-0.1f,0.0f);
  Modeler::drawCube(SOLID,Vec3(0.0,0.0,0.0),1.0f);
}

void displayCustomView() {
  // to be implemented
}

void displayVoxelizedView() {
  // to be implemented
}

void displayMapView() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

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

  glEnd();

  programData->getCurrentVoxel()->drawMap();
}

void reshape(int w,int h) {
	// reshapes the view after the window changes shape
  glViewport(0,0,w,h);
  programData->setWinW(w);
  programData->setWinH(h);
}

void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods) {
  if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
    glfwSetWindowShouldClose(window,GL_TRUE);
  if(key == GLFW_KEY_O && action == GLFW_PRESS)
    transitionToObjectView();
  if(key == GLFW_KEY_V && action == GLFW_PRESS)
    transitionToVoxelView();
  if(key == GLFW_KEY_C && action == GLFW_PRESS)
    transitionToCustomView();
  if(key == GLFW_KEY_D && action == GLFW_PRESS)
    transitionToVoxelizedView();
  if(key == GLFW_KEY_M && action == GLFW_PRESS)
    transitionToMapView();
  if(key == GLFW_KEY_G && action == GLFW_PRESS)
    programData->getCurrentVoxel()->bake();
  if(key == GLFW_KEY_W && action == GLFW_PRESS)
    programData->setRenderMode(WIREFRAME);
  if(key == GLFW_KEY_S && action == GLFW_PRESS)
    programData->setRenderMode(SOLID);
  if(key == GLFW_KEY_W && action == GLFW_PRESS)
    programData->setRenderMode(SHADED);
}

void mouseMove(GLFWwindow* window,double x,double y) {
  control->updateMousePosition(x,y);
}

void mouseClick(GLFWwindow* window,int button,int action,int mods) {
  // Control Updates
  if(button == GLFW_MOUSE_BUTTON_LEFT && GLFW_PRESS)
    control->updateClicking(true);
  if(button == GLFW_MOUSE_BUTTON_LEFT && GLFW_RELEASE)
    control->updateClicking(false);
  // Cases Per View
  if(programData->getMapView()) {
    if(control->getClicking()) {
      int mapX = (int)(control->getMouseX() / ((double)programData->getWinW()) * ((double)MAPDIM));
      int mapY = (int)(control->getMouseY() / ((double)programData->getWinH()) * ((double)MAPDIM));
      programData->getCurrentVoxel()->flipMapVal(mapY,mapX);
      programData->getCurrentVoxel()->flipMapVal(MAPDIM-1-mapY,mapX);
      programData->getCurrentVoxel()->flipMapVal(mapY,MAPDIM-1-mapX);
      programData->getCurrentVoxel()->flipMapVal(MAPDIM-1-mapY,MAPDIM-1-mapX);
    }
  }
}

void error(int error, const char* description) {
  // to be implemented
}

void transitionToObjectView() {
  // to be implemented
}

void transitionToVoxelView() {
  programData->falsifyViews();
  programData->setVoxelView(true);
}

void transitionToCustomView() {
  // to be implemented
}

void transitionToVoxelizedView() {
  // to be implemented
}

void transitionToMapView() {
  programData->falsifyViews();
  programData->setMapView(true);
}
