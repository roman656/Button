#include <Button.h>

int ledPins[] = {7, 6, 5, 4, 3};
int ledPinsAmount = 5;
int counter = 0;
int anotherLedPin = 8;
Button buttons[] = {(11), (10), (9)};
int buttonsAmount = 3;

void setup()
{
    for (int i = 0; i < ledPinsAmount; i++)
    {
        pinMode(ledPins[i], OUTPUT);
    }

    pinMode(anotherLedPin, OUTPUT);

    for (int j = 0; j < buttonsAmount; j++)
    {
        pinMode(buttons[j].getPin(), INPUT_PULLUP);
    }
}

void loop()
{
    if (buttons[2].isPressed())
    {
        digitalWrite(anotherLedPin, HIGH);
    }
    else
    {
        digitalWrite(anotherLedPin, LOW);
    }

    if (buttons[0].wasClicked() && counter < ledPinsAmount)
    {
        counter++;
    }

    if (buttons[1].wasReleased() && counter > 0)
    {
        counter--;
    }

    for (int i = 0; i < ledPinsAmount; i++)
    {
        if (i + 1 <= counter)
        {
            digitalWrite(ledPins[i], HIGH);
        }
        else
        {
            digitalWrite(ledPins[i], LOW);
        }
    }
}
