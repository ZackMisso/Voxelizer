#ifndef __MODELER_H__
#define __MODELER_H__

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "vec3.h"
#include "globalInclude.h"

class Modeler {
public:
  static void drawCube(RenderMode rm);
  static void drawCube(RenderMode rm,Vec3 pos,float dim);
};

#endif
