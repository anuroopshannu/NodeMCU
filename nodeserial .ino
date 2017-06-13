#include<SoftwareSerial.h>

int m1= 5;
int m2= 6;
int val,opt;
SoftwareSerial aserial(3,2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  aserial.begin(4800);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(aserial.available()>0){
    val=aserial.parseInt();
    if(aserial.read()=='\n')
    //Serial.println(val);
    //opt=(499-val)/4;
    opt=(512-val)/4;
    Serial.print("v1,opt\t");
    Serial.println(128+opt);
    //Serial.print("v1");
    //Serial.println(opt);
    Serial.print("v2\t");
    Serial.println(128-opt);
    analogWrite(m1,(128+opt));
    analogWrite(m2,(128-opt));
  }
  
}
