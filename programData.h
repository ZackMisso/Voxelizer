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
  int winH;
  int winW;
  bool objectView;
  bool voxelView;
  bool customView;
  bool voxelizedView;
  bool mapView;
  RenderMode renderMode;
public:
  ProgramData();
  ~ProgramData();
  void falsifyViews();
  void falsifyRender();
  // getter methods
  Voxel* getCurrentVoxel();
  TriMesh* getCurrentTriMesh();
  VoxelMesh* getCurrentVoxelMesh();
  TriMeshLoader* getLoader();
  int getWinH();
  int getWinW();
  bool getObjectView();
  bool getVoxelView();
  bool getCustomView();
  bool getVoxelizedView();
  bool getMapView();
  RenderMode getRenderMode();
  // setter methods
  void setCurrentVoxel(Voxel* param);
  void setCurrentTriMesh(TriMesh* param);
  void setCurrentVoxelMesh(VoxelMesh* param);
  void setLoader(TriMeshLoader* param);
  void setWinH(int param);
  void setWinW(int param);
  void setObjectView(bool param);
  void setVoxelView(bool param);
  void setCustomView(bool param);
  void setVoxelizedView(bool param);
  void setMapView(bool param);
  void setRenderMode(RenderMode param);
};

#endif
