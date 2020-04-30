#include <SoftwareSerial.h> // Use have to install SoftwareSerial library first https://www.arduino.cc/en/Tutorial/SoftwareSerialExample
static const int RXPin = 8, TXPin = 9;
SoftwareSerial RS485_Serial(RXPin, TXPin); // Use SoftwareSerial

const byte dirPin = 4; // For control direction (Logic High for send data , Logic Low for receive data)

void setup() {
  Serial.begin(9600);
  RS485_Serial.begin(9600);
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin,LOW);
}

unsigned long previousMillis = 0;
const long interval = 2000;

void loop() {
  if (RS485_Serial.available()) {
    Serial.write(RS485_Serial.read());
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // SEND //
    digitalWrite(dirPin,HIGH);
    delay(10);
    RS485_Serial.write(" Data");
    RS485_Serial.write(0x0a);

    // TO Recieved //
    delay(10);
    digitalWrite(dirPin,LOW);
  }
}
