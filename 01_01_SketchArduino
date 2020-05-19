/**
 *  IOT laboratorio HW-1
 *  esercizio 1
 *  PILOTAGGIO DEI LED 
 *  todo: pilotare due led per farli lampeggiare
 *        con periodi indipendenti fra loro
 *        pins definiti tramite costanti
 *        per pilotare il primo led si usa la delay()
 *        per pilotare il secondo invece una ISR 
 *          collegata al timer1 della board
 *        usare i pin d11 e d12
 */

#include <TimerOne.h>

const int ledRosso = 11;
const int ledVerde = 12;
const int delayRosso = 3; 

const float rossoHalfPeriod = 1.5;
const float verdeHalfPeriod = 3.5;

int statoLedRosso = LOW;
int statoLedVerde = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledRosso, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Timer1.initialize(verdeHalfPeriod * 1e06);
  Timer1.attachInterrupt(blinkGreen);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(rossoHalfPeriod * 1e03);
  statoLedRosso = !statoLedRosso;
  digitalWrite(ledRosso, statoLedRosso);
}


/*Funzione blinkGreen chiamata dalla funzione interrupt ISR*/
void blinkGreen() {
  statoLedVerde = !statoLedVerde;
  digitalWrite(ledVerde, statoLedVerde);
}
