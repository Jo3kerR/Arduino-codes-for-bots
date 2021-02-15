int ir_lf=0,ir_rf=1,ir_lb=2,ir_rb=3;
int trigpin=12,echopin=13;
int motorA=A0;
int motorB=A1;
int motorC=A2;
int motorD=A3;
int motor1_pwm=9;
int motor2_pwm=10;
#define high 255
#define low 0
#define mhigh 190
#define mlow 90
void setup() {
  pinMode(ir_lf,INPUT);
  pinMode(ir_rf,INPUT);
  pinMode(ir_lb,INPUT);
  pinMode(ir_rb,INPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(motorA,OUTPUT);
  pinMode(motorB,OUTPUT);
  pinMode(motorC,OUTPUT);
  pinMode(motorD,OUTPUT);
  pinMode(motor1_pwm,OUTPUT);
  pinMode(motor2_pwm,OUTPUT);

}
void loop() {
  int n=1;
  int spd=255;
  ir_sensors();
  float dist = ultrasonic(); 
  if(dist<=30)
  {
    attack();
  }
  else
  {
    forward(); // rotate at middle
    
  }
  /*if(dist>=2000) {    // opponent very close
    attack();
   } 
   */
 }
void ir_sensors()
{
  if(digitalRead(ir_lf)==0 && digitalRead(ir_rf)==0 && digitalRead(ir_lb) == 1 && digitalRead(ir_rb) == 1)
  {
    stop1();
    delay(10);
    reverse();
    delay(500); // check delay sec so that it comes to the middle of the arena
  }
  if(digitalRead(ir_lf)==0 && digitalRead(ir_rf)==1 && digitalRead(ir_lb) == 1 && digitalRead(ir_rb) == 1)
  {
    stop1();
    delay(10);
    reverse();
    delay(100);
    rotate_right();
    delay(500); // check delay
  }
  if(digitalRead(ir_lf)==0 && digitalRead(ir_rf)==1 && digitalRead(ir_lb)==0 && digitalRead(ir_rb) == 1 ) {
    rotate_right();
    delay(500); // check delay
  }
  if(digitalRead(ir_lf)==1 && digitalRead(ir_rf)==0 && digitalRead(ir_lb)==1 && digitalRead(ir_rb) == 0 ) {
    rotate_left();
    delay(500); // check delay
  }
  if(digitalRead(ir_lf)==1 && digitalRead(ir_rf)==0 && digitalRead(ir_lb) == 1 && digitalRead(ir_rb) == 1 ) 
  {
    stop1();
    delay(10);
    reverse();
    delay(100);
    rotate_left();
    delay(500) ; //check delay
  }
  if(digitalRead(ir_lf)==1 && digitalRead(ir_rf)==1 && digitalRead(ir_lb) == 0 && digitalRead(ir_rb) == 1 ) {
    rotate_right();
    delay(300);
    while(ultrasonic()>30) {
      rotate();
    }
    attack();
  }
  if(digitalRead(ir_lf)==1 && digitalRead(ir_rf)==1 && digitalRead(ir_lb) == 1 && digitalRead(ir_rb) == 0 ) {
    rotate_left();
    delay(300);
    while(ultrasonic()>30) {
      rotate();
    }
    attack();
  }
  if(digitalRead(ir_lf)== 1 && digitalRead(ir_rf)==1 && digitalRead(ir_lb)==1 && digitalRead(ir_rb)==1) // rotate at middle
  {
    // first come to middle
    while(ultrasonic()>30) { // add  && ultrasonic()<20000 ?
      rotate();
    }
    attack();
  }
}

float ultrasonic()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  float duration = pulseIn(echopin,HIGH);
  return (duration/58.2);
}
  
void attack() // check directions of motors
{
  analogWrite(motor1_pwm,high);
  analogWrite(motorA,high);
  analogWrite(motorB,low);
  analogWrite(motor2_pwm,high);
  analogWrite(motorC,high);
  analogWrite(motorD,low);
  delay(2000);
  if(ultrasonic() > 30 ) {
    forward(); // come t middle     
  }
}
void rotate_left() // check directions of motors
{
  analogWrite(motor1_pwm,highh);
  analogWrite(motorA,mlow);
  analogWrite(motorB,low);
  analogWrite(motor2_pwm,high);
  analogWrite(motorC,mhigh);
  analogWrite(motorD,low);
  //delay
}
void rotate_right() //check directions of motors
{
  analogWrite(motor1_pwm,high);
  analogWrite(motorA,mlow);
  analogWrite(motorB,low);
  analogWrite(motor2_pwm,high);
  analogWrite(motorC,mhigh); // check mlow if it works to conserve battery 
  analogWrite(motorD,low);
  //delay
}
/*void forward() // check directions of motors
{
  analogWrite(m1t1,mhigh);
  analogWrite(m1t2,low);
  analogWrite(m2t1,mhigh);
  analogWrite(m2t2,low);
}
void reverse() // check directions of motors
{
  analogWrite(m1t2,mhigh);
  analogWrite(m1t1,low);
  analogWrite(m2t2,mhigh);
  analogWrite(m2t1,low);
  //delay
}
void stopp() // not required ? 
{
  analogWrite(m1t1,low);
  analogWrite(m1t2,low);
  analogWrite(m2t1,low);
  analogWrite(m2t1,low);
}*/
void rotate() // check directions of motors
{
  analogWrite(motor1_pwm,low);
  analogWrite(motorA,low);
  analogWrite(motorB,low);
  analogWrite(motor2_pwm,high);
  analogWrite(motorC,mhigh);
  analogWrite(motorD,low);
  //delay
}
void forward(){
      analogWrite(motor1_pwm,high);
      analogWrite(motorA,high);
      analogWrite(motorB,low);
      analogWrite(motor2_pwm,spd);
      analogWrite(motorC,low);
      analogWrite(motorD,high);
}
void stop1(){
      analogWrite(motor1_pwm,low);
      analogWrite(motorA,low);
      analogWrite(motorB,low);
      analogWrite(motor2_pwm,low);
      analogWrite(motorC,low);
      analogWrite(motorD,low);
 }
void reverse(){
      analogWrite(motor1_pwm,spd);
      analogWrite(motorA,low);
      analogWrite(motorB,high);
      analogWrite(motor2_pwm,spd);
      analogWrite(motorC,high);
      analogWrite(motorD,low);
 }
 /*void stop2(int n){
  switch(n){
 case 1:
 
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
  case 2:
 
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,LOW);
  }
 }*/


 
