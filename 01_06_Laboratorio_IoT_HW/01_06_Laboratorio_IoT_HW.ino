/**
 *    IOT laboratorio HW-1
 *    esercizio 6
 *    todo: sketch in grado di leggere valori analogici
 *          di temperatura e stamparli display LCD.
 *          sensore temperatura su A1 e display su 
 *          d2/d3 inizializzati di defaul sulla libreria
 */

#include <LiquidCrystal_PCF8574.h>
#include <math.h>

const int tempPin = A1;
const long int R0 = 100000;
const int beta = 4275;
const int sleepTime = 10000;

//valore dato dalle slide ma da provare in base a come 
//sono collegati i cavi
LiquidCrystal_PCF8574 lcd(0x27);

void setup() {
  // put your setup code here, to run once:
  pinMode(tempPin, INPUT);
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.home();
  lcd.clear();
  lcd.print("Temperature:");
}

void loop() {
  // put your main code here, to run repeatedly:
  int vDigit = analogRead(tempPin);
  // ora trasformo l'entrata da digital a vsignal
  float vSig = vDigit*5/1024;
  //calcolo il valore di R, nelle formule va moltiplicato per r0, 
  //successivamente nel calcolo di T va diviso quindi lo semplifico 
  //direttamente, inoltre il valore di T esce direttamente in Celsius
  float R = (5/vSig-1);
  float T = (1/((log(R)/beta)+(1/298)))-273;

  lcd.setCursor(0, 13);
  lcd.print(T, 2);
  delay(sleepTime);
  
  
}
