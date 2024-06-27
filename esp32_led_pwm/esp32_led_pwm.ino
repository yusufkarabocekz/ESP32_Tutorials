// ESP32 Led PWM Tutorial

const int led = 25;

int pwm = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("Led-PWM");

  pinMode(led, OUTPUT);
}

void loop()
{
  for (pwm = 0; pwm <= 255; pwm++)
  {
    analogWrite(led, pwm);
    delay(10);
    Serial.print("Led brightness value: ");
    Serial.println(pwm);
  }
  for (pwm = 255; pwm >= 0; pwm--)
  {
    analogWrite(led, pwm);
    delay(10);
    Serial.print("Led brightness value: ");
    Serial.println(pwm);
  }



}
