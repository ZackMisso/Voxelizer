#include "programData.h"

ProgramData::ProgramData() {
  currentVoxel = new Voxel();
  currentTrimesh = new TriMesh();
  currentVoxelMesh = new VoxelMesh();
  loader = new TriMeshLoader();
  winH = 1000;
  winW = 1000;
  renderMode = SOLID;
}

ProgramData::~ProgramData() {
  delete currentVoxel;
  delete currentTrimesh;
  delete currentVoxelMesh;
  delete loader;
}

void ProgramData::falsifyViews() {
  objectView = false;
  voxelView = false;
  customView = false;
  voxelizedView = false;
  mapView = false;
}

Voxel* ProgramData::getCurrentVoxel() { return currentVoxel; }
TriMesh* ProgramData::getCurrentTriMesh() { return currentTrimesh; }
VoxelMesh* ProgramData::getCurrentVoxelMesh() { return currentVoxelMesh; }
TriMeshLoader* ProgramData::getLoader() { return loader; }
int ProgramData::getWinH() { return winH; }
int ProgramData::getWinW() { return winW; }
bool ProgramData::getObjectView() { return objectView; }
bool ProgramData::getVoxelView() { return voxelView; }
bool ProgramData::getCustomView() { return customView; }
bool ProgramData::getVoxelizedView() { return voxelizedView; }
bool ProgramData::getMapView() { return mapView; }
RenderMode ProgramData::getRenderMode() { return renderMode; }

void ProgramData::setCurrentVoxel(Voxel* param) { currentVoxel = param; }
void ProgramData::setCurrentTriMesh(TriMesh* param) { currentTrimesh = param; }
void ProgramData::setCurrentVoxelMesh(VoxelMesh* param) { currentVoxelMesh = param; }
void ProgramData::setLoader(TriMeshLoader* param) { loader = param; }
void ProgramData::setWinH(int param) { winH = param; }
void ProgramData::setWinW(int param) { winW = param; }
void ProgramData::setObjectView(bool param) { objectView = param; }
void ProgramData::setVoxelView(bool param) { voxelView = param; }
void ProgramData::setCustomView(bool param) { customView = param; }
void ProgramData::setVoxelizedView(bool param) { voxelizedView = param; }
void ProgramData::setMapView(bool param) { mapView = param; }
void ProgramData::setRenderMode(RenderMode param) { renderMode = param; }
