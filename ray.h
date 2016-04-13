#ifndef __RAY_H__
#define __RAY_H__

#include "vec3.h"

class Ray {
private:
	Vec3 origin;
	Vec3 dir;
public:
	Ray();
	Ray(Vec3 o,Vec3 d);
	// getter methods
	Vec3 getOrigin();
	Vec3 getDir();
	// setter methods
	void setOrigin(Vec3 param);
	void setDir(Vec3 param);
};

#endif

