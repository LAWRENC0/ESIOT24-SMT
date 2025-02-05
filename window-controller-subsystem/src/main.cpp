#include <Arduino.h>
#include <EnableInterrupt.h>
#include "config.hpp"
#include "kernel/State.hpp"
#include "kernel/MsgService.hpp"
#include "devices/motors/ServoMotorImpl.hpp"
#include "devices/potentiometer/Potentiometer.hpp"
#include "devices/consoles/UserConsole.hpp"
#include "devices/buttons/ButtonImpl.hpp"

State* state;
ServoMotorImpl* servo;
int door_angle;
float temp;
Potentiometer* potentiometer;
UserConsole* lcd;
ButtonImpl* button;

void switchState() { state->switchValue(); }

void setup() {
    Serial.begin(BAUD_RATE);
    MsgService.init(BAUD_RATE);
    state = new State();
    servo = new ServoMotorImpl(PIN_SERVO);
    potentiometer = new Potentiometer(PIN_POT);
    lcd = new UserConsole();
    button = new ButtonImpl(PIN_BUTTON);
    enableInterrupt(PIN_BUTTON, switchState, RISING);

    door_angle = 0;
    temp = 0;
}

void loop() {
    // SEND STATE THROUGH SERIAL LINE
    // Serial.write(state);
    MsgService.sendMsg(state->toString());
    if (state->getValue() == State::Value::AUTOMATIC) {
        // READ DOOR ANGLE / TEMP THROUGH SERIAL LINE
        String content = "";
        if (MsgService.isMsgAvailable()) {
            Msg* msg = MsgService.receiveMsg();
            if (msg != NULL) {
                content = msg->getContent();
                delete msg;
            }
        }
        if (content != "") {
            // PARSE THE STRING
            // temp = stof(content);
        }
    } else if (state->getValue() == State::Value::MANUAL) {
        // READ DOOR ANGLE / TEMP THROUGH POTENTIOMETER
        door_angle = map(potentiometer->getValue(), 0, 1023, 0, 180);
    }
    // MOVE DOOR
    servo->moveToPosition(door_angle);
    // DISPLAY ON LCD
}