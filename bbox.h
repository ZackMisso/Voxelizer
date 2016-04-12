#ifndef __BBOX_H__
#define __BBOX_H__

#include "vec3.h"

class Bbox {
private:
  Vec3 pos;
  Vec3 dim;
public:
  Bbox();
  Bbox(Vec3 p,Vec3 d);
  float longestDim();
  // getter methods
  Vec3 getPos();
  Vec3 getDim();
  // setter methods
  void setPos(Vec3 param);
  void setDim(Vec3 param);
};

#endif
