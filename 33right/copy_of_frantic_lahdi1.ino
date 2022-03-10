//design by 白雲
byte rrr[4] = {9,8,7,6};
byte ccc[4] = {5,4,3,2};
//byte DP[8] = {10,11,12,13,A3,A4,A5};
byte DP[8] = {12,13,11,10,A5,A4,A3};
byte conterl[3]={A0,A1,A2};
byte contrl[3] = {0b1111111,0b1111111,0b1111111} ;
const char numberrr[4][4] = {     
    {'1','2','3','A'}, 
    {'4','5','6','B'}, 
    {'7','8','9','C'},
    {'*','0','#','D'}
};
byte k;
byte i, j;
byte isme;

const byte charMap[15] = {
// 上右左中右下左   
  0b0001000, // 0
  
  0b1011011, // 1
  
  0b0010100, // 2
  
  0b0010001, // 3
  
  0b1000011, // 4
  
  0b0100001, // 5
  
  0b0100000, // 6
  
  0b0011011, // 7
  
  0b0000000, // 8
  
  0b0000001, // 9
  
  0b0000010, // A
  
  0b1100000, // b
  
  0b0101100, // c
  
  0b1010000, // d
  
  0b1110111  // #

};

void setup()
{
  for (byte i = 0; i < 8; i++) {
    pinMode(DP[i], OUTPUT);
    digitalWrite(DP[i], 1);
  }
  for (i = 0; i <= 3; i++) {
    pinMode(rrr[i], INPUT);
    pinMode(ccc[i], OUTPUT);
    digitalWrite(ccc[i], HIGH);
    digitalWrite(rrr[i], HIGH);
  }
  for (i = 0; i <= 2; i++) {
    pinMode(conterl[i], OUTPUT);
    digitalWrite(conterl[i], HIGH);
  }
    
  

  Serial.begin(9600);
}

void loop()
{
  for (i = 0; i <= 3; i++) {
    for (j = 0; j <= 3; j++) {
      digitalWrite(ccc[j], LOW);
      isme = digitalRead(rrr[i]);

      if (isme == LOW) {
        Serial.print(numberrr[i][j]);
        delay(50);
        dp7(numberrr[i][j]);

          
        digitalWrite(ccc[j], HIGH);
        break;       
      }
      lol();
      digitalWrite(ccc[j], HIGH);
    }
  }
  
}
//------------------------------------------
void dp7(char c) {  
  byte MC;
  
  switch (c) {
    case '0': MC = charMap[0]; break;
    case '1': MC = charMap[1]; break;
    case '2': MC = charMap[2]; break;
    case '3': MC = charMap[3]; break;
    case '4': MC = charMap[4]; break;
    case '5': MC = charMap[5]; break;
    case '6': MC = charMap[6]; break;
    case '7': MC = charMap[7]; break;
    case '8': MC = charMap[8]; break;
    case '9': MC = charMap[9]; break;
    case 'A': MC = charMap[10]; break;
    case 'B': MC = charMap[11]; break;
    case 'C': MC = charMap[12]; break;
    case 'D': MC = charMap[13]; break;
    case '#': MC = charMap[14]; break;
    case '*': MC = charMap[14]; break;
  }

  left_move(contrl,3);
  Serial.print(contrl[0]);
  Serial.print(contrl[1]);
  Serial.print(contrl[2]);
  contrl[2]=MC;
  
  
}

//------------------------------------------
int left_move(byte *buffer , int buf_len)
{
	int i ;
	char tmp = buffer[0];
	for(i = 1 ; i < buf_len ; i++)
	{
		buffer[i-1] = buffer[i] ;
	}
	buffer[buf_len-1] = tmp ;
}


//------------------------------------------
void lol(){



  for(int i=0;i<3;i++){

    if(i==0){
      k=contrl[0];

    }
    else if(i==1){
      k=contrl[1];
    }
    else if(i==2){
      k=contrl[2];
    }


    for (byte i = 0; i < 7; i++){
      digitalWrite(DP[i], bitRead(k,6-i));

    }
    digitalWrite(conterl[i],1);
    delay(1);
    digitalWrite(conterl[i],0);
  }
}