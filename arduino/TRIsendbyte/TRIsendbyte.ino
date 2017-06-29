int defaultValue = 0;
//byte sendByte = 0x00;
bool triId = true;

void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);


  int i = 0;
  int sum = 0;
  for (i = 0; i < 10; i++) {
    sum += analogRead(A0);
  }
  defaultValue = sum / 10;

}

void loop() {
  char sendByte = 0x00;

  // put your main code here, to run repeaedly:
  /*
  int nowpos = analogRead(A0) - defaultValue;
  if (nowpos > 31) nowpos = 31;
  if (nowpos < -31) nowpos = -31;
  //下位6ビットがポテンショの値、右から6ビット目が符号
  sendByte = (char) nowpos;
  sendByte = sendByte & 0x1F;//下位5bitのみコピー
  if (nowpos < 0) {
    sendByte = sendByte | 0x20; //6bit目に符号
  }
  */


  //上から2bit目がスイッチのオンオフ
  if (digitalRead(12) == HIGH) {
    sendByte = sendByte & 0xBF;
    digitalWrite(13, HIGH);
  } else {
    sendByte = sendByte | 0x40;
    digitalWrite(13, LOW);
  }

  //一番上のビットがID(０か１）
  //  bitWrite(sendByte, 7, triID);
  if (triId) sendByte = sendByte | 0x80;

  Serial.write(sendByte);
  //Serial.write(0xAA);
}
