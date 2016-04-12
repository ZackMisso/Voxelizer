#ifndef __PROGRAMDATA_H__
#define __PROGRAMDATA_H__

#include "globalInclude.h"
#include "voxel.h"
#include "trimesh.h"
#include "voxelmesh.h"

class ProgramData {
private:
  Voxel* currentVoxel;
  TriMesh* currentTrimesh;
  VoxelMesh* currentVoxelMesh;
public:
  ProgramData();
  ~ProgramData();
  // getter methods
  Voxel* getCurrentVoxel();
  TriMesh* getCurrentTriMesh();
  VoxelMesh* getCurrentVoxelMesh();
  // setter methods
  void setCurrentVoxel(Voxel* param);
  void setCurrentTriMesh(TriMesh* param);
  void setCurrentVoxelMesh(VoxelMesh* param);
};

#endif
