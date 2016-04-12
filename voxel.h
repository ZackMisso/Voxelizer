#ifndef __VOXEL_H__
#define __VOXEL_H__

#include "globalInclude.h"

class Voxel {
private:
  bool map[MAPDIM][MAPDIM];
  void drawSquare();
  void drawCube();
public:
  Voxel();
  void setMapVal(int y,int x,bool val);
  void drawMap();
  void drawVoxel();
  void resetMap();
};

#endif
