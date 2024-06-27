// ESP32 adjusting the led brightness with a potentiometer

const int led = 25;
int pot = 26;
int pot_value = 0;
int brightness = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {

  pot_value = analogRead(pot);
  brightness = map(pot_value, 0, 4095, 0, 255); // ESP32 ADC Range is 0-4095
  Serial.print("Pot value: ");
  Serial.println(brightness);

  analogWrite(led, brightness);
  delay(10);

}
