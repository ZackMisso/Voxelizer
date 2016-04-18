#ifndef __CONTROL_H__
#define __CONTROL_H__

class Control {
private:
  double mouseX;
  double mouseY;
  bool clicking;
  bool clicked;
public:
  Control();
  void updateMousePosition(double x,double y);
  void updateClicking(bool click);
  // getter methods
  double getMouseX();
  double getMouseY();
  bool getClicking();
  // setter methods
  void setMouseX(double param);
  void setMouseY(double param);
  void setClicking(bool param);
};

#endif
