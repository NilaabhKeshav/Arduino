#define enA 2
#define in1 0
#define in2 1
#define enB 6
#define in3 4
#define in4 7
#define in5 8
#define in6 11
#define enC 10
#define jx A0
#define jy A1
#define button 50
int xAxis;
int yAxis;
int buttonValue;

void setup() { 
  pinMode(enA, OUTPUT);//pwm
  pinMode(enB, OUTPUT);//pwm
  pinMode(enC, OUTPUT);//pwm
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(jx,INPUT);
  pinMode(jy,INPUT);
  pinMode(button,INPUT);
  }
void loop() {
  xAxis = analogRead(jx);
  yAxis = analogRead(jy);
  buttonValue = digitalRead(button);
 if(buttonValue==LOW){ 
  if ((yAxis < 400) && (xAxis>400) && (xAxis<600) )//back
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    digitalWrite(in5,LOW);
    digitalWrite(in6,HIGH);
    analogWrite(enA, 60);
    analogWrite(enB, 20);
    analogWrite(enC, 20);
  }
  else if ((yAxis > 600) &&  (xAxis>400) && (xAxis<600) ) //front
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    analogWrite(enA, 60);
    analogWrite(enB, 20);
    analogWrite(enC, 20);
  }
  else if ((xAxis > 600) &&  (yAxis>400) && (yAxis<600))//left turn
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    analogWrite(enA, 60);
    analogWrite(enB, 20);
    analogWrite(enC, 20);
  }
  else if ((xAxis <400) && (yAxis>400) && (yAxis<600))//right turn
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    analogWrite(enA, 60);
    analogWrite(enB, 20);
    analogWrite(enC, 20);
  }
  else 
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);
    analogWrite(enA, 60);
    analogWrite(enB, 20);
    analogWrite(enC, 20);
  }
 }
  
  
else if(buttonValue==HIGH)
 {
  if((yAxis>600) && (xAxis>400) && (xAxis<600))//clockwise rotation
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    analogWrite(enA, 60);
    analogWrite(enB, 20);
    analogWrite(enC, 20);
  }
  
  else if((yAxis<400) && (xAxis>400) && (xAxis<600))//anticlockwise rotation
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    analogWrite(enA, 60);
    analogWrite(enB, 20);
    analogWrite(enC, 20);
  }
  else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);
    
  }
 }
 else if(xAxis>550 && yAxis>550 && buttonValue==LOW)//top right
  { 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    motorSpeedB=map(xAxis,550,1023,0,50);
    motorSpeedC=map(xAxis,550,1023,0,50);
    motorSpeedA=1.732*motorSpeedB;
  }
  
  else if(xAxis>550 && yAxis<470 && buttonValue==LOW)//bottom right
  { 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    motorSpeedB=map(xAxis,550,1023,0,50);
    motorSpeedC=map(xAxis,550,1023,0,50);
    motorSpeedA=1.732*motorSpeedB;
  }

  else if(xAxis<470 && yAxis>550 && buttonValue==LOW)//top left
  { 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    motorSpeedB=map(xAxis,470,0,0,50);
    motorSpeedC=map(xAxis,470,0,0,50);
    motorSpeedA=1.732*motorSpeedB;
  }

  else if(xAxis<470 && yAxis<470 && buttonValue==LOW)//bottom left
  { 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    motorSpeedB=map(xAxis,470,0,0,50);
    motorSpeedC=map(xAxis,470,0,0,50);
    motorSpeedA=1.732*motorSpeedB;   
    //Bottom left 45 angle
  }

}
