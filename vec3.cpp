#include "vec3.h"

Vec3::Vec3() {
  x = 0.0f;
  y = 0.0f;
  z = 0.0f;
}

Vec3::Vec3(float xpos,float ypos,float zpos) {
  x = xpos;
  y = ypos;
  z = zpos;
}

Vec3 Vec3::operator+(const Vec3& other) const {
	return Vec3(x+other.x,y+other.y,z+other.z);
}

Vec3 Vec3::operator-(const Vec3& other) const {
	return Vec3(x-other.x,y-other.y,z-other.z);
}

Vec3 Vec3::operator^(const Vec3& other) const {
	// to be implemented
	return Vec3();
}

float Vec3::operator*(const Vec3& other) const {
	return x*other.x + y*other.y + z*other.z;
}

