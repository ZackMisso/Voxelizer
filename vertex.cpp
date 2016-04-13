#include "vertex.h"

Vertex::Vertex() {
  pos = Vec3();
  norm = Vec3();
}

Vertex::Vertex(Vec3 p,Vec3 n) {
  pos = p;
  norm = n;
}

Vec3 Vertex::getPos() { return pos; }
Vec3 Vertex::getNorm() { return norm; }

void Vertex::setPos(Vec3 param) { pos = param; }
void Vertex::setNorm(Vec3 param) { norm = param; }
