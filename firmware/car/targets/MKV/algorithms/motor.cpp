#include "motor.hpp"

#include <utility>

Differential::Differential(float startVelocityValue) : startVelocity(startVelocityValue) {}

void Differential::proc(int position) {
    if (position < 0) {
        valueRight = (startVelocity * (engineCutoffValue + (position))) / engineCutoffValue;
        valueLeft  = (startVelocity * (engineBrakingCoefficient + (position))) / engineBrakingCoefficient;
    } else if (position > 0) {
        valueLeft  = (startVelocity * (engineCutoffValue - (position))) / engineCutoffValue;
        valueRight = (startVelocity * (engineBrakingCoefficient - (position))) / engineBrakingCoefficient;
    }
}
float Differential::getLeft() { return valueLeft; }
float Differential::getRight() { return valueRight; }
void  Differential::setStartVelocity(float value) { startVelocity = value; }
float Differential::getStartVelocity() { return startVelocity; }
