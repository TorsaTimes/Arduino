// #include "DHT.h"
// #include "LiquidCrystal_I2C.h"
// LiquidCrystal_I2C lcd(0x27,20,4);

// //====================================== Temperatureinstellungen
// #define solltemp 26
// #define stufe1 solltemp+1
// #define stufe2 solltemp+2
// #define stufe3 solltemp+3
// #define stufe4 solltemp+4
// #define stufe5 solltemp+5
// //==============================================================

// #define DHTPIN 2 
// #define FanPin 9
// #define DHTTYPE DHT11
// float temp;
// String status;

// DHT dht(DHTPIN, DHTTYPE);

// void setup() {
// lcd.init();
// lcd.backlight();
// dht.begin();
// TCCR1B = TCCR1B & B11111000 | B00000001;
// pinMode(FanPin,OUTPUT);
// }
// void loop() {
// delay(2000);
// float temp = dht.readTemperature();
// if (temp <= solltemp) { digitalWrite(FanPin,LOW); status = "AUS      "; }else
// if (temp >= stufe5) { digitalWrite(FanPin,HIGH); status = "Stufe-MAX"; }else
// if (temp >= stufe4) { analogWrite(FanPin,190); status = "Stufe-4  "; }else
// if (temp >= stufe3) { analogWrite(FanPin,150); status = "Stufe-3  "; }else
// if (temp >= stufe2) { analogWrite(FanPin,90); status = "Stufe-2  "; }else
// if (temp >= stufe1) { analogWrite(FanPin,40); status = "Stufe-1  "; }else
// if (temp >= solltemp) { analogWrite(FanPin,20); status = "Stufe-LOW"; }
// lcd.setCursor(0,0);
// lcd.print("L\365ftersteuerung");
// lcd.setCursor(0,1);
// lcd.print("Aktuell: ");
// lcd.print(temp);
// lcd.print("\337C");
// lcd.setCursor(0,2);
// lcd.print("Soll: ");
// lcd.print(solltemp);
// lcd.print("\337C");
// lcd.setCursor(0,3);
// lcd.print("Status: ");
// lcd.print(status);
// delay(1000);
// }



#include "DHT.h"
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27,20,4);

//====================================== Temperatureinstellungen
#define solltemp 30
#define stufe1 40
#define stufe2 45
#define stufe3 47.5
#define stufe4 50
#define stufe5 52.5
#define stufe6 55
#define stufe7 60
#define stufe8 65
#define stufe9 70
//==============================================================

#define DHTPIN 2 
#define FanPin 9
#define DHTTYPE DHT11
float temp;
String status;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
lcd.init();
lcd.backlight();
dht.begin();
TCCR1B = TCCR1B & B11111000 | B00000001;
pinMode(FanPin,OUTPUT);
}
void loop() {
delay(2000);
float temp = dht.readTemperature();
if (temp <= solltemp) { digitalWrite(FanPin,LOW); status = "AUS      "; }else
if (temp >= stufe9) { digitalWrite(FanPin,180); status = "Stufe-MAX"; }else
if (temp >= stufe8) { digitalWrite(FanPin,150); status = "Stufe-8"; }else
if (temp >= stufe7) { digitalWrite(FanPin,130); status = "Stufe-7"; }else
if (temp >= stufe6) { digitalWrite(FanPin,110); status = "Stufe-6"; }else
if (temp >= stufe5) { digitalWrite(FanPin,90); status = "Stufe-5"; }else
if (temp >= stufe4) { analogWrite(FanPin,70); status = "Stufe-4  "; }else
if (temp >= stufe3) { analogWrite(FanPin,50); status = "Stufe-3  "; }else
if (temp >= stufe2) { analogWrite(FanPin,40); status = "Stufe-2  "; }else
if (temp >= stufe1) { analogWrite(FanPin,30); status = "Stufe-1  "; }else
if (temp >= solltemp) { analogWrite(FanPin,20); status = "Stufe-LOW"; }
lcd.setCursor(0,0);
lcd.print("L\365ftersteuerung");
lcd.setCursor(0,1);
lcd.print("Aktuell: ");
lcd.print(temp);
lcd.print("\337C");
lcd.setCursor(0,2);
lcd.print("Soll: ");
lcd.print(solltemp);
lcd.print("\337C");
lcd.setCursor(0,3);
lcd.print("Status: ");
lcd.print(status);
delay(1000);
}
