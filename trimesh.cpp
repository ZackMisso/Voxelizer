#include "trimesh.h"

TriMesh::TriMesh() {
  verts = new Array<Vertex*>();
  faces = new Array<Face*>();
  bbox = new Bbox();
}

TriMesh::~TriMesh() {
  while(verts->getSize())
    delete verts->removeLast();
  while(faces->getSize())
    delete faces->removeLast();
  delete faces;
  delete verts;
  delete bbox;
}

void TriMesh::normalCalc() {
  // to be implemented
}

void TriMesh::addVertex(float* vals) {
  Vec3 tmp = Vec3(vals[0],vals[1],vals[2]);
  Vertex* v = new Vertex();
  v->setPos(tmp);
  verts->add(v);
}

void TriMesh::addFace(int *vals) {
  faces->add(new Face(vals))
}

void TriMesh::calculateBbox() {
  // to be implemented
}

Bbox* TriMesh::getBbox() { return bbox; }
