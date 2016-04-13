#include "voxelmesh.h"
#include <GL/glut.h>

VoxelMesh::VoxelMesh() {
  pos = Vec3();
  voxelDimension = 0.0f;
  resetMesh();
}

VoxelMesh::~VoxelMesh() { }

void VoxelMesh::generateVoxelMesh(TriMesh* mesh) {
  float longest = mesh->getBbox()->longestDim();
  voxelDimension = longest / VOXDIM;
  resetMesh();
	// to be implemented
}

void VoxelMesh::resetMesh() {
  for(int i=0;i<VOXDIM;i++)
    for(int j=0;j<VOXDIM;j++)
      for(int k=0;k<VOXDIM;k++)
        mesh[i][j][k] = false;
}

void VoxelMesh::drawMesh() {
  for(int i=0;i<VOXDIM;i++)
		for(int j=0;j<VOXDIM;j++)
			for(int k=0;k<VOXDIM;k++)
				if(mesh[i][j][k]) {
					Vec3 pos = Vec3(); // implement
					float dim = 0.0f; // implement
					drawCube(pos,dim);
				}
}

void VoxelMesh::drawCustomMesh(Voxel* voxel) {
  for(int i=0;i<VOXDIM,i++)
		for(int j=0;j<VOXDIM;j++)
			for(int k=0;k<VOXDIM;k++)
				if(mesh[i][j][k]) {
					Vec3 pos = Vec3(); // implement
					float dim = 0.0f; // implement
					voxel->drawVoxel(pos,dim);
				}
}

void VoxelMesh::drawCube(Vec3 pos,float dim) {
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

void VoxelMesh::setPos(Vec3 param) { pos = param; }
//void VoxelMesh::setVoxelDimension(float param) { voxelDimension = param; }
