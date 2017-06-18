const int SW  = 2;

void setup(){

  // シリアル通信開始
  Serial.begin(115200);

  // ピンモード
  pinMode(SW,  INPUT_PULLUP);
}

void loop(){

  
  char ch[256];
  if(Serial.available()){
   Serial.readBytes(ch,8); 
  }
  Serial.println(ch);

  
  
  // スイッチの値を読み取る
  int value = digitalRead(2);

  if (value != HIGH) {

    Serial.println(1);
  } 
  
}
