class Ball {
  float x, y;
  float size;
  float speedX, speedY;

  Ball(float x, float y, float size, float speedX, float speedY) {
    this.x = x;
    this.y = y;
    this.size = size;
    this.speedX = speedX;
    this.speedY = speedY;
  }

  void move() {
    x += speedX;
    y += speedY;

    if (x < 0 || x > width) {
      speedX *= -1;
    }
    if (y < 0 || y > height) {
      speedY *= -1;
    }
  }

  void display_1() {
    local_face(x, y, 2);
  }
  void display_2() {
    pig(x, y, 0.8, 0.8);
  }
}
