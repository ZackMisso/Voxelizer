#include "voxel.h"

Voxel::Voxel() {
  resetMap();
}

void Voxel::setMapVal(int y,int x,bool val) {
  map[y][x] = val;
}

void Voxel::drawMap() {
  // to be implemented
}

void Voxel::drawVoxel() {
  // to be implemented
}

void Voxel::resetMap() {
  for(int i=0;i<MAPDIM;i++)
    for(int j=0;j<MAPDIM;j++)
      map[i][j] = false;
}

void Voxel::drawSquare() {
  // to be implemented
}

void Voxel::drawCube() {
  // to be implemented
}
