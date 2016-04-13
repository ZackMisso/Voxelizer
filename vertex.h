#ifndef __VERTEX_H__
#define __VERTEX_H__

class Vertex {
private:
  Vec3 pos;
  Vec3 norm;
public:
  Vertex();
  Vertex(Vec3 p,Vec3 n);
  // getter methods
  Vec3 getPos();
  Vec3 getNorm();
  // setter methods
  void setPos(Vec3 param);
  void setNorm(Vec3 param);
};

#endif
