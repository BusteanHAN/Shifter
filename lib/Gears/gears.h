void neutral(Joystick_ *Joystick) {
    for (int i = 0; i < 8; i++)
        Joystick->setButton(i,0);
    // Serial.println("neutral");
}

void first(Joystick_ *Joystick) {
    Joystick->setButton(0,1);
    // Serial.println("first");
}

void second(Joystick_ *Joystick) {
    Joystick->setButton(1,1);
    // Serial.println("second");
}

void third(Joystick_ *Joystick) {
    Joystick->setButton(2,1);
    // Serial.println("third");
}

void fourth(Joystick_ *Joystick) {
    Joystick->setButton(3,1);
    // Serial.println("fourth");
}

void fifth(Joystick_ *Joystick) {
    Joystick->setButton(4,1);
    // Serial.println("fifth");
}

void sixth(Joystick_ *Joystick) {
    Joystick->setButton(5,1);
    // Serial.println("sixth");
}

void seventh(Joystick_ *Joystick) {
    Joystick->setButton(6,1);
    // Serial.println("seventh");
}

void reverse(Joystick_ *Joystick) {
    Joystick->setButton(7,1);
    // Serial.println("Reverse");
}