// ESP32 Led Blink Tutorial

#define led 25

void setup()
{
    Serial.begin(115200);
    Serial.println("Led Blink");
    delay(1000);
    pinMode(led, OUTPUT);
}

void loop()
{
    digitalWrite(led, HIGH);
    delay(250);
    Serial.println("Led state: open");

    digitalWrite(led, LOW);
    delay(250);
    Serial.println("Led state: close");
}
