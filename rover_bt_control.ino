#include<SoftwareSerial.h>
SoftwareSerial mySerial(0, 1);

int BluetoothData;
int en1=5;
int a1=6;
int a2=7;

int en2=8;
int b1=9;
int b2=10;
int data=0;
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(en1, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);

  pinMode(en2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);

  
}

void loop()
{
 

  
  //digitalWrite(en1, HIGH);
    //digitalWrite(a1, HIGH);
  //digitalWrite(a2, LOW);

      //digitalWrite(en2, HIGH);
      //digitalWrite(b1, HIGH);
      //digitalWrite(b2, LOW);

  if (Serial.available() > 0)
  {
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");
    if (data == '1')  //forward
    {
      digitalWrite(en1, HIGH);
      digitalWrite(a1, HIGH);
      digitalWrite(a2, LOW);

      digitalWrite(en2, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(b2, LOW);
    }
    else if (data == '2') //reverse
    {
      digitalWrite(en1, HIGH);
      digitalWrite(a1, LOW);
      digitalWrite(a2, HIGH);

      digitalWrite(en2, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(b2, HIGH);
    }
    else if (data == '3') //left|right
    {
      digitalWrite(en1, HIGH);
      digitalWrite(a1, HIGH);
      digitalWrite(a2, LOW);

      digitalWrite(en2, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(b2, LOW);
    }

    else if (data == '4') //left|right
    {
      digitalWrite(en1, HIGH);
      digitalWrite(a1, LOW);
      digitalWrite(a2, LOW);

      digitalWrite(en2, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(b2, LOW);
    }

    else if (data == '0') //stop
    {
      digitalWrite(en1, HIGH);
      digitalWrite(a1, LOW);
      digitalWrite(a2, LOW);

      digitalWrite(en2, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(b2, LOW);
    }
  }
}

