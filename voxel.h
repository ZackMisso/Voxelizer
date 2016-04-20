#ifndef __VOXEL_H__
#define __VOXEL_H__

#include "globalInclude.h"
#include "vec3.h"

class Voxel {
private:
  bool map[MAPDIM][MAPDIM];
  bool cube[MAPDIM][MAPDIM][MAPDIM];
  void drawSquare();
public:
  Voxel();
  void setMapVal(int y,int x,bool val);
  void flipMapVal(int y,int x);
  void drawMap();
  void bake();
  void drawVoxel(Vec3 pos,float dim);
  void resetMap();
  void resetCube();
};

#endif
