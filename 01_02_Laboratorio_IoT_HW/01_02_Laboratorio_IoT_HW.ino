/**
 * *  IOT laboratorio HW-1
 *  esercizio 2
 *  COMUNICAZIONE TRAMITE PORTA SERIALE
 *  todo: pilotare due led per farli lampeggiare
 *        con periodi variabili in base all'input
 *        da monitor seriale, baud=9600
 *        
 *        pins definiti tramite costanti
 *        usare i pin d11 e d12
 *        
 *  inserire serialmente R per verificare lo stato
 *  del led Rosso, e V per quello verde.
 */
#include <TimerOne.h>
const int ledRosso = 11;
const int ledVerde = 12;

const float rossoHalfPeriod = 1.5;
const float verdeHalfPeriod = 3.5;

int statoLedRosso = LOW;
volatile int statoLedVerde = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  /* se non apri il monitor seriale, il programma non parte */
  Serial.println("Lab 1.2 Starting");
  pinMode(ledRosso, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Timer1.initialize(verdeHalfPeriod * 1e06);
  Timer1.attachInterrupt(blinkGreen);
  digitalWrite(ledRosso, statoLedRosso);
  digitalWrite(ledVerde, statoLedVerde);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  /*controllo se trovo qualcosa nel buffer di inserimento*/
  if (Serial.available() >0) {
    SerialPrintStatus();
  }
  
  delay(rossoHalfPeriod * 1e03);
  statoLedRosso = !statoLedRosso;
  digitalWrite(ledRosso, statoLedRosso);
}


void SerialPrintStatus(){
  if (Serial.available() >0) {
    int inByte = Serial.read();

    if (inByte == 'R'){
      Serial.println("Stato ledRosso :" + statoLedRosso);
      Serial.flush();
    }
    else if (inByte == 'V'){
      Serial.println("Stato ledVerde :" + statoLedVerde);
      Serial.flush();
    }
    else {
      Serial.println("Comando non riconosciuto. Riprova!");
      Serial.flush();    
    }
    
  }
}

/*Funzione blinkGreen chiamata dalla funzione interrupt ISR*/
void blinkGreen() {
  statoLedVerde = !statoLedVerde;
  digitalWrite(ledVerde, statoLedVerde);
}
