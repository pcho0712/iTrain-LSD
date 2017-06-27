#include <Wire.h>
 
#define LDaddrs1 (0x70)  //LEDドライバーHT16K33　アドレス
 
byte LedDot[8] = {
                  B10000001,
                  B11000001,
                  B10100001,
                  B10010001,
                  B10001001,
                  B10000101,
                  B10000011,
                  B10000001
                  };
 
byte LedDot2[8];

byte LedDots[8][8];
byte LedDots2[8][8];


int nownum;
int prenum;

 
//***********セットアップ***************************************************
void setup() 
{
  Serial.begin(115200);
  Wire.begin(); // initialise the connection
  Wire.setClock(400000L); //HT16K33のクロックはMax 400kHz
  int i;
  for(i = 0; i < 8; i++){
    LED_Driver_Setup( LDaddrs1 + i, 1); //HT16K33システムオシレータ　ＯＮ
    LED_Driver_Blink( LDaddrs1 + i, 1, 0); //blink_Hz=0 点滅off, 1は2Hz, 2は1Hz, 3は0.5Hz, on_off=0は消灯、1は点灯
    LED_Driver_Brightness( LDaddrs1 + i, 1 ); // brightness= 0～15
    LED_Driver_DisplayInt( LDaddrs1 + i ); //Display Black OUT
  }
  delay(1000);

  prenum = 0;
  nownum = 1;
}
//**************メインループ*************************************************

void loop() {
  if(Serial.available() >= 63){
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; i++){
          LedDots[i][j] = Serial.read();
      }
      LED_Ada88_cnv(LedDots[i], LedDots2[i]);
      LED_Driver_DisplayOutput(LDaddrs1 + i, LedDots2[i]);
    }
  }
}
//**********************ＬＥＤドライバ　HT16K33　セットアップ*******************
void LED_Driver_Setup(byte LD_addrs, byte on_off)
{
  //HT16K33は8X8マトリックスLEDを２台まで制御できるらしい。
  //ドライバＩＣ#1 アドレスは0x70から設定する。
  Wire.beginTransmission(LD_addrs);
  Wire.write(0x20 | on_off);  //システムオシレータをONにする
  Wire.endTransmission();
}
//**********************ＬＥＤドライバ　HT16K33　点滅周期設定*******************
void LED_Driver_Blink(byte LD_addrs, byte on_off, byte blink_Hz)
{
  //blink_Hz=0 点滅off, 1は2Hz, 2は1Hz, 3は0.5Hz, on_off=0は消灯、1は点灯　
  Wire.beginTransmission(LD_addrs);
  Wire.write(0x80 | (blink_Hz<<1) | on_off); 
  Wire.endTransmission();
}
//**********************ＬＥＤドライバ　HT16K33　明るさ設定*********************
void LED_Driver_Brightness(byte LD_addrs, byte brightness)
{
  // brightness= 0～15
  Wire.beginTransmission(LD_addrs);
  Wire.write(0xE0 | brightness);
  Wire.endTransmission();
}
//**********************ＬＥＤドライバ　HT16K33　画面初期化*********************
void LED_Driver_DisplayInt(byte LD_addrs)
{
  Wire.beginTransmission(LD_addrs);
  Wire.write(0x00);
  for(int i=0;i<8;i++){  
        Wire.write(B00000000);                   //1つ目の8x8LED初期化
        Wire.write(B00000000);                   //2つ目の8x8LED初期化
  }
  Wire.endTransmission();
}
//**********************Adafruit8x8ドット bit変換******************************
void LED_Ada88_cnv(byte* Bdot1, byte* Bdot2)
{
  for(byte i=0; i<8; i++){
    for(byte j=0; j<7; j++){
     bitWrite(Bdot2[i],6-j,bitRead(Bdot1[i],j));
    }
    bitWrite( Bdot2[i],7,bitRead(Bdot1[i],7));  
  }
}
//**********************ＬＥＤドライバ　HT16K33　8X8データ送信*******************
void LED_Driver_DisplayOutput(byte LD_addrs, byte* DotB)
{
  int i,j;
        Wire.beginTransmission(LD_addrs);
        Wire.write(B00000000); //これは必要
        for(i = 0; i<8; i++){
          Wire.write(DotB[i]);
          Wire.write(0); //2つ目のLEDがある場合はここで送るが、今回は無し
        }
        Wire.endTransmission();
}
