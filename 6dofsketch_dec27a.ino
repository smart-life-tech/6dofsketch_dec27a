
#include <Servo.h>
#include <Wire.h>
#include <PS2X_lib.h>
#include <Adafruit_MS_PWMServoDriver.h>
#include "QGPMaker_MotorShield.h"
#include "QGPMaker_Encoder.h"

long ARM_MIN[]={10, 10, 10, 10};

long ARM_MAX[]={170, 170, 170, 170};

Servo servo_A0;
Servo servo_A1;
Servo servo_A2;
Servo servo_A3;
Servo servo_A4;
Servo servo_A5;

void forward() {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  Serial.println("f");
}


QGPMaker_MotorShield AFMS = QGPMaker_MotorShield();
PS2X ps2x;
void back() {
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  Serial.println("b");
}

void left() {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  Serial.println("l");
}

void turn_left() {
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  Serial.println("l");
}

void right() {
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  Serial.println("r");
}

void turn_right() {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  Serial.println("r");
}

void stop() {
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
}

void setup(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  AFMS.begin(50);

  int error = 0;
  do{
    error = ps2x.config_gamepad(13,11,10,12, true, true);
    if(error == 0){
      break;
    }else{
      delay(100);
    }
  }while(1);
  for(size_t i = 0; i < 50; i++)
  {
        ps2x.read_gamepad(false, 0);
        delay(10);
  }

  servo_A0.attach(A0);
  servo_A1.attach(A1);
  servo_A2.attach(A2);
  servo_A3.attach(A3);
  servo_A4.attach(A4);
  servo_A5.attach(A5);
}

void loop(){
  ps2x.read_gamepad(false, 0);
  delay(3);
  if (ps2x.Button(PSB_PAD_UP)) {
    forward();

  } else if (ps2x.ButtonReleased(PSB_PAD_UP)) {
    stop();
  }
  if (ps2x.Button(PSB_PAD_DOWN)) {
    back();

  } else if (ps2x.ButtonReleased(PSB_PAD_DOWN)) {
    stop();
  }
  if (ps2x.Button(PSB_PAD_LEFT)) {
    left();

  } else if (ps2x.ButtonReleased(PSB_PAD_LEFT)) {
    stop();
  }
  if (ps2x.Button(PSB_PAD_RIGHT)) {
    right();

  } else if (ps2x.ButtonReleased(PSB_PAD_RIGHT)) {
    stop();
  }
  if (ps2x.Button(PSB_SQUARE)) {
    turn_left();

  } else if (ps2x.ButtonReleased(PSB_SQUARE)) {
    stop();
  }
  if (ps2x.Button(PSB_CIRCLE)) {
    turn_right();

  } else if (ps2x.ButtonReleased(PSB_CIRCLE)) {
    stop();
  }
  if (ps2x.Button(PSB_CROSS)) {
    ps2x.read_gamepad(true, 200);
    delay(300);
    ps2x.read_gamepad(false, 0);

  }
  //左边摇杆x
  if (ps2x.Analog(PSS_LX) > 150) {
    servo_A0.write((servo_A0.read() + 1));
    delay(0);

  }
  if (ps2x.Analog(PSS_LX) < 90) {
    servo_A0.write((servo_A0.read() - 1));
    delay(0);

  }
  Serial.println(ps2x.Analog(PSS_RY));
  delay(10);
  //左边摇杆y
  if (ps2x.Analog(PSS_LY) > 135) {
    servo_A1.write((servo_A1.read() + 1));
    delay(0);

  }
  if (ps2x.Analog(PSS_LY) < 120) {
    servo_A1.write((servo_A1.read() - 1));
    delay(0);

  }
  //右边摇杆x
  if (ps2x.Analog(PSS_RX) > 135) {
    servo_A2.write((servo_A2.read() + 1));
    delay(0);

  }
  if (ps2x.Analog(PSS_RX) < 120) {
    servo_A2.write((servo_A2.read() - 1));
    delay(0);

  }
  //右边摇杆y
  if (ps2x.Analog(PSS_RY) > 135) {
    servo_A3.write((servo_A3.read() + 1));
    delay(0);

  }
  if (ps2x.Analog(PSS_RY) < 105) {
    servo_A3.write((servo_A3.read() - 1));
    delay(0);

  }
  if (ps2x.Button(PSB_L1)) {
    servo_A4.write((servo_A4.read() + 1));
    delay(0);

  }
  if (ps2x.Button(PSB_R1)) {
    servo_A4.write((servo_A4.read() - 1));
    delay(0);

  }
  if (ps2x.Button(PSB_L2)) {
    servo_A5.write((servo_A5.read() + 1));
    delay(0);

  }
  if (ps2x.Button(PSB_R2)) {
    servo_A5.write((servo_A5.read() - 1));
    delay(0);

  }

}
