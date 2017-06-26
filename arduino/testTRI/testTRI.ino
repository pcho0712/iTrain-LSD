int defaultValue = 0;

void setup() {
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
  // put your main code here, to run repeatedly:

  if(digitalRead(13) == HIGH){
    Serial.print("HIGH  ");
    Serial.println(analogRead(A0) - defaultValue);
  }else{
    Serial.print("LOW  ");
    Serial.println(analogRead(A0) - defaultValue);
  }
}
