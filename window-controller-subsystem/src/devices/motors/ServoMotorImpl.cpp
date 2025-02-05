#include "devices/motors/ServoMotorImpl.hpp"
#include "Arduino.h"

ServoMotorImpl::ServoMotorImpl(int pin) {
    this->pin = pin;
    angle = 0;
}

void ServoMotorImpl::on() { motor.attach(pin); }

void ServoMotorImpl::moveToPosition(int angle) {
    if (angle > 180) {
        angle = 180;
    } else if (angle < 0) {
        angle = 0;
    }
    // 750 -> 0, 2250 -> 180
    // 750 + angle*(2250-750)/180
    // updated values: min is 544, max 2400 (see ServoTimer2 doc)
    float coeff = (2400.0 - 544.0) / 180;
    int dest = 544 + angle * coeff;
    angle = angle + 10 * (abs(dest - angle) / (dest - angle));

    motor.write(angle);
}

void ServoMotorImpl::off() { motor.detach(); }
