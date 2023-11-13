#include <Stepper.h>

// 스텝 모터의 핀 설정
const int in1Pin = 2;
const int in2Pin = 3;
const int in3Pin = 4;
const int in4Pin = 5;

// 스텝 모터의 단계 수와 속도 설정
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, in1Pin, in2Pin, in3Pin, in4Pin);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.setSpeed(100); // 속도 설정 (값을 조절하여 속도를 변경할 수 있습니다.)
  myStepper.step(stepsPerRevolution);
  delay(500);

  // 반시계 방향으로 1회전
  myStepper.setSpeed(100);
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
