// LDR -- GPIO34 LED -- GPIO5


const int LDR_PIN = 34;
const int LED_PIN = 5;
const int THRESHOLD = 500; // Light threshold value (between 0-4095 Dec)

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int ldrValue = analogRead(LDR_PIN);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue < THRESHOLD)
  { // If the LDR value is below the threshold value
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }

  delay(500);
}
