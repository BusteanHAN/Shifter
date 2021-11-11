#include <Arduino.h>
#include "Joystick.h"
#include "gears.h"

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
                   JOYSTICK_TYPE_GAMEPAD, 8, 0,
                   false, false, false,                // X  Y  Z
                   false, false, false,                //Rx Ry Rz
                   false, false, false, false, false); //Rudder, Throttle, Accelerator, Brake, Steering

bool inGear = false;

void setup()
{
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(115200);
}

void loop()
{
  uint16_t A3Reading = analogRead(A3), A2Reading = analogRead(A2);
  Serial.print(A2Reading);\
  Serial.print(" ");
  Serial.println(A3Reading);
  switch (A3Reading)
  {
  case 0 ... 370:
    if (!inGear)
    {
      switch (A2Reading)
      {
      case 775 ... 1023:
        first(&Joystick);
        inGear = true;
        break;
      case 720 ... 774:
        third(&Joystick);
        inGear = true;
        break;
      case 590 ... 665:
        fifth(&Joystick);
        inGear = true;
        break;
      case 0 ... 580:
        seventh(&Joystick);
        inGear = true;
        break;
      default:
        break;
      }
    }
    break;
  case 371 ... 464:
    neutral(&Joystick);
    inGear = false;
    break;
  case 465 ... 1023:
    if (!inGear)
    {
      switch (A2Reading)
      {
      case 680 ... 1023:
        second(&Joystick);
        inGear = true;
        break;
      case 570 ... 630:
        fourth(&Joystick);
        inGear = true;
        break;
      case 537 ... 565:
        sixth(&Joystick);
        inGear = true;
        break;
      case 0 ... 536:
        reverse(&Joystick);
        inGear = true;
        break;
      }
    }
    break;
  default:
    neutral(&Joystick);
    break;
  }

  Joystick.sendState();
}