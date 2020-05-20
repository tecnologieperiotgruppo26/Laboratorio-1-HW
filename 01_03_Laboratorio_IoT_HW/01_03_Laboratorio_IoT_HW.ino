/**
 *    IOT laboratorio HW-1
 *    esercizio 3
 *    todo:  sketch per numerare le persone che passano davanti il sensore
 *           di movimento PIR. il PIR va collegato ad un pin con interrupt 
 *           (useremo il D7), e reagire ad ogni fronte di salita e discesa
 *           (CHANGE). la reazione consiste nell'accendere il led ogni 
 *           fronte alto del sensore.
 *           registrarsi anche il numero di persone che passano 
 *           ogni 30 secondi 
 * 
 */

const int ledPin = 12;
const int pirPin = 7;

volatile int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(pirPin), checkPresence, CHANGE);
  Serial.begin(9600);
  while (!Serial);
  /* se non apri il monitor seriale, il programma non parte */
  Serial.println("Lab 1.3 Starting");
  Serial.println("Aspettiamo ulteriori 30 secondi per il setup del sensore PIR");
  delay(30000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Sono passate " + String(count) + " persone!");
  Serial.flush();
  delay(30000);
  //ripeto la stampa ogni 30 secondi
}

void checkPresence(){
  if (digitalRead(pirPin)==HIGH){
    digitalWrite(ledPin, HIGH);
    count += 1; 
  }
  else if(digitalRead(pirPin)==LOW){
    digitalWrite(ledPin, LOW);
  }
}
