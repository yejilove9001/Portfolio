#include<Servo.h>
#include<LiquidCrystal_I2C.h>
Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16,2);
int carNumber =0;
int pos = 0;
int servoPin = 6;

#define TRIG 9
#define ECHO 8

int RED = 12;
int GREEN = 11;
int BLUE = 10;
bool barrierRaised = false;

void setup() {
  //초음파
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  //서보모터
  pinMode(servoPin, OUTPUT);
  myservo.attach(6);
  myservo.write(0);
 
  //조도센서
  pinMode(A0, INPUT); //들어오는 차 감지
  pinMode(A1, INPUT); //나가는 차 감지

  //3색 led
  pinMode(RED, OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE, OUTPUT);
}
void loop() {
  //초음파 센서
  long duration, distance;

  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

  duration = pulseIn(ECHO,HIGH);
  distance = duration*17/1000;

  Serial.println(duration);
  Serial.print("\nDistance:");
  Serial.print(distance);
  Serial.println("Cm");

  // 차단봉 동작 코드
if (carNumber >= 5) {
    if (barrierRaised) {
      myservo.write(0);
      delay(1000);
      barrierRaised = false;
    }
  }
  else if (!barrierRaised && distance <= 10) {
    for (pos = 0; pos <= 90; pos += 1) {
      myservo.write(pos);
      delay(10);
    }
    delay(1000);
    for (pos = 90; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(10);
    }
    barrierRaised = false;
  }
//조도센서
 
  int comein = analogRead(A0);
  Serial.println("Come in : " + String(comein));
  delay(100);
  int goout = analogRead(A1);
  Serial.println("Go out : " + String(goout));
  delay(1000);

  if(comein < 120){
    carNumber = carNumber + 1;
  }
  if(goout < 120){
    carNumber = carNumber - 1;
  }

 
}

  
