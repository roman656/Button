#include <Button.h>

void Button::updateState()
{
    bool buttonState = !digitalRead(_pin);

    if (millis() >= _upTime)
    {
        if (buttonState && !_flagPressed)
        {
            _upTime = millis() + _delay;
            _flagPressed = true;
            _flagReleased = false;
            _flagClicked = true;
        }
        else if (!buttonState && _flagPressed)
        {
            _upTime = millis() + _delay;
            _flagPressed = false;
            _flagReleased = true;
            _flagClicked = false;
        }
    }
}

Button::Button(byte pin, unsigned long delay)
{
    _pin = pin;
    _delay = delay;
}

byte Button::getPin()
{
    return _pin;
}

bool Button::isPressed()
{
    updateState();
    return _flagPressed;
}

bool Button::wasClicked()
{
    bool result;

    updateState();
    result = _flagClicked;
    _flagClicked = false;

    return result;
}

bool Button::wasReleased()
{
    bool result;

    updateState();
    result = _flagReleased;
    _flagReleased = false;

    return result;
}
