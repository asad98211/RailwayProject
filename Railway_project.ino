#include <Servo.h>
const int servo1=11,servo2=10,servo3=9,servo4=8,ir1=13,ir2=12;
Servo myservo1,myservo2,myservo3,myservo4;
int pos1=0,pos2=0,pos3=0,pos4 = 0;
int flag=0;
void setup() {
  myservo1.attach(servo1);
  myservo2.attach(servo2);
  myservo3.attach(servo3);
  myservo4.attach(servo4);
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
}
void barricadeDown(int num){
  switch(num){
    case 1:       
      for(pos1=0;pos1<=90;pos1++){
        myservo1.write(pos1);
        delay(10);
        myservo2.write(pos1);
        delay(10);
       }
       break;
    case 2:       
      for(pos2=0;pos2<=90;pos2+=1){
        myservo3.write(pos2);
        delay(10);
        myservo4.write(pos2);
        delay(10);
       }
       break;
    }
}
void barricadeUp(int num){
  switch(num){
    case 1:       
      for(pos1=90;pos1>=0;pos1--){
        myservo1.write(pos1);
        delay(10);
        myservo2.write(pos1);
        delay(10);
       }
       break;
    case 2:       
      for(pos2=90;pos2>=0;pos2-=1){
        myservo3.write(pos2);
        delay(10);
        myservo4.write(pos2);
        delay(10);
       }
       break;
  }
}
void loop() {
  int signal1,signal2;
  static int flag1=1;
  signal1=digitalRead(ir1);
  signal2=digitalRead(ir2);
  if(!flag){
     barricadeUp(1);
     delay(1000);
     barricadeUp(2);
     flag=1;
  }
  if(signal1==HIGH&&flag1==1){
    barricadeUp(2);
    barricadeDown(1);
    flag1=0;
  }
  else if(signal2==HIGH&&flag1==0){
    barricadeUp(1);
    barricadeDown(2);  
    flag1=1;
    }
/*  
  if(signal1==HIGH){
    barricadeUp(2);
  }
  else if(signal2==HIGH){
    barricadeDown(1);
  }
  else if(signal3==HIGH){
    barricadeUp(1);
  }
  else if(signal4==HIGH){
    barricadeDown(2);
  }
 barricadeUp(1);
 delay(1000);
 barricadeUp(2);
 delay(1000);
 barricadeDown(1);
 delay(1000);
 barricadeDown(2);
 delay(1000);*/
}
