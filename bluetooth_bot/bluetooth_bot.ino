#include <SoftwareSerial.h>
#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11

#define ENA  5
#define ENB  6

#define Rx   2
#define Tx   3

#define LIGHT    12
#define BEEP     13

SoftwareSerial bluetooth(Rx,Tx);  // hc05 tx to 2 & hc05 rx to 3
String value;
String angle;
String strength;
String button;

int xy=0,p=0,k=0;

void setup() {
  
  Serial.begin(115200);
  bluetooth.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(LIGHT,OUTPUT);
  pinMode(BEEP,OUTPUT);
  
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);

  analogWrite(ENA,0); //  0 to 255
  analogWrite(ENB,0);
  
}


void loop() {

  while(bluetooth.available()>0)
  {
    value=bluetooth.readStringUntil('#'); 
  }

    angle=value.substring(0,3);
    strength=value.substring(3,6);
    button=value.substring(6,7);
    xy=angle.toInt();
    p=strength.toInt();
    k=button.toInt();
    p*=2;////            p=p*2
    
    Serial.print("angle:");
    Serial.print(xy);
    Serial.print("\t");
    Serial.print("strength:");
    Serial.print(p);
    Serial.print("\t");
    Serial.print("button:");
    Serial.print(k);
    Serial.print("\n");
    
   
     
        
       if(p>0)
     {   



///////////////////////////////////////////////////////////////////////////////////////forward

      
         if((75<xy) && (xy<105))
       {
         
         analogWrite(ENA,p-30);   
         analogWrite(ENB,p);
         digitalWrite(IN1,1);
         digitalWrite(IN2,0);
         digitalWrite(IN3,1);
         digitalWrite(IN4,0);
        
       }

       ///////////////////////////////////////////////////////////////////////////////////////reverse

      
         if((255<xy) && (xy<285))
       {
         
         analogWrite(ENA,p-30);   
         analogWrite(ENB,p);
         digitalWrite(IN1,0);
         digitalWrite(IN2,1);
         digitalWrite(IN3,0);
         digitalWrite(IN4,1);
        
       }
       
///////////////////////////////////////////////////////////////////////////////////////Right

      
       else if((345<xy)||(0<=xy && xy<15)) ////////////////////**********************
       {
         
         analogWrite(ENA,p-30);   
         analogWrite(ENB,p-30);
         digitalWrite(IN1,0);
         digitalWrite(IN2,1);
         digitalWrite(IN3,1);
         digitalWrite(IN4,0);
        
       }
       ////////////////////////////////////////////////////////////////////////////////////Left
        else if((160<xy) && (xy<190))
       {
         
         analogWrite(ENA,p-30);   
         analogWrite(ENB,p-30);
         digitalWrite(IN1,1);
         digitalWrite(IN2,0);
         digitalWrite(IN3,0);
         digitalWrite(IN4,1);
        
       }

       
     }
 ////////////////////////////////////////////////////////////////    

       else  
       {
         analogWrite(ENA,0);   
         analogWrite(ENB,0);
         digitalWrite(IN1,0);
         digitalWrite(IN2,0);
         digitalWrite(IN3,0);
         digitalWrite(IN4,0);
        
       }
` -+

       delay(100);

       value="0";
  
        
  
}
