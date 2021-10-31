#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <Arduino.h>

class Button
{
private:
    byte _pin;
    bool _flagPressed = false;
    bool _flagReleased = false;
    bool _flagClicked = false;
    unsigned long _upTime = 0;
    unsigned long _delay;

    void updateState();
public:
    Button(byte pin, unsigned long delay = 200);
    byte getPin();
    bool isPressed();
    bool wasClicked();
    bool wasReleased();
};

#endif // BUTTON_H_INCLUDED
