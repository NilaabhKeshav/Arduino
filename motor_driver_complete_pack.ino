#define pwm 9
#define in1 7
#define in2 8
char c;
int rotDirection = 0;
int a = 0;
void setup() {
  pinMode(pwm, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  
  if(Serial.available()){ 
  Serial.write(a);
  switch(a){
    case '1':
    Serial.println("Forward Backward");
  analogWrite(pwm,100);
  digitalWrite(in1,HIGH);  
  digitalWrite(in2,LOW);
  delay(5000);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  delay(5000);
  break;

  case '2':
  Serial.println("f for forward");
  c=Serial.read();
  if(c=='f'){
   Serial.println("Forward"); 
  digitalWrite(in1,HIGH);  
  digitalWrite(in2,LOW);
  }
  else if(c=='b'){
  Serial.println("Backward");
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
    }
   else if(c=='s')
   {
    Serial.println("Stop");
     digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);
   }
   break;

  case '3':
  Serial.println("Gradual Change");
   for(a=0;a<=200;a++){
  Serial.println(a);  
  analogWrite(pwm,a);  
  digitalWrite(in1,HIGH);  
  digitalWrite(in2,LOW);
  delay(1000);
   }
  
  }
  }
} 
