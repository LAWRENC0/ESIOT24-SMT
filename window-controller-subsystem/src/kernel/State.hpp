#ifndef __STATE__
#define __STATE__

#include <Arduino.h>

class State {
   public:
    enum class Value { AUTOMATIC, MANUAL };
    State();

    Value getValue();
    void setValue(Value newValue);
    void switchValue();
    String toString();

   private:
    Value value;
};

#endif