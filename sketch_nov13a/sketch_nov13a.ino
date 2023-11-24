#include <Stepper.h>

// 스텝 모터의 핀 설정
const int in0Pin = 0;
const int in1Pin = 1;
const int in2Pin = 2;
const int in3Pin = 3;
const int in4Pin = 4;
const int in5Pin = 5;

const int in6Pin = 6;
const int in7Pin = 7;

const int in8Pin = 8;
const int in9Pin = 9;

const int in10Pin = 10;
const int in11Pin = 11;

const int in12Pin = 12;
const int in13Pin = 13;

// 스텝 모터의 단계 수와 속도 설정
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, in2Pin, in3Pin, in4Pin, in5Pin);
Stepper myStepper2(stepsPerRevolution, in8Pin, in9Pin, in10Pin, in11Pin);

unsigned long motor1StartTime;
unsigned long motor2StartTime;
unsigned long motor3StartTime;
unsigned long motor4StartTime;

const int motor1Duration = 0;  
const int motor2Duration = 400;
const int motor3Duration = 600;  
const int motor4Duration = 800;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  SettingDC();

  motor1StartTime = millis();
  motor2StartTime = millis();
  motor3StartTime = millis();
  motor4StartTime = millis();

}



void loop() {

  DcMoterSpeed(50);

  unsigned long currentTime = millis();

  // DcMoter1Up();
  // DcMoter2Up();
  // DcMoter3Up();
  // DcMoter4Up();


  // DcMoter1Up();
  // DcMoter2Down();
  // DcMoter3Down();
  // DcMoter4Down();

  DcMoter2Down();
  DcMoter3Down();
  DcMoter4Down();
  
  if (currentTime - motor1StartTime >= motor1Duration) {
    DcMoter1Stop();
  }
  
  if (currentTime - motor2StartTime >= motor2Duration) {
    DcMoter2Stop();
  }
  
  if (currentTime - motor3StartTime >= motor3Duration) {
    DcMoter3Stop();
  }

  if (currentTime - motor4StartTime >= motor4Duration) {
    DcMoter4Stop();
  }


}

void StepMotoerFunc() {
  myStepper.setSpeed(200); // 속도 설정 (값을 조절하여 속도를 변경할 수 있습니다.)
  myStepper.step(stepsPerRevolution);
  delay(1000);

  // 반시계 방향으로 1회전
  myStepper.setSpeed(200);
  myStepper.step(-stepsPerRevolution);
  delay(1000);

  myStepper2.setSpeed(200); // 속도 설정 (값을 조절하여 속도를 변경할 수 있습니다.)
  myStepper2.step(stepsPerRevolution);
  delay(1000);

  // 반시계 방향으로 1회전
  myStepper2.setSpeed(200);
  myStepper2.step(-stepsPerRevolution);
  delay(1000);
}

void DcMoterSpeed(int i){
  analogWrite(in3Pin, i);
  analogWrite(in9Pin, i);
  analogWrite(in10Pin, i);
  analogWrite(in11Pin, i);
}

void SettingDC(){
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  pinMode(in5Pin, OUTPUT);

  pinMode(in6Pin, OUTPUT);
  pinMode(in7Pin, OUTPUT);
  pinMode(in8Pin, OUTPUT);
  pinMode(in9Pin, OUTPUT);

  pinMode(in10Pin, OUTPUT);
  pinMode(in11Pin, OUTPUT);
  pinMode(in12Pin, OUTPUT);
  pinMode(in13Pin, OUTPUT);
}

void DcMoterUp(){
  digitalWrite(in4Pin, LOW);
  digitalWrite(in5Pin, HIGH);
  digitalWrite(in6Pin, LOW);
  digitalWrite(in7Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in8Pin, HIGH);
  digitalWrite(in12Pin, LOW);
  digitalWrite(in13Pin, HIGH);
}

void DcMoter1Up(){
  digitalWrite(in4Pin, LOW);
  digitalWrite(in5Pin, HIGH);
}

void DcMoter2Up(){
  digitalWrite(in6Pin, LOW);
  digitalWrite(in7Pin, HIGH);
}

void DcMoter3Up(){
  digitalWrite(in2Pin, LOW);
  digitalWrite(in8Pin, HIGH);
}

void DcMoter4Up()
{ 
  digitalWrite(in12Pin, LOW);
  digitalWrite(in13Pin, HIGH);
}

void DcMoterDown()
{ 
  digitalWrite(in4Pin, HIGH);
  digitalWrite(in5Pin, LOW);
  digitalWrite(in6Pin, HIGH);
  digitalWrite(in7Pin, LOW);

  digitalWrite(in2Pin, HIGH);
  digitalWrite(in8Pin, LOW);
  digitalWrite(in12Pin, HIGH);
  digitalWrite(in13Pin, LOW);
}

void DcMoter1Down(){
  digitalWrite(in4Pin, HIGH);
  digitalWrite(in5Pin, LOW);
}

void DcMoter2Down(){
  digitalWrite(in6Pin, HIGH);
  digitalWrite(in7Pin, LOW);
}

void DcMoter3Down(){
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in8Pin, LOW);
}

void DcMoter4Down(){
  digitalWrite(in12Pin, HIGH);
  digitalWrite(in13Pin, LOW);
}

void DcMoter1Stop(){
  digitalWrite(in4Pin, LOW);
  digitalWrite(in5Pin, LOW);
}

void DcMoter2Stop(){
  digitalWrite(in6Pin, LOW);
  digitalWrite(in7Pin, LOW);
}

void DcMoter3Stop(){
  digitalWrite(in2Pin, LOW);
  digitalWrite(in8Pin, LOW);
}

void DcMoter4Stop(){
  digitalWrite(in12Pin, LOW);
  digitalWrite(in13Pin, LOW);
}


