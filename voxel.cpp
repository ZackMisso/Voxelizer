#include "voxel.h"
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

Voxel::Voxel() {
  resetMap();
  resetCube();
}

void Voxel::setMapVal(int y,int x,bool val) {
  map[y][x] = val;
}

void Voxel::flipMapVal(int y,int x) {
  map[y][x] = !map[y][x];
}

void Voxel::drawMap() {
  //cout << "Drawing Voxel" << endl;
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_QUADS);
  float d = 2.0f / ((float)MAPDIM);
  for(int i=0;i<MAPDIM;i++)
    for(int j=0;j<MAPDIM;j++)
      if(map[i][j]) {
        float x = 2.0f / ((float)MAPDIM) * ((float)j) - 1.0f;
        float y = 2.0f / ((float)MAPDIM) * ((float)i) - 1.0f;
        glVertex2f(x,y);
        glVertex2f(x+d,y);
        glVertex2f(x+d,y+d);
        glVertex2f(x,y+d);
      }
  glEnd();
}

void Voxel::drawVoxel(Vec3 pos,float dim) {
  // to be implemented
}

void Voxel::bake() {
  resetCube();
  for(int i=0;i<MAPDIM;i++) {
    for(int j=0;j<MAPDIM;j++) {
      if(map[i][j]) {
        // set the cube on every face
        int depth = i < j ? i+1 : j+1;
        // front (i,j,0)
        // back (i,j,max)
        // right (i,max,k)
        // left (i,0,k)
        // top (0,j,k)
        // bottom (max,j,k)
      }
    }
  }
  // to be implemented
}

void Voxel::resetMap() {
  for(int i=0;i<MAPDIM;i++)
    for(int j=0;j<MAPDIM;j++)
      map[i][j] = false;
}

void Voxel::resetCube() {
  for(int i=0;i<MAPDIM;i++)
    for(int j=0;j<MAPDIM;j++)
      for(int k=0;k<MAPDIM;k++)
        cube[i][j][k] = false;
}

void Voxel::drawSquare() {
  glBegin(GL_QUADS);
  glVertex2f(-0.5,-0.5);
  glVertex2f(-0.5,0.5);
  glVertex2f(0.5,0.5);
  glVertex2f(0.5,-0.5);
  glEnd();
}

void Voxel::drawCube(Vec3 pos,float d) {
	glBegin(GL_QUADS);
	glVertex3f(pos.x,pos.y,pos.z);
	glVertex3f(pos.x+d,pos.y,pos.z);
	glVertex3f(pos.x+d,pos.y-d,pos.z);
	glVertex3f(pos.x,pos.y-d,pos.z);

	glVertex3f(pos.x,pos.y,pos.z);
	glVertex3f(pos.x,pos.y,pos.z+d);
	glVertex3f(pos.x+d,pos.y,pos.z+d);
	glVertex3f(pos.x+d,pos.y,pos.z);

	glVertex3f(pos.x,pos.y,pos.z);
	glVertex3f(pos.x,pos.y-d,pos.z);
	glVertex3f(pos.x,pos.y-d,pos.z+d);
	glVertex3f(pos.x,pos.y,pos.z+d);

	glVertex3f(pos.x+d,pos.y-d,pos.z+d);
	glVertex3f(pos.x,pos.y-d,pos.z+d);
	glVertex3f(pos.x,pos.y,pos.z+d);
	glVertex3f(pos.x+d,pos.y,pos.z+d);

	glVertex3f(pos.x+d,pos.y-d,pos.z+d);
	glVertex3f(pos.x,pos.y-d,pos.z+d);
	glVertex3f(pos.x,pos.y-d,pos.z);
	glVertex3f(pos.x+d,pos.y-d,pos.z);

	glVertex3f(pos.x+d,pos.y-d,pos.z+d);
	glVertex3f(pos.x+d,pos.y,pos.z+d);
	glVertex3f(pos.x+d,pos.y,pos.z);
	glVertex3f(pos.x+d,pos.y-d,pos.z);
	glEnd();
}
