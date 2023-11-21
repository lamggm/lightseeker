#include <ESP32Servo.h>

Servo servo_x;
Servo servo_y;

int servo_xPin = 32;
int servo_yPin = 33;

int L_ldrPin = 36;
int R_ldrPin = 39;
int U_ldrPin = 34;
int D_ldrPin = 35;

const int tol = 100;

TaskHandle_t x_Axis;
TaskHandle_t y_Axis;

extern void x_axis(void *parameter);
extern void y_axis(void *parameter);


void setup() {

  pinMode(L_ldrPin, INPUT);
  pinMode(R_ldrPin, INPUT);
  pinMode(U_ldrPin, INPUT);
  pinMode(D_ldrPin, INPUT);
  servo_x.attach(servo_xPin);
  servo_y.attach(servo_yPin);

  xTaskCreatePinnedToCore(x_axis, "x_Axis", 10000, NULL, 1, &x_Axis, 0);
  delay(500);
  xTaskCreatePinnedToCore(y_axis, "y_Axis", 10000, NULL, 1, &y_Axis, 1);
  delay(500);
}

void loop() {}
