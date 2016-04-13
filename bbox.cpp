#include "bbox.h"

Bbox::Bbox() {
  pos = Vec3();
  dim = Vec3();
}

Bbox::Bbox(Vec3 p,Vec3 d) {
  pos = p;
  dim = d;
}

float Bbox::longestDim() {
  float longest = dim.x;
  if(dim.y > longest)
    longest = dim.y;
  if(dim.z > longest)
    longest = dim.z;
  return longest;
}

float Bbox::volume() {
  return dim.x * dim.y * dim.z;
}

Vec3 getPos() { return pos; }
Vec3 getDim() { return dim; }

void setPos(Vec3 param) { pos = param; }
void setDim(Vec3 param) { dim = param; }
