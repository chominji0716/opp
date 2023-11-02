class Player {
  float x, y;
  float size;
  float speed;
  int lives;

  Player(float x, float y, float size, float speed, int lives) {
    this.x = x;
    this.y = y;
    this.size = size;
    this.speed = speed;
    this.lives = lives;
  }

  void move() {
    if (keyPressed) {
      if (key == 'a' && x > 0) {
        x -= speed;
      } else if (key == 'd' && x < width - size) {
        x += speed;
      }
      if (key == 'w' && y > 0) {
        y -= speed;
      } else if (key == 's' && y < height - size) {
        y += speed;
      }
    }
  }

  void display() {
    cuby(x, y, size/18);
  }

  boolean checkCollision(Ball ball) {
    float distance = dist(x, y, ball.x, ball.y);
    if (distance < (size*2 + ball.size) / 2) {
      lives--;
      return true;
    }
    return false;
  }
}
