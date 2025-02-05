#ifndef __PATTERN__
#define __PATTERN__

#include <Arduino.h>

class Pattern {
   public:
    static boolean matchTemp(const String& msg);
    static boolean matchAngle(const String& msg);
    static boolean matchState(const String& msg);
    static float getTemp(const String& msg);
    static int getAngle(const String& msg);
    static String getState(const String& msg);
};

#endif