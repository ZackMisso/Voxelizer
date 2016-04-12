#ifndef __VOXELMESH_H__
#define __VOXELMESH_H__

#include "globalInclude.h"
#include "vec3.h"
#include "trimesh.h"
#include "voxel.h"

class VoxelMesh {
private:
  Vec3 pos;
  bool mesh[VOXDIM][VOXDIM][VOXDIM];
  float voxelDimension;
  void resetMesh();
public:
  VoxelMesh();
  ~VoxelMesh();
  void generateVoxelMesh(TriMesh* mesh);
  void drawMesh();
  void drawCustomMesh(Voxel* voxel);
  // setter methods
  void setPos(Vec3 param);
  //void setVoxelDimension(float param);
};

#endif
