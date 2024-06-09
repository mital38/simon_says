
#include <Adafruit_CircuitPlayground.h>

float totalAccel;
volatile bool switch_flag = false;
volatile int idx = 0;
int level = 0;
int cur = 0;
bool next_level = true;
bool loss = false;
int level_arr[20];
float midi[127];
int pinr = 5;





///////////////////////////////////////////////////////////////////////////////
void setup() {
CircuitPlayground.begin();
Serial.begin(9600);
generateMIDI();

//attachInterrupt(4, A_ISR, RISING);
attachInterrupt(digitalPinToInterrupt(4), leftisr, RISING);
attachInterrupt(digitalPinToInterrupt(pinr), rightisr, RISING);
attachInterrupt(digitalPinToInterrupt(7), switchisr, CHANGE);



 switch_flag = digitalRead(7);

CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);
}

///////////////////////////////////////////////////////////////////////////////
void loop() {

if (!switch_flag && !loss){

  if (next_level){
    cur = 0;
    int temp = random(10);
    level_arr[level] = temp;
    level++;
    next_level = false;
    Serial.print("Level ");
    Serial.println(level);

    for (int i = 0 ; i < level ; i++){
      int randNumber = random (10);
      CircuitPlayground.setPixelColor(level_arr[i], 0x110011);
      delay(750);
      CircuitPlayground.setPixelColor(level_arr[i], 0x000000);
      delay(750);
    }
  }
  
  CircuitPlayground.setPixelColor(idx, 0x111111);
  delay(500);
  off();
  delay(500);

  totalAccel = read_accel();
  //Serial.println(totalAccel);

  if (totalAccel > 15 ){
    if (idx == level_arr[cur]){
      green();
      delay(1000);
      off();
      delay(100);
      cur++;
      if (cur == level){
        next_level = true;
      }
    }
    else {
      red();
     loss = true;
     Serial.println("Game over");
      CircuitPlayground.playTone(midi[50],100);


    }
  }

}
else if (switch_flag){
  next_level = true;
  level = 0;
  loss = false;
  off();
}
}

void green()
{
for (int i = 0; i < 10 ; i++){
 CircuitPlayground.setPixelColor(i, 0x001000);
}
}


void blue()
{
for (int i = 0; i < 10 ; i++){
 CircuitPlayground.setPixelColor(i, 0x000010);

}
}

void off(){
for (int i = 0; i < 10 ; i++){
 CircuitPlayground.setPixelColor(i, 0x000000);
 }
}

void red(){
for (int i = 0; i < 10 ; i++){
 CircuitPlayground.setPixelColor(i, 0x100000);
 }
}

float read_accel(){
////READ ACCELERATION//////////////
float X = 0;
float Y = 0;
float Z = 0;
for (int i=0; i<10; i++) {
  X += CircuitPlayground.motionX();
  Y += CircuitPlayground.motionY();
  Z += CircuitPlayground.motionZ();
  delay(1);
}
X /= 10;
Y /= 10;
Z /= 10;
return sqrt(X*X + Y*Y + Z*Z);
////////////////////////////////////
}

void generateMIDI(){
for (int i = 0; i < 127; ++i)
{
  midi[i] = (440/ 32.0) * pow(2.0, ((i - 9.0) / 12.0));
  //Serial.println(midi[x]);
}
}

void rightisr(){
if (idx == 0){
  idx = 9;
  
}
else{
  idx--;
  
}
}

void leftisr(){

 if (idx == 9){
 idx = 0;
  
 }
else {
 idx++;

 }
}

void switchisr(){
switch_flag = digitalRead(7);
}



