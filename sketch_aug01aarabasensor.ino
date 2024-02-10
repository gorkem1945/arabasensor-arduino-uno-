#include <NewPing.h>
#define trig_pin 8 
#define echo_pin 6
#define max_mes 200
NewPing sonar(trig_pin,echo_pin,max_mes);
int mesafe;

void setup() {
Serial.begin(9600);
pinMode(11,OUTPUT); //kırmızı
pinMode(12,OUTPUT); // sarı
pinMode(13,OUTPUT); // yeşil 
pinMode(3,OUTPUT);  // buzzer
}

void loop() {
  mesafe=sonar.ping_cm(); // sonar matematiksel fonksiyonu
  Serial.print(mesafe);
  Serial.print(" cm");
if(mesafe <=5){
  digitalWrite(11,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}
else if(mesafe > 5 and mesafe <= 10){
  digitalWrite(11,LOW);
  digitalWrite(3,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW); 
}
else{
  digitalWrite(11,LOW);
  digitalWrite(3,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
}
}
