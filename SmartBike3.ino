
#define echoPin 10
#define triggerPin 9
#define ledPin 2
#define echoPinizq 6
#define triggerPinizq 5
#define ledPid2 3
#define ledPin3 4

 
int delaymili = 1000;
int maximumRangeCm = 400;
int minimumRangeCm = 0;
 
 
long duration, distanceCm,durationizq, distanceCmizq;
 
void setup() {
	Serial.begin(9600);
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
  
  pinMode(triggerPinizq, OUTPUT);
  pinMode(echoPinizq, INPUT);
	pinMode(ledPin, OUTPUT);
  pinMode(ledPin3, OUTPUT);

}
 
void loop() {
	initTrigger();
 
	duration = pulseIn(echoPin, HIGH);
	distanceCm = microsecCm(duration);

  Lecturader(distanceCm);
  
 
  initTriggerizq();
  durationizq = pulseIn(echoPinizq, HIGH);
  distanceCmizq = microsecCm(durationizq);

  Lecturaizq(distanceCmizq);

}










 
long microsecCm(long microsecond) {
	return microsecond / 58;
}

void initTrigger() {
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);
}

 
void initTriggerizq() {
  digitalWrite(triggerPinizq, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPinizq, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPinizq, LOW);
}

void Lecturaizq(long Lecturaizq){
    if(distanceCmizq<=200&&distanceCmizq>=100)
    {
      digitalWrite(ledPin, HIGH);
      delay(300);
      Serial.println("Te encuentras potencialmente en peligro!!!!\nLa distancia por la izquierda en centimetros respecto al objeto es :");
      Serial.println(distanceCmizq);
      Serial.println("\n\n");

      digitalWrite(ledPin, LOW);
      delay(300);
      digitalWrite(ledPin, HIGH);
      delay(delaymili); 
      
    }
   if(distanceCmizq<100&&distanceCmizq>=50)
    {
      digitalWrite(ledPin, HIGH);
      delay(150);
      Serial.println("Te encuentras en un peligro inminente!!!!\nLa distancia por la izquierda en centimetros respecto al objeto es :");
      Serial.println(distanceCmizq);
      digitalWrite(ledPin, LOW);
      delay(150);
      Serial.println("\n\n");

      delay(delaymili); 
      
    }
    if(distanceCmizq<50&&distanceCmizq>0)
    {
      digitalWrite(ledPin, HIGH);
      delay(100);    
      Serial.println("Muevete yaaaa!!!!\nLa distancia por la izquierda en centimetros respecto al objeto es :");
      Serial.println(distanceCmizq);
      Serial.println("\n\n");      digitalWrite(ledPin, HIGH);
      
      digitalWrite(ledPin, LOW);
      delay(100);
      delay(delaymili); 
      
    }


}


void Lecturader(long Lecturader){

    if(distanceCm<=200&&distanceCm>=100)
    {
      digitalWrite(ledPin, HIGH);
      delay(300);
      Serial.println("Te encuentras potencialmente en peligro!!!!\nLa distancia por la derecha en centimetros respecto al objeto es :");
      digitalWrite(ledPin, LOW);
      delay(300);
      Serial.println(distanceCm);
      Serial.println("\n\n");
      delay(delaymili); 
      
    }
   if(distanceCm<100&&distanceCm>=50)
    {
      digitalWrite(ledPin, HIGH);
      delay(150);
      Serial.println("Te encuentras en un peligro inminente!!!!\nLa distancia por la derecha en centimetros respecto al objeto es :");
      Serial.println(distanceCm);
      digitalWrite(ledPin, LOW);
      delay(150);
      Serial.println("\n\n");
      delay(delaymili); 
      
    }
    if(distanceCm<50&&distanceCm>0)
    {
      
      digitalWrite(ledPin, HIGH);
      delay(100);
      Serial.println("Muevete yaaaa!!!!\nLa distancia por la derecha en centimetros respecto al objeto es :");
      Serial.println(distanceCm);
     digitalWrite(ledPin, LOW);
     delay(100);
      Serial.println("\n\n");
      delay(delaymili); 
      
    }

}

