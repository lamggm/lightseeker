int angle_x = 90, right, left, diff_x;
extern const int tol;

void x_axis(void *parameter);

void x_axis(void *parameter) {

  servo_x.write(0);
  servo_x.write(180);
  servo_x.write(angle_x);

  while (1) {

    right = analogRead(R_ldrPin);
    left = analogRead(L_ldrPin);
    diff_x = right - left;

    if (diff_x > tol) {
      angle_x++;
    } else if (diff_x < (-tol)) {
      angle_x--;
    } else if (angle_x > 180) {
      angle_x = 180;
    } else if (angle_x < 0) {
      angle_x = 0;
    }

    servo_x.write(angle_x);
  }
}
