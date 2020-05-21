
/**
 *    IOT laboratorio HW-1
 *    esercizio 5
 *    todo: sketch in grado di leggere valori analogici
 *          di temperatura e stamparli su monitor seriale
 *          il sensore va collegato in un pin analogico 
 *          e letto ogni 10 secondi
 */

#include <math.h>

const int tempPin = A1;
const long int R0 = 100000;
const int beta = 4275;
const int sleepTime = 10000;


void setup() {
  // put your setup code here, to run once:
  pinMode(tempPin, INPUT);
  while (!Serial);
  /* se non apri il monitor seriale, il programma non parte */
  Serial.println("Lab 1.5 Starting");
  
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
  Serial.print("La temperatura della stanza è di ");
  Serial.print(TC);
  Serial.println("gradi celsius   ");
  Serial.println(vDigit);
  delay(sleepTime);
  
  
}
