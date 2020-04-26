#include <LiquidCrystal.h>

LiquidCrystal lcd(5,6,8,9,10,11);

int windowOFF = 3;
int windowON = 2;
int buzzer = 4;
int sensor = A0;
int sensorThresh = 400;


void setup()
{
  pinMode(windowOFF,OUTPUT);
  pinMode(windowON,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  
  
}

void loop()
{
  int analogValue = analogRead(sensor);
  Serial.print(analogValue);
  if(analogValue > sensorThresh){
    digitalWrite(windowOFF,HIGH);
    digitalWrite(windowON,LOW);
    tone(buzzer,1000,10000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("ALERT");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("GAS DETECTED");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("WINDOW IS NOW OPEN");
    delay(1000);
  }
  else{
    digitalWrite(windowON,HIGH);
    digitalWrite(windowOFF,LOW);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("safe");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("All Clear");
    delay(1000);
    
  }
}