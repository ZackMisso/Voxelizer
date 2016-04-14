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

bool Face::collides(Ray* ray,Array<Vertex*>* verts) {
	Vec3 a = verts->get(ind[0])->getPos();
	Vec3 b = verts->get(ind[1])->getPos();
	Vec3 c = verts->get(ind[2])->getPos();

	Vec3 e1 = b - a;
	Vec3 e2 = c - a;

	Vec3 p = ray->getDir()^e2;
	float det = e1*p;

	if(det > -.0000001 && det < .0000001)
		return false;

	float invDet = 1.0f/det;

	Vec3 T = ray->getOrigin()-a;

	float u = T*p*invDet;
	if(u < 0.0f || u > 1.0f)
		return false;

	Vec3 Q = T^e1;
	
	float v = ray->getDir()*Q*invDet;
	if(v < 0.0f || u + v > 1.0f)
		return false;

	float t = e2*Q*invDet;

	return t > .0000001;
}

