#include<Servo.h>
#include <dht11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <String.h>

int E1 = 10;
int M1 = 12;

int E2 = 11;
int M2 = 13;
String command;

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo spray;

#define DHT11PIN 14

dht11 DHT11;

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

}

void loop()
{
  String command;
  lcd.init();
  int soilmoisture = analogRead(A1);


  //*****************add different bluetooth functionalities below******
  if (Serial.available()) {

    command = (Serial.readString()); // send from bluetooth to serial
    Serial.println(command);
  }

  if (command == "led on")
  {
    digitalWrite(5, LOW);
  }
  else if (command == "led off")
  {
    digitalWrite(5, HIGH);
  }
  else if (command == "spray on")
  {
    spray.attach(9);
    spray.write(0);
    delay (500);
    spray.write(100);
    delay(500);
    spray.write(0);

  }
  else if (command == "water plant")
  {
    digitalWrite(M1, HIGH);
    digitalWrite(E1, HIGH);
    delay(1000);
    digitalWrite(E1, LOW);
    delay(1000);
  }
  else if (command == "open window")
  {
    digitalWrite(M2, HIGH);
    analogWrite(E2, 150);
    delay(1000);
    analogWrite(E2, 0);
    delay(3000);
    digitalWrite(M2, LOW);
    analogWrite(E2, 150);
    delay(1000);
    analogWrite(E2, 0);
    delay(1000);
  }

  //********************

  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture = ");
  lcd.setCursor(0, 1);
  lcd.print(soilmoisture);
  delay(1000);


  //*********************Soil Moisture****************


  if (soilmoisture > 500)
  {
    lcd.init();
    lcd.setCursor(0, 0);
    lcd.print("Watering plant");
    delay(1000);
    digitalWrite(M1, HIGH);
    digitalWrite(E1, HIGH);
    delay(1500);
    digitalWrite(E1, LOW);
    delay(1500);

  }

  //*********************Humidity****************

  lcd.init();
  int chk = DHT11.read(DHT11PIN);


  lcd.setCursor(0, 0);
  lcd.print("Humidity(%):");
  lcd.setCursor(13, 0);
  lcd.print((int)DHT11.humidity);


  //*********************Temperature****************


  lcd.setCursor(0, 1);
  lcd.print("Temp(C): ");
  lcd.setCursor(9, 1);
  lcd.print((int)DHT11.temperature);
  delay(2000);

  spray.attach(9);
  spray.write(0);

  //*********************Spray****************

  if (DHT11.humidity < 90)
  {
    lcd.init();
    lcd.setCursor(0, 0);
    lcd.print("Spraying Water");
    spray.attach(9);
    spray.write(100);
    delay(500);
    spray.write(0);
    delay(500);
  }
  else if (DHT11.humidity > 95)
  {
    lcd.init();
    lcd.setCursor(0, 0);
    lcd.print("Opening Window");
    
    digitalWrite(M2, HIGH);
    analogWrite(E2, 150);
    delay(1000);
    analogWrite(E2, 0);
    delay(5000); //window kept open for 10 seconds
    digitalWrite(M2, LOW);
    analogWrite(E2, 150);
    delay(1000);
    analogWrite(E2, 0);
    delay(1000);
  }


  //*********************LDR****************
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("Brightness: ");
  lcd.setCursor(12, 0);
  lcd.print(analogRead(2));
  delay(1500);

  if (analogRead(2) > 980)
  {
    digitalWrite(5, HIGH);
  }
  else if (analogRead(2) < 980)
  {
    digitalWrite(5, LOW);
  }

}
