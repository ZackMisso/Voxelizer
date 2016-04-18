#ifndef __VEC3_H__
#define __VEC3_H__

class Vec3 {
public:
  float x;
  float y;
  float z;
  Vec3();
  Vec3(float xpos,float ypos,float zpos);
	// operator overloads
	Vec3 operator+(const Vec3& other) const;
	Vec3 operator-(const Vec3& other) const;
	Vec3 operator^(const Vec3& other) const; // cross product
	float operator*(const Vec3& other) const; // dot product
};

#endif
