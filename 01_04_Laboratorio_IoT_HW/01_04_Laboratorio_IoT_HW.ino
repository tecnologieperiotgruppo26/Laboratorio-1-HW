/**
 *    IOT laboratorio HW-1
 *    esercizio 4
 *    todo: sketch in grado di controllare e regolare la velocità  
 *          di rotazione di un motore tramite pwm, step controllati
 *          da input tramite monitor seriale
 */

const int fanPin = 10;
/*valore current speed da 0 a 255*/
float currentSpeed = 0;
/*ad ogni pressione di un tasto +/- faccio cambiare la velocità di +/-10%*/
float cambioDieci = 255/10;

void setup() {
  // put your setup code here, to run once:
  pinMode(fanPin, OUTPUT);
  analogWrite(fanPin, currentSpeed);
  while (!Serial);
  /* se non apri il monitor seriale, il programma non parte */
  Serial.println("Lab 1.4 Starting");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    int inByte = Serial.read();

    if (inByte == '+'){
      currentSpeed = currentSpeed + cambioDieci;
      if (currentSpeed >= 255){
        currentSpeed = 255;
        analogWrite(fanPin, currentSpeed);
        Serial.println("Velocità massima già raggiunta! v = " + String(currentSpeed));
        Serial.flush();
      }
        analogWrite(fanPin, currentSpeed);
        Serial.println("Aumento la velocità, V = " + String(currentSpeed));
        Serial.flush();
      }
    else if (inByte == '-'){
      currentSpeed = currentSpeed - cambioDieci;
      if (currentSpeed <= 0){
        currentSpeed = 0;
        analogWrite(fanPin, currentSpeed);
        Serial.println("Velocità minima già raggiunta! v = " + String(currentSpeed));
        Serial.flush();
      }
        analogWrite(fanPin, currentSpeed);
        Serial.println("Diminuisco la velocità, V= " + String(currentSpeed));
        Serial.flush();
    } 
    else {
      Serial.println("Comando non riconosciuto. Riprova!");
      Serial.flush();    
    }
  }
}
