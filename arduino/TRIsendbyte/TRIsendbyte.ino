int defaultValue0 = 0;
int defaultValue1 = 0;

bool triId = true;

void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(3, INPUT_PULLUP);

  int i = 0;
  defaultValue0 = 0;
  defaultValue1 = 0;
  for (i = 0; i < 10; i++) {
    defaultValue0 += analogRead(A0);
    defaultValue1 += analogRead(A1);
  }
  defaultValue0 = defaultValue0 / 10;
  defaultValue1 = defaultValue1 / 10;

}

void loop() {
  byte sendByte0 = 0x00;
  byte sendByte1 = 0x00;

  // put your main code here, to run repeaedly:  
  int nowpos0 = analogRead(A0) - defaultValue0;
  if (nowpos0 > 127) nowpos0 = 127;
  if (nowpos0 < -127) nowpos0 = -127;

/*
  //下位6ビットがポテンショの値、右から6ビット目が符号
  if (nowpos0 < 0) {
    sendByte0 = (byte) abs(nowpos0);
    sendByte0 = sendByte0 & 0x1F;//下位5bitのみコピー
    sendByte0 = sendByte0 | 0x20; //6bit目に符号
  }else{
    sendByte0 = (byte) abs(nowpos0);
    sendByte0 = sendByte0 & 0x1F;//下位5bitのみコピー  
  }
:*/

  int nowpos1 = analogRead(A1) - defaultValue1;
  if (nowpos1 > 127) nowpos1 = 127;
  if (nowpos1 < -127) nowpos1 = -127;

/*
  if (nowpos1 < 0) {
    sendByte1 = (byte) abs(nowpos1);
    sendByte1 = sendByte1 & 0x1F;//下位5bitのみコピー
    sendByte1 = sendByte1 | 0x20; //6bit目に符号
  }else{
    sendByte1 = (byte) abs(nowpos1);
    sendByte1 = sendByte1 & 0x1F;//下位5bitのみコピー    
  }
*/


  //上から2bit目がスイッチのオンオフ
  //*1/0******
 char is_on0 = 0;
 char is_on1 = 0;
  if (digitalRead(3) == HIGH) {
    //sendByte0 = sendByte0 & 0xBF;
    is_on0 = 1;
    digitalWrite(13, HIGH);
  } else {
    //sendByte0 = sendByte0 | 0x40;
    digitalWrite(13, LOW);
    is_on0 = 0;
  }  
  if (digitalRead(2) == HIGH) {
    //sendByte1 = sendByte1 & 0xBF;
    is_on1 = 1;
  } else {
    //sendByte1 = sendByte1 | 0x40;
    is_on1 = 0;
  }

  //一番上のビットがID(０か１）
  //if (0) sendByte0 = sendByte0 | 0x80;
  //if (1) sendByte1 = sendByte1 | 0x80;

  Serial.write(0xFF);
  Serial.write(0x00);
  Serial.write(is_on0);
  Serial.write((char)nowpos0);

  Serial.write(0xFF);
  Serial.write(0x01);
  Serial.write(is_on1);
  Serial.write((char)nowpos1);

  
  //Serial.write(sendByte0);
  //Serial.write(sendByte1);

  //For Debug
  //Serial.print(sendByte0, BIN);
  //Serial.print(" ");
  //Serial.println(sendByte1, BIN);
}
