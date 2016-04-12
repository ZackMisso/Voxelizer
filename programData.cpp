#include "programData.h"

ProgramData::ProgramData() {
  currentVoxel = new Voxel();
  currentTrimesh = new TriMesh();
  currentVoxelMesh = new VoxelMesh();
}

ProgramData::~ProgramData() {
  delete currentVoxel;
  delete currentTrimesh;
  delete currentVoxelMesh;
}

Voxel* ProgramData::getCurrentVoxel() { return currentVoxel; }
TriMesh* ProgramData::getCurrentTriMesh() { return currentTrimesh; }
VoxelMesh* ProgramData::getCurrentVoxelMesh() { return currentVoxelMesh; }

void ProgramData::setCurrentVoxel(Voxel* param) { currentVoxel = param; }
void ProgramData::setCurrentTriMesh(TriMesh* param) { currentTrimesh = param; }
void ProgramData::setCurrentVoxelMesh(VoxelMesh* param) { currentVoxelMesh = param; }
