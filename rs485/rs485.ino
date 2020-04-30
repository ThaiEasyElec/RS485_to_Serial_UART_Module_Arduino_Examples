const byte dirPin = 4; // For control direction (Logic High for send data , Logic Low for receive data)

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600); // Use Serial2 (TX2 >> D16 , RX2 >> D17)
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin,LOW);
}

unsigned long previousMillis = 0;
const long interval = 2000;

void loop() {
  if (Serial2.available()) {
    Serial.write(Serial2.read());
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // SEND //
    digitalWrite(dirPin,HIGH);
    delay(10);
    Serial2.write(" Data");
    Serial2.write(0x0a);

    // TO Recieved //
    delay(10);
    digitalWrite(dirPin,LOW);
  }
}
