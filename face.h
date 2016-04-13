#ifndef __FACE_H__
#define __FACE_H__

#include "vertex.h"
#include "array.h"
#include "vec3.h"

class Face{
private:
	int ind[3];
	Vec3 norm;
public:
	Face(int *vals);
	void calculateNorm(Array<Vertex*> *vs);
	void draw(Array<Vertex*>* verts);
};

#endif
