#include "LiquidCrystal_I2C.h"

#define TRIG_LEFT 5
#define ECHO_LEFT 4
#define TRIG_MIDDLE 9
#define ECHO_MIDDLE 8
#define TRIG_RIGHT 13
#define ECHO_RIGHT 12

LiquidCrystal_I2C lcd(0x27, 20, 40);

double dist_left;
double dist_middle;
double dist_right;

String string_left;
String string_middle;
String string_right;

void setup()
{
    lcd.begin();
    lcd.backlight();

    pinMode(TRIG_LEFT, OUTPUT);
    pinMode(ECHO_LEFT, INPUT);
    pinMode(TRIG_MIDDLE, OUTPUT);
    pinMode(ECHO_MIDDLE, INPUT);
    pinMode(TRIG_RIGHT, OUTPUT);
    pinMode(ECHO_RIGHT, INPUT);
}

void loop()
{
    digitalWrite(TRIG_MIDDLE, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_MIDDLE, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_MIDDLE, LOW);

    dist_middle = pulseIn(ECHO_MIDDLE, HIGH) * 17.0 / 1000.0;
    string_middle = String(dist_middle, 1);

    digitalWrite(TRIG_LEFT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_LEFT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_LEFT, LOW);

    dist_left = pulseIn(ECHO_LEFT, HIGH) * 17.0 / 1000.0;
    string_left = String(dist_left, 1);

    digitalWrite(TRIG_RIGHT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_RIGHT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_RIGHT, LOW);

    dist_right = pulseIn(ECHO_RIGHT, HIGH) * 17.0 / 1000.0;
    string_right = String(dist_right, 1);

    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print(string_middle);
    lcd.print("cm");
    lcd.setCursor(0, 3);
    lcd.print(string_left);
    lcd.print("cm");
    lcd.setCursor(18 - string_right.length(), 3);
    lcd.print(string_right);
    lcd.print("cm");
    lcd.display();

    delay(3000);
}
