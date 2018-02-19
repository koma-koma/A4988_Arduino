#include <Arduino.h>

class A4988 {
  public:
    A4988(int pin_enable, int pin_step, int pin_direction);
    void setdeltime(int deltime);
    void move_steps(int steps);
  private:
    int _pin_enable;
    int _pin_step;
    int _pin_direction;
    int _deltime;
};

