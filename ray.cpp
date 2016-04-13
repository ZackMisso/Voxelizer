#include "ray.h"

Ray::Ray() {
	origin = Vec3();
	dir = Vec3();
}

Ray::Ray(Vec3 o,Vec3 d) {
	origin = o;
	dir = d;
}

Vec3 Ray::getOrigin() { return origin; }
Vec3 Ray::getDir() { return dir; }

void Ray::setOrigin(Vec3 param) { origin = param; }
void Ray::setDir(Vec3 param) { dir = param; }

