
int waterSensorPin = A0; 

void setup() {

  Serial.begin(9600);
}

void loop() {


  int sensorValue = analogRead(waterSensorPin);

  if (sensorValue >500) {
    Serial.print("water! Caution! sensorValue: ");
    Serial.println(sensorValue);
  }
  else
  {
    Serial.println("no water");
  }

  
  delay(500);
}
