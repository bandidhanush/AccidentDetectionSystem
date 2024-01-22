/*
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
*/
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int emergency = 7;
int vib = A0;
int Buzzer = 6;

int count = 0, q = 0;

void setup() {
  Serial.begin(9600);
  pinMode(emergency, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(vib, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  int value = analogRead(vib);
  Serial.println(value);

  if (value > 288) {
    digitalWrite(Buzzer, HIGH);
    delay(5000);  // Buzzer rings for 5 seconds

    sendCallAndLocation("Enter your phone number without country code", "Emergency! Need help at Loc: DSU");
    Serial.println("CALL AND MESSAGE SENT EMERGENCY");
    lcd.print("Accident Alert!!!");
  } else {
    digitalWrite(Buzzer, LOW);
  }

  // --------------------------Emergency Button------------------------
  if (digitalRead(emergency) == HIGH) {
    if (q == 0) {
      sendCallAndLocation("Enter your phone number without country code", "Emergency Alert!");
      Serial.println("CALL AND MESSAGE SENT EMERGENCY");
      lcd.clear();
      lcd.print("Emergency Alert!!!");
      q = 1;
      delay(5000);
      disp();
    }
  } else {
    q = 0;
  }
}

void sendCallAndLocation(String number, String message) {
  Serial.println("ATD" + number + ";");
  delay(2000);
  sendmessage(number, message);
}

void sendmessage(String number, String message) {
  Serial.println("AT+CMGF=1");
  delay(200);
  Serial.println("AT+CMGS=\"" + number + "\"");
  delay(200);
  Serial.println(message);
  delay(200);
  Serial.println((char)26);
  delay(200);
}

void disp() {
  lcd.clear();
  lcd.print("ACCIDENT&ALERTSYS");
}
