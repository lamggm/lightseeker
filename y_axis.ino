int angle_y = 90, up, down, diff_y;
extern const int tol;

void y_axis(void *parameter);

void y_axis(void *parameter) {

  servo_y.write(0);
  servo_y.write(180);
  servo_y.write(angle_y);

  while (1) {

    up = analogRead(R_ldrPin);
    down = analogRead(L_ldrPin);
    diff_y = up - down;

    if (diff_y > tol) {
      angle_y++;
    } else if (diff_y < (-tol)) {
      angle_y--;
    } else if (angle_y > 180) {
      angle_y = 180;
    } else if (angle_y < 0) {
      angle_y = 0;
    }

    servo_y.write(angle_y);
  }
}
