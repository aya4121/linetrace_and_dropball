int sensorPinR = A0;
int sensorPinL = A1;
int sensorValueL = 0;
int sensorValueR = 0;
int ledPin = 13; 

const int AIA = 5;
const int AIB = 3;
const int BIA = 9;
const int BIB = 6;
const int speed = 170;

void setup() {
 Serial.begin(9600);
 pinMode(ledPin, OUTPUT);
 pinMode (AIA, OUTPUT);

 pinMode (AIB, OUTPUT);
 pinMode (BIA, OUTPUT);
 pinMode (BIB, OUTPUT);
 pinMode(2,INPUT_PULLUP);
 pinMode(4,INPUT_PULLUP);

 while (digitalRead(4) == HIGH){}
}

void loop() {
 sensorValueL = analogRead(sensorPinL);
 sensorValueR = analogRead(sensorPinR);

 Serial.println(sensorValueL);
 Serial.println(sensorValueR);
 int In1 = digitalRead(7);
 int InT = digitalRead(4);
 int In2 = digitalRead(2);

 delay(10);
 if (sensorValueL < 40) {
   if (sensorValueR < 45) {
   digitalWrite(ledPin,HIGH);
   forward();}else{
     right();
   }

 }else{
   if (sensorValueR <45) {
   digitalWrite(ledPin,LOW);
   left();}else{
     forward();
     delay(300);
     rightS();
     delay(300);
     leftS();
     delay(300);
     rightS();
     delay(300);
     leftS();
     delay(300);
     rightS();
     delay(300);
     leftS();
     delay(300);
     rightS();
     delay(300);
     leftS();
     delay(300);
     rightS();
     delay(300);
   }
 } 

}


void forward() {
 analogWrite (AIA,speed +15);
 analogWrite (AIB,0);
 analogWrite (BIA,speed );
 analogWrite (BIB,0);

}

void stopMotor(){
 analogWrite (AIA,0);
 analogWrite (AIB,0);
 analogWrite (BIA,0);
 analogWrite (BIB,0);

}

void right() {
 analogWrite (AIB,0);
 analogWrite (AIA,speed );
 analogWrite (BIA,0);
 analogWrite (BIB,speed );

}

void left() {
 analogWrite (AIA,0);
 analogWrite (AIB,speed );
 analogWrite (BIA,speed );
 analogWrite (BIB,0);
}

void rightS(){
  analogWrite (AIB,0);
 analogWrite (AIA,225);
 analogWrite (BIA,0);
 analogWrite (BIB,225);
}

void leftS() {
 analogWrite (AIA,0);
 analogWrite (AIB,225);
 analogWrite (BIA,225);
 analogWrite (BIB,0);
}
