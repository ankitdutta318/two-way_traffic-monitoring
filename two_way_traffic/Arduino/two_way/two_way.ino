#define datIn1 A2
#define datIn2 A0
#define red1 8
#define green1 7
#define red2 6
#define green2 5
int thresold=500;
  bool red;
  bool green;
  double read1;
  double read2;
void getcurr_density(){
  read1=analogRead(datIn1);
  read2=analogRead(datIn2);
  Serial.println(read1);
  delay(2000);
  Serial.println(read2);
}
void red_1(){
  red=true;
  green=false;
  digitalWrite(8,red);
  digitalWrite(7,green);
}
void red_2(){
  red=true;
  green=false;
  digitalWrite(6,red);
  digitalWrite(5,green);
}
void green_1(){
  red=false;
  green=true;
  digitalWrite(8,red);
  digitalWrite(7,green);
}
void green_2(){
  green=true;
  red=false;
  digitalWrite(6,red);
  digitalWrite(5,green);
}
void setup() {
Serial.begin(9600); 
pinMode(A2,INPUT);
pinMode(A0,INPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
}

void loop() {
getcurr_density();
if(read1<thresold && read2<thresold){
  red_1();
  green_2();
  delay(1200);
  red_2();
  green_1();
  delay(1200);
}
else{
  if(read1>read2){
    red_1();
    green_2();
    delay(1800);
  }
    else{
      red_2();
      green_1();
      delay(1800);
  }
}
}
