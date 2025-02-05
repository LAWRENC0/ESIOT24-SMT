#include "devices/potentiometer/Potentiometer.hpp"
#include "Arduino.h"

Potentiometer::Potentiometer(int pin) { this->pin = pin; }

int Potentiometer::getValue() { return analogRead(pin); }