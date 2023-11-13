#include <Stepper.h>

// 스텝 모터의 핀 설정
const int in1Pin = 2;
const int in2Pin = 3;
const int in3Pin = 4;
const int in4Pin = 5;

const int in8Pin = 8;
const int in9Pin = 9;
const int in10Pin = 10;
const int in11Pin = 11;


// 스텝 모터의 단계 수와 속도 설정
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, in1Pin, in2Pin, in3Pin, in4Pin);
Stepper myStepper2(stepsPerRevolution, in8Pin, in9Pin, in10Pin, in11Pin);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SettingDC();
}



void loop() {
  // put your main code here, to run repeatedly:
  
  int i=1;

  do{
  analogWrite(5,255);
  delay(200);
  analogWrite(5,0);
  delay(200);
  }while(i!=1);

}

void StepMotoerFunc() {
  myStepper.setSpeed(100); // 속도 설정 (값을 조절하여 속도를 변경할 수 있습니다.)
  myStepper.step(stepsPerRevolution);
  delay(500);

  // 반시계 방향으로 1회전
  myStepper.setSpeed(100);
  myStepper.step(-stepsPerRevolution);
  delay(500);

  myStepper2.setSpeed(50); // 속도 설정 (값을 조절하여 속도를 변경할 수 있습니다.)
  myStepper2.step(stepsPerRevolution);
  delay(500);

  // 반시계 방향으로 1회전
  myStepper2.setSpeed(50);
  myStepper2.step(-stepsPerRevolution);
  delay(500);
}

void SettingDC(){
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void DcMoterFunc()
{
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(2000);
  digitalWrite(5,HIGH);
  digitalWrite(6, LOW);
  delay(2000);
}