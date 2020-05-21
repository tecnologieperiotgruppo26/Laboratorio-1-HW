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
  //calcolo il valore di R, successivamente
  //uso il datasheet per ricavare le formule di conversione e 
  //calcolo T, per poi convertire in Celsius
  float R = ((1023.0/vDigit)-1.0);
  R = R0*R;
  float loga = log(R/R0)/beta;
  float TK = 1.0/((loga)+(1.0/298.15));
  float TC = TK-273.15;
  

  lcd.setCursor(12, 0);
  lcd.print(String(TC));
  
  delay(sleepTime);
  
  
}
