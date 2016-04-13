#ifndef __TRIMESH_H__
#define __TRIMESH_H__

#include "array.h"
#include "vertex.h"
#include "face.h"
#include "bbox.h"

class TriMesh{
private:
	Array<Vertex*>* verts;
	Array<Face*>* faces;
  Bbox* bbox;
  //Array<Normal*>* vertNorms;
public:
	TriMesh();
	~TriMesh();
	void normalCalc();
	void addVertex(float *values);
	void addFace(int *values);
  void calculateBbox();
	void draw();
  // getter methods
  Bbox* getBbox();
};

#endif
