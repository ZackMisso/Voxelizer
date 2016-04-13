#ifndef __PROGRAMDATA_H__
#define __PROGRAMDATA_H__

#include "globalInclude.h"
#include "voxel.h"
#include "trimesh.h"
#include "voxelmesh.h"
#include "trimeshLoader.h"

class ProgramData {
private:
  Voxel* currentVoxel;
  TriMesh* currentTrimesh;
  VoxelMesh* currentVoxelMesh;
  TriMeshLoader* loader;
  bool objectView;
  bool voxelView;
  bool customView;
  bool voxelizedView;
  bool mapView;
public:
  ProgramData();
  ~ProgramData();
  void falsifyViews();
  // getter methods
  Voxel* getCurrentVoxel();
  TriMesh* getCurrentTriMesh();
  VoxelMesh* getCurrentVoxelMesh();
  TriMeshLoader* getLoader();
  bool getObjectView();
  bool getVoxelView();
  bool getCustomView();
  bool getVoxelizedView();
  bool getMapView();
  // setter methods
  void setCurrentVoxel(Voxel* param);
  void setCurrentTriMesh(TriMesh* param);
  void setCurrentVoxelMesh(VoxelMesh* param);
  void setLoader(TriMeshLoader* param);
  void setObjectView(bool param);
  void setVoxelView(bool param);
  void setCustomView(bool param);
  void setVoxelizedView(bool param);
  void setMapView(bool param);
};

#endif
