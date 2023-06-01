const int r = 9;             //connect red led at pin 9    
const int y = 10;           //connect yellow led at pin 10
const int g = 11;           //connect green led at pin 11
const int sec = 1000;       //seconds defined 
int indice = 0;
void setup() 
  {
    Serial.begin(9600);
    pinMode(r,OUTPUT);
    pinMode(y,OUTPUT);
    pinMode(g,OUTPUT);
    delay(sec);
  }

void loop()
    {
      //for (indice=10; indice<=250; indice=indice+10) { 
        analogWrite(r,150) ;//analogWrite(r,80) ;
        delay(sec*5);
        analogWrite(r,0) ;
        digitalWrite(y,HIGH) ;
        delay(sec*1);
        digitalWrite(y,LOW) ;
        analogWrite(g,25) ;
        delay(sec*5);
        analogWrite(g,0) ;

        //Serial.print(indice);
        //Serial.print('\n'); 
        //delay(sec*5);
      //}
        
    }
