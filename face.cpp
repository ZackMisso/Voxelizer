#include "face.h"

Face::Face(int* vals) {
  ind[0] = vals[0];
  ind[1] = vals[1];
  ind[2] = vals[2];
}

void Face::calculateNorm(Array<Vertex*>* vs) {
  // to be implemented
}

void Face::draw(Array<Vertex*>* verts) {
  // to be implemented
}
