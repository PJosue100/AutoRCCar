
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

int led = 13;

// duration for output
int time = 53;
// initial command
int command = 0;



void setup() {

  Serial.begin(9600);
  pinMode(led, OUTPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {

  //if(Serial.available() > 0){
  //  char data = Serial.read();
  //  if(data == 'y'){
  //    digitalWrite(led, HIGH);
  //  }
  //  else if(data == 'n'){
  //    digitalWrite(led, LOW);
  //  }
  //  else if(data == 'r'){
  //    forward_right(time);
  //  }
  //  else if(data == 'l'){
  //    left(time);
  //  }
  //  else if(data == 'f'){
  //    forward(time);
  //  }
  //}

  if (Serial.available() > 0){
    command = Serial.read();
  }
  else{
    reset();
  }
  send_command(command,time);

  
}


void right(int time){
  digitalWrite(led, HIGH);
  analogWrite(ENA, 150);  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  //analogWrite(ENB, 90);
  //digitalWrite(IN3, LOW);
  //digitalWrite(IN4, HIGH);
  
  delay(time);
  reset();
}

void left(int time){
  digitalWrite(led, HIGH);
  analogWrite(ENB, 150);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  //analogWrite(ENA, 90);  
  //digitalWrite(IN1, HIGH);
  //digitalWrite(IN2, LOW);
  
  delay(time);
  reset();
}

void forward(int time){
  digitalWrite(led, HIGH);
  analogWrite(ENA, 90);
  analogWrite(ENB, 90);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
  delay(time);
  reset();
}

void reverse(int time){
  digitalWrite(led, HIGH);
  analogWrite(ENA, 90);
  analogWrite(ENB, 90);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  delay(time);
  reset();
}


void forward_right(int time){
  digitalWrite(led, HIGH);
  analogWrite(ENA, 150);  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  int indice = 0;  
  for(indice = 0; indice < 2; indice ++){
    delay(9);
    analogWrite(ENB, 90);
    delay(19);
    analogWrite(ENB, 0);
  }
  reset();
}

void forward_left(int time){
  digitalWrite(led, HIGH);
  analogWrite     (ENB, 150);  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);  

  int indice = 0;  
  for(indice = 0; indice < 2; indice ++){
    delay(9);
    analogWrite(ENA, 90);
    delay(19);
    analogWrite(ENA, 0);
  }
  reset();
}

void reverse_right(int time){
  digitalWrite(led, HIGH);
  analogWrite(ENA, 150);  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  int indice = 0;  
  for(indice = 0; indice < 2; indice ++){
    delay(9);
    analogWrite(ENB, 90);
    delay(19);
    analogWrite(ENB, 0);
  }
  reset();
}

void reverse_left(int time){
  digitalWrite(led, HIGH);
  analogWrite(ENB, 150);  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);  

  int indice = 0;  
  for(indice = 0; indice < 2; indice ++){
    delay(9);
    analogWrite(ENA, 90);
    delay(19);
    analogWrite(ENA, 0);
  }
  reset();
}












void reset(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(led, LOW);
}


void send_command(int command, int time){
  switch (command){

     //reset command
     case 0: reset(); break;

     // single command
     case 1: forward(time); break;
     case 2: reverse(time); break;
     case 3: right(time); break;
     case 4: left(time); break;

     //combination command
     case 6: forward_right(time); break;
     case 7: forward_left(time); break;
     case 8: reverse_right(time); break;
     case 9: reverse_left(time); break;

     default: Serial.print("Inalid Command\n");
    }
}
