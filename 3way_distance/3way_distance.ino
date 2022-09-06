#include "LiquidCrystal_I2C.h"

#define TRIG1 5
#define ECHO1 4
#define TRIG2 9
#define ECHO2 8
#define TRIG3 13
#define ECHO3 12

LiquidCrystal_I2C lcd(0x27, 20, 40);

double dist1;
double dist2;
double dist3;

String d1;
String d2;
String d3;

void setup()
{
    lcd.begin();
    lcd.backlight();

    pinMode(TRIG1, OUTPUT);
    pinMode(ECHO1, INPUT);
    pinMode(TRIG2, OUTPUT);
    pinMode(ECHO2, INPUT);
    pinMode(TRIG3, OUTPUT);
    pinMode(ECHO3, INPUT);
}

void loop()
{
    digitalWrite(TRIG1, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG1, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG1, LOW);

    dist1 = pulseIn(ECHO1, HIGH) * 17.0 / 1000.0;
    d1 = String(dist1, 1);

    digitalWrite(TRIG2, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG2, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG2, LOW);

    dist2 = pulseIn(ECHO2, HIGH) * 17.0 / 1000.0;
    d2 = String(dist2, 1);

    digitalWrite(TRIG3, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG3, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG3, LOW);

    dist3 = pulseIn(ECHO3, HIGH) * 17.0 / 1000.0;
    d3 = String(dist3, 1);

    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print(d1);
    lcd.print("cm");
    lcd.setCursor(0, 3);
    lcd.print(d2);
    lcd.print("cm");
    lcd.setCursor(18-d3.length(), 3);
    lcd.print(d3);
    lcd.print("cm");
    lcd.display();

    delay(3000);
}
