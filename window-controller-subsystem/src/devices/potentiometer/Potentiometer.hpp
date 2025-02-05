#ifndef __POTENTIOMETER__
#define __POTENTIOMETER__

class Potentiometer {
   public:
    int getValue();
    Potentiometer(int pin);

   private:
    int pin;
};

#endif