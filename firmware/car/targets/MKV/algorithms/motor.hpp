#pragma once
#include <utility>

class Differential {
  private:
    constexpr static float engineCutoffValue = 50.0;
    constexpr static float engineBrakingCoefficient = engineCutoffValue * 1.5;
    constexpr static float engineCutoffValueSquared = engineCutoffValue * engineCutoffValue;

    int   position;
    float startVelocity;
    float valueLeft;
    float valueRight;

  public:
    /**
     *@brief set velocity adequate to current conditions on track
     *@param startVelocity is the default speed of the car
     *@param position is the current position of the car on the track
    */
    Differential(float startVelocity);

    void  proc(int position);
    float getLeft();
    float getRight();
    void  setStartVelocity(float value);
    float getStartVelocity();
};
