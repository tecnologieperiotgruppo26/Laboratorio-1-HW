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
  // ora trasformo l'entrata da digital a vsignal
  float vSig = vDigit*5/1024;
  //calcolo il valore di R, nelle formule va moltiplicato per r0, 
  //successivamente nel calcolo di T va diviso quindi lo semplifico 
  //direttamente, inoltre il valore di T esce direttamente in Celsius
  float R = (5/vSig-1);
  float T = (1/((log(R)/beta)+(1/298)))-273;
  Serial.print("La temperatura della stanza è di ");
  Serial.print(T);
  Serial.println("gradi celsius");
  delay(sleepTime);
  
  
}
