#include "voxelmesh.h"
#include <GLFW/glfw3.h>

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
					//drawCube(pos,dim);
				}
}

void VoxelMesh::drawCustomMesh(Voxel* voxel) {
  for(int i=0;i<VOXDIM;i++)
		for(int j=0;j<VOXDIM;j++)
			for(int k=0;k<VOXDIM;k++)
				if(mesh[i][j][k]) {
					Vec3 pos = Vec3(); // implement
					float dim = 0.0f; // implement
					voxel->drawVoxel(pos,dim);
				}
}

void VoxelMesh::setPos(Vec3 param) { pos = param; }
//void VoxelMesh::setVoxelDimension(float param) { voxelDimension = param; }
