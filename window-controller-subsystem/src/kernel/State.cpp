#include "kernel/State.hpp"

State::State() { setValue(State::Value::AUTOMATIC); }

State::Value State::getValue() { return this->value; }

void State::setValue(State::Value newValue) { this->value = newValue; }

String State::toString() {
    if (this->value == State::Value::AUTOMATIC) return "AUTOMATIC";
    if (this->value == State::Value::MANUAL) return "MANUAL";
}

void State::switchValue() {
    if (this->value == State::Value::AUTOMATIC) {
        this->value = State::Value::MANUAL;
    } else if (this->value == State::Value::MANUAL) {
        this->value = State::Value::AUTOMATIC;
    }
}