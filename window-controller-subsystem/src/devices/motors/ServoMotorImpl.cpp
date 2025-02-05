#include "devices/motors/ServoMotorImpl.hpp"
#include "Arduino.h"

ServoMotorImpl::ServoMotorImpl(int pin, int tickSpeedMS) {
    this->pin = pin;
    this->motorPosition = this->angleToPosition(0);
    this->off();
    // suggested speed for a miuzei microservo ms18 is 0.5 deg / ms
    this->stepSize = tickSpeedMS * 0.5;
}

int ServoMotorImpl::angleToPosition(int angle) {
    // 750 -> 0, 2250 -> 180
    // 750 + angle*(2250-750)/180
    // updated values: min is 544, max 2400 (see ServoTimer2 doc)
    float coeff = (2400.0 - 544.0) / 180;
    return 544 + angle * coeff;
}

void ServoMotorImpl::on() {
    state = true;
    motor.attach(pin);
}

bool ServoMotorImpl::getState() { return this->state; }

void ServoMotorImpl::moveToPosition(int angle) {
    if (angle > 180) {
        angle = 180;
    } else if (angle < 0) {
        angle = 0;
    }
    int dest = angleToPosition(angle);
    if (dest == motorPosition) {
        this->off();
        return;
    } else if (state == false) {
        this->on();
    }
    if (abs(dest - motorPosition) > stepSize) {
        motorPosition = motorPosition + stepSize * (abs(dest - motorPosition) / (dest - motorPosition));
    } else {
        motorPosition = dest;
    }

    motor.write(motorPosition);
}

void ServoMotorImpl::off() {
    state = false;
    motor.detach();
}
