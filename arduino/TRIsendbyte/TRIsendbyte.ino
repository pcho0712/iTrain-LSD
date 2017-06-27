int defaultValue = 0;
unsigned char sendByte = 0;
boolean triId = 0;

void setup() {
  // put your setup code here, to run once:
   // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, INPUT);

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
    bitWrite(sendByte, 6, 0);
  }else{
    nowpos = -nowpos;
    bitWrite(sendByte, 6, 1);
  }

  //上から2bit目がスイッチのオンオフ
  if(digitalRead(13) == HIGH){
    bitWrite(sendByte, 7, 0);
  }else{
    bitWrite(sendByte, 7, 1);
  }

  //一番上のビットがID(０か１）
  bitWrite(sendByte, 8, triId);

  Serial.write(sendByte);
}
