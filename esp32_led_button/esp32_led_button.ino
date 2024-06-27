// ESP32 Led-Button Tutorial

#define led 25
#define button 26

int buttonstate;

void setup()
{
    Serial.begin(115200);
    Serial.println("Led-Button");
    delay(1000);

    pinMode(button, INPUT);
    pinMode(led, OUTPUT);
}

void loop()
{
    buttonstate = digitalRead(button);

    if(buttonstate == 1)
    {
        digitalWrite(led, HIGH);
        Serial.println("Led state: open");
    }
    else
    {
        digitalWrite(led, LOW);
        Serial.println("Led state: close");
    }
   
}
