#ifndef __VOXEL_H__
#define __VOXEL_H__

#include "globalInclude.h"

class Voxel {
private:
  bool map[MAPDIM][MAPDIM];
  bool cube[MAPDIM][MAPDIM][MAPDIM];
  void drawSquare();
  void drawCube();
public:
  Voxel();
  void setMapVal(int y,int x,bool val);
  void flipMapVal(int y,int x);
  void drawMap();
  void bake();
  void drawVoxel();
  void resetMap();
  void resetCube();
};

#endif
