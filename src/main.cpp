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
  case 0 ... 660:
    if (!inGear)
    {
      switch (A2Reading)
      {
      case 0 ... 470:
        second(&Joystick);
        inGear = true;
        break;
      case 490 ... 520:
        fourth(&Joystick);
        inGear = true;
        break;
      case 660 ... 730:
        sixth(&Joystick);
        inGear = true;
        break;
      case 770 ... 1023:
        reverse(&Joystick);
        inGear = true;
        break;
      default:
        break;
      }
    }
    break;
  case 661 ... 779:
    neutral(&Joystick);
    inGear = false;
    break;
  case 780 ... 1023:
    if (!inGear)
    {
      switch (A2Reading)
      {
      case 0 ... 460:
        first(&Joystick);
        inGear = true;
        break;
      case 465 ... 500:
        third(&Joystick);
        inGear = true;
        break;
      case 610 ... 670:
        fifth(&Joystick);
        inGear = true;
        break;
      case 700 ... 1023:
        seventh(&Joystick);
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