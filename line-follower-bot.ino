#define m1t1 5
#define m1t2 6
#define m2t1 9
#define m2t2 10
#define ir_lf 11
#define ir_rf 12
#define low 0
#define high 200
void setup() {
  pinMode(m1t1,OUTPUT);
  pinMode(m1t2,OUTPUT);
  pinMode(m2t1,OUTPUT);
  pinMode(m2t2,OUTPUT);
  pinMode(ir_lf,INPUT);
  pinMode(ir_rf,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  if(!digitalRead(ir_lf)&&!digitalRead(ir_rf))
  {
     analogWrite(m1t1,low);
  analogWrite(m1t2,high);
  analogWrite(m2t1,low);
  analogWrite(m2t2,high);
  }
  if(digitalRead(ir_lf)&&!digitalRead(ir_rf))
  {
     analogWrite(m1t1,low);
  analogWrite(m1t2,high);
  analogWrite(m2t1,low);
  analogWrite(m2t2,low);
  }
  if(!digitalRead(ir_lf)&&digitalRead(ir_rf))
  {
     analogWrite(m1t1,low);
  analogWrite(m1t2,low);
  analogWrite(m2t1,low);
  analogWrite(m2t2,high);
  }
  if(digitalRead(ir_lf)&&digitalRead(ir_rf))
  {
     analogWrite(m1t1,low);
  analogWrite(m1t2,low);
  analogWrite(m2t1,low);
  analogWrite(m2t2,low);
  }
  
  // put your main code here, to run repeatedly:

}
