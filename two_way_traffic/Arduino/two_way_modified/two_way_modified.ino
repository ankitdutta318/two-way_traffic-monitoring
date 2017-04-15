#define red1 8
#define green1 7
#define red2 6
#define green2 5
bool red;
bool green;
int time_delay;
int ch=1;
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
pinMode(red1,OUTPUT);
pinMode(green1,OUTPUT);
pinMode(red2,OUTPUT);
pinMode(green2,OUTPUT);
}
void loop() {
 if(Serial.available()>0) {            //checking if anything is received in the buffer
  while(Serial.available()>0){
    time_delay=(time_delay*10)+Serial.parseInt(); //for receiving the time for lane 2 according to density
  }
  if(ch == 1) {
    red_1();
    green_2();
    ch=2;
    delay(time_delay*1000);
  } 
  else {
    red_2();
    green_1();
    ch=1;
    delay(time_delay*1000);
  }
 }
}
