/**
 * Copyright (c) Kolo Naukowe Elektronikow, Akademia Gorniczo-Hutnicza im. Stanislawa Staszica w Krakowie 2020
 * Authors: Dominik Michalczyk, Kacper Cwiokowski
 *
 * Kitty algorithm
 *
 */

#include "servo.hpp"

#include <cstddef>
#include <stdbool.h>
#include <stdint.h>

#pragma once

class Algorithm {
  private:
    constexpr static uint32_t cameraDataSize     = 128;  // Size of the camera data
    constexpr static uint32_t imageWindowSize    = 10;   // Cut unused pixels from both sides
    constexpr static float   brightnessModifier = 1.0f;
    constexpr static int32_t poistionOffset     = -8;

    constexpr static float alpha           = 0.05f; // Filter parameter
    constexpr static float delta           = 3;     // Filter parameter
    float                  average         = 0;     // Average value of the measurements
    float                  lastMeasurement = 0;     // Last measurement


    uint32_t brightness = 0; // Calculated brightness, used for finding crossings with camera data

    int32_t lastPosition = 0;

  public:
    Algorithm(){};
    int32_t calculatePosition(uint16_t* data);
    int32_t getBrightness() const { return brightness; } // Get brightness, used to print on the chart

  protected:
    uint32_t calculateBrightness(uint16_t* data);
    int32_t  calculateSlidingWindow();
    int32_t  meanFilter(int32_t measurement);
};
