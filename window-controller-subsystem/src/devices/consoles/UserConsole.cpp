
#include "devices/consoles/UserConsole.hpp"
#include <Arduino.h>
#include <avr/sleep.h>
#include "config.hpp"

UserConsole::UserConsole() { lcd = new LiquidCrystal_I2C(0x27, 20, 4); }

void UserConsole::init() {
    lcd->init();
    lcd->backlight();
    lcd->noDisplay();
}

void UserConsole::turnOnDisplay() {
    lcd->display();
    lcd->clear();
}

void UserConsole::turnOffDisplay() { lcd->noDisplay(); }

void UserConsole::display(String s, int row_number) {
    lcd->setCursor(0, row_number);
    lcd->print(s);
}

void UserConsole::clearScreen() { lcd->clear(); }

void UserConsole::prepareToSleep() {
    lcd->noDisplay();
    lcd->noBacklight();
}

void UserConsole::resumeFromSleeping() {
    lcd->display();
    lcd->backlight();
}

void UserConsole::test() {
    delay(1000);

    lcd->display();
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print(F("Testing"));
    delay(1000);
    lcd->clear();
}
