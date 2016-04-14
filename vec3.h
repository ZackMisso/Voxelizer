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
	inline Vec3 operator+(const Vec3& other) const;
	inline Vec3 operator-(const Vec3& other) const;
	inline Vec3 operator^(const Vec3& other) const; // cross product
	inline float operator*(const Vec3& other) const; // dot product
};

#endif
