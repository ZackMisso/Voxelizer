#include "modeler.h"

void Modeler::drawCube(RenderMode rm) {
  if(rm == WIREFRAME) {
    glBegin(GL_LINES);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);

    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);

    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,1.0);

    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);

    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);

    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);

    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);

    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);

    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);

    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);

    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);

    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);

    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,1.0);
  } else if(rm == SOLID) {
    glBegin(GL_QUADS);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
  } else if(rm == SHADED) {
    // to be implemented
  }
	glEnd();
}

void Modeler::drawCube(RenderMode rm,Vec3 pos,float d) {
  if(rm == WIREFRAME) {
    glBegin(GL_LINES);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);

    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);

    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,1.0);

    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);

    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);

    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);

    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);

    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);

    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);

    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);

    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);

    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);

    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,1.0);
  } else if(rm == SOLID) {
    glBegin(GL_QUADS);
  	glVertex3f(pos.x-d,pos.y-d,pos.z-d);
  	glVertex3f(pos.x+d,pos.y-d,pos.z-d);
  	glVertex3f(pos.x+d,pos.y+d,pos.z-d);
  	glVertex3f(pos.x-d,pos.y+d,pos.z-d);

  	glVertex3f(pos.x-d,pos.y-d,pos.z-d);
  	glVertex3f(pos.x-d,pos.y-d,pos.z+d);
  	glVertex3f(pos.x+d,pos.y-d,pos.z+d);
  	glVertex3f(pos.x+d,pos.y-d,pos.z-d);

  	glVertex3f(pos.x-d,pos.y-d,pos.z-d);
  	glVertex3f(pos.x-d,pos.y+d,pos.z-d);
  	glVertex3f(pos.x-d,pos.y+d,pos.z+d);
  	glVertex3f(pos.x-d,pos.y-d,pos.z+d);

  	glVertex3f(pos.x+d,pos.y+d,pos.z+d);
  	glVertex3f(pos.x+d,pos.y-d,pos.z+d);
  	glVertex3f(pos.x+d,pos.y-d,pos.z-d);
  	glVertex3f(pos.x+d,pos.y+d,pos.z-d);

  	glVertex3f(pos.x+d,pos.y+d,pos.z+d);
  	glVertex3f(pos.x+d,pos.y+d,pos.z-d);
  	glVertex3f(pos.x-d,pos.y+d,pos.z-d);
  	glVertex3f(pos.x-d,pos.y+d,pos.z+d);

  	glVertex3f(pos.x+d,pos.y+d,pos.z+d);
  	glVertex3f(pos.x-d,pos.y+d,pos.z+d);
  	glVertex3f(pos.x-d,pos.y-d,pos.z+d);
  	glVertex3f(pos.x+d,pos.y-d,pos.z+d);
  } else if(rm == SHADED) {
    // to be implemented
  }
	glEnd();
}
