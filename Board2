#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {

  Serial.begin(9600);
  pinMode(A0, INPUT); // 조도센서 1
  pinMode(A1, INPUT); // 조도센서 2
  pinMode(A2, INPUT); // 조도센서 3  

}

void loop() {
  // 조도센서: 차량 주차 여부 확인
  int N0 = analogRead(A0);
  Serial.print("N0: ");
  Serial.println(N0);
  delay(10);

  int N1 = analogRead(A1);
  Serial.print("N1: ");
  Serial.println(N1);
  delay(10);

 int N2 = analogRead(A2);
  Serial.print("N2: ");
  Serial.println(N2);

  // LCD 출력
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  // 1번째 조도센서
  lcd.print("N0:");
  if (N0 < 100) {
    lcd.print("X ");
  } else {
    lcd.print("O ");
  }
  
// 2번째 조도센서
  lcd.print("N1:");
  if (N1 < 100) {
    lcd.print("X ");
  } else {
    lcd.print("O ");
    }
  // 3번째 조도센서
  lcd.print("N2:");
  if (N2 < 100) {
    lcd.print("X ");
  } else {
    lcd.print("O ");
  }  
  lcd.setCursor(0, 1);
  lcd.print("Welcome!");
  }
