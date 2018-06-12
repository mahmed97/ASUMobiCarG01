#include<SoftwareSerial.h>
SoftwareSerial BT(3,2);
#define RMS 10
#define LMS 11
int MPin[4]={6,7,8,9};
void setup() {
 BT.begin(9600);
 Serial.begin(9600);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(A3,INPUT);
 pinMode(A4,INPUT);
 pinMode(A5,INPUT);
}
void motors(int Volt[4]){
  for (int x=0;x<4;x++){
    digitalWrite(MPin[x],Volt[x]);
    }
  }
void forward(){
int F[4]={1,0,1,0};
analogWrite(RMS,255);
analogWrite(LMS,255);
motors(F);
}
void backward(){
int B[4]={0,1,0,1};
motors(B);
}
void right(){
  int R[4]={1,0,0,1};

motors(R);
}
void left(){
int L[4]={0,1,1,0};

motors(L);
}
void forwardR(){
int FR[4]={1,0,1,0};
analogWrite(RMS,255);
analogWrite(LMS,100);
motors(FR);
}
void forwardL(){
int FL[4]={1,0,1,0};
analogWrite(RMS,100);
analogWrite(LMS,255);
motors(FL);
}
void backwardR(){
int BR[4]={0,1,0,1};
analogWrite(RMS,255);
analogWrite(LMS,100);
motors(BR);
}
void backwardL(){
int BL[4]={0,1,0,1};
analogWrite(RMS,100);
analogWrite(LMS,255);
motors(BL);
}
void STOP(){
int S[4]={0,0,0,0};
motors(S);
}

void loop() {
  int Rfra=digitalRead(A3);
  int Cfra=digitalRead(A4);
 int Lfra=digitalRead(A5);
int x,y,z;
  if (Cfra==0&&Rfra==1&&Lfra==1){forward();z=1;}
else if (Cfra==0&&Rfra==0&&Lfra==1||Cfra==1&&Rfra==0&&Lfra==1){right();x=1;}
else if (Cfra==0&&Rfra==1&&Lfra==0||Cfra==1&&Rfra==1&&Lfra==0){left();y=1;}
else if(Cfra==0&&Rfra==0&&Lfra==0){STOP();}
else if(Cfra==1&&Rfra==1&&Lfra==1){if(x==1){right();} else if(y==1){left();} else if(z==1){forward();}}
 Serial.println(Cfra);
  char input = BT.read();
switch(input){
    case'F':forward();break;
    case'B':backward();break;
    case'R':right();break;
    case'L':left();break;
    case'S':STOP();break;
    case'I':forwardR();break;
    case'G':forwardL();break;
    case'J':backwardR();break;
    case'H':backwardL();break;


}
  }
