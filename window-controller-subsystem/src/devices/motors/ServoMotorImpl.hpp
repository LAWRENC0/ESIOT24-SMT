#ifndef __SERVO_MOTOR_IMPL__
#define __SERVO_MOTOR_IMPL__

#include "devices/motors/ServoMotor.hpp"
#include <arduino.h>
#include "ServoTimer2.h"

class ServoMotorImpl : public ServoMotor {
   public:
    ServoMotorImpl(int pin, int tickSpeedMS);

    void on();
    void moveToPosition(int angle);
    int getAngle();
    void off();
    bool getState();
    int angleToPosition(int angle);

   private:
    int pin;
    int motorPosition;
    int stepSize;
    bool state;
    ServoTimer2 motor;
};

#endif
