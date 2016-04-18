#include "control.h"

Control::Control() {
  mouseX = 0.0;
  mouseY = 0.0;
  clicking = false;
  clicked = false;
}

void Control::updateMousePosition(double x,double y) {
  if(!clicking) {
    mouseX = x;
    mouseY = y;
  }
}

void Control::updateClicking(bool click) {
  if(click) {
    if(clicking) {
      clicking = false;
      clicked = true;
    } else {
      clicking = true;
      clicked = false;
    }
  } else {
    clicking = false;
    clicked = false;
  }
}

double Control::getMouseX() { return mouseX; }
double Control::getMouseY() { return mouseY; }
bool Control::getClicking() { return clicking; }

void Control::setMouseX(double param) { mouseX = param; }
void Control::setMouseY(double param) { mouseY = param; }
void Control::setClicking(bool param) { clicking = param; }
