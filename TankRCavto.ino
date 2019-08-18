int pot1 = A1; // pin pot1  ГАЗ
int pot2 = A2; // pin pot2 РУЛЬ
int IN1 = 8;  
int IN2 = 7;
int IN3 = 2;
int IN4 = 4;
int EN1 = 9;
int EN2 = 10;

int motr;  // скорость правого мотора
int motl;  // скорость левого мотора
int mr;
int ml;
int will; // руль

void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  mr = analogRead(pot1);
  mr = map(mr, 0, 1023, 0, 255);
  ml = analogRead(pot1);
  ml = map(ml, 0, 1023, 0, 255);
  will = analogRead(pot2);
  will = map(will,0, 1023, -250, 250);
  
  if(-5>will<5){
    motr=mr;
    motl=ml;
  }
  if(will<-5){
    motr=mr;
    motl=ml+will;
  }
  if(will>5){
    motr=mr-will;
    motl=ml;
  }
  Serial.print(will);
  Serial.print("\t\t");
  Serial.print(motr);
  Serial.print("\t\t");
  Serial.println(will);
  
 

  if(ml>10||mr>10){    //вперед
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, motl);
  analogWrite(EN2, motr);
  }
  if(ml<10||mr<10){     //назад
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  analogWrite(EN1, motr+130);
  analogWrite(EN2, motl+130);
  }
  
    
  

}

