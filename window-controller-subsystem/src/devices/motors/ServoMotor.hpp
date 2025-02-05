#ifndef __SERVO_MOTOR__
#define __SERVO_MOTOR__

class ServoMotor {
   public:
    virtual void on() = 0;
    virtual void moveToPosition(int angle) = 0;
    virtual void off() = 0;
};

#endif
