int defaultValue = 0;
unsigned char sendByte = 0;
bool triId = 0;

void setup() {
  // put your setup code here, to run once:
   // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);


  int i = 0;
  int sum = 0;
  for(i = 0; i < 10; i++){
    sum += analogRead(A0);
  }
  defaultValue = sum / 10;

}

void loop() {
  // put your main code here, to run repeaedly:
  int nowpos = analogRead(A0) - defaultValue;
  //下位6ビットがポテンショの値、右から6ビット目が符号
  if(nowpos > 0){
    sendByte = (unsigned char)nowpos;
    bitWrite(sendByte, 5, 0);
  }else{
    nowpos = -nowpos;
    bitWrite(sendByte, 5, 1);
  }

  //上から2bit目がスイッチのオンオフ
  if(digitalRead(12) == HIGH){
    bitWrite(sendByte, 6, 0);
    digitalWrite(13,HIGH);
  }else{
    bitWrite(sendByte, 6, 1);
        digitalWrite(13,LOW);
  }

  //一番上のビットがID(０か１）
  bitWrite(sendByte, 7, 1);

  Serial.write(sendByte);
//Serial.write(0xAA);
}
