#include <FlexiTimer2.h>

#include <TimerOne.h>
int seven[10]={
  0xC0,0XF9,0xA4,0xB0,0x99,0x92,0x82,0xD8,0x80,0x98
};
int se[8]{13,12,11,10,9,8,7,6};
int sc[4]{22,24,26,28};
int count=0;
int set1=0;
int set2=0;
int set3=0;
int set4=0;
boolean clock=HIGH;
int k;


void event(){
  count++;
  if(set1<9){
    set1++;
  }
  else{
    count=0;
    set1=0;
    set2++;
  }
  if(set2>=6){
    set3++;
    set2=0;
  }
  if(set3>=10){
    set4++;
    set3=0;
  }
  if(set4==2 and set3==4 ){
    set1=0;
    set2=0;
    set3=0;
    set4=0;
    count=0;
  }

  
  

}
void LED(){
  clock=!clock;
  digitalWrite(38,clock);

}


void setup() {
  pinMode(38,OUTPUT);
  digitalWrite(38,0);
  Timer1.initialize(500000);
  Timer1.attachInterrupt(LED);
  
  FlexiTimer2::set(10,1.0/1000,event);
  FlexiTimer2::start();



  
  for(int i=0;i<4;i++){
   pinMode(sc[i],OUTPUT);
   digitalWrite(sc[i],1);
  }
  for(int i=0;i<8;i++){
   pinMode(se[i],OUTPUT);
   digitalWrite(se[i],1);
  }

  
}

void loop() {

  
  lol(set1,set2,set3,set4);

}


void lol(int x1,int x2,int x3,int x4){


  
  for(int i=0;i<4;i++){
  
    if(i==0){
      k=seven[x1];

    }
    else if(i==1){
      k=seven[x2];
    }
    else if(i==2){
      k=seven[x3];
    }
    else if(i==3){
      k=seven[x4];
    }
    
    
    for(int j=0;j<8;j++){

      digitalWrite(se[j],bitRead(k,j));
      
    }
    digitalWrite(sc[i],0);
    delay(1);
    digitalWrite(sc[i],1);    
  }
}
