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

Player player;
Ball[] balls_1;
Ball[] balls_2;
int numBalls = 5;

void setup() {
  size(800, 800);
  player = new Player(width / 2, height - 20, 20, 5, 3);
  balls_1 = new Ball[numBalls];
  balls_2 = new Ball[numBalls];

  for (int i = 0; i < numBalls; i++) {
    float x = random(width);
    float y = random(height / 2);
    float size = random(10, 30);
    float speedX = random(-2, 2);
    float speedY = random(-2, 2);
    balls_1[i]=new Ball(x, y, size, speedX, speedY);
  }
  for (int i = 0; i < numBalls; i++) {
    float x = random(width);
    float y = random(height / 2);
    float size = random(10, 30);
    float speedX = random(-2, 2);
    float speedY = random(-2, 2);
    balls_2[i]=new Ball(x, y, size, speedX, speedY);
  }
}

void draw() {
  background(220);
  player.move();
  player.display();

  for (Ball ball : balls_1) {
    ball.move();
    ball.display_1();
    if (player.checkCollision(ball)) {
      ball.x = random(width);
      ball.y = random(height / 2);
    }
  }
  for (Ball ball : balls_2) {
    ball.move();
    ball.display_2();
    if (player.checkCollision(ball)) {
      ball.x = random(width);
      ball.y = random(height / 2);
    }
  }

  fill(0);
  text("Lives: " + player.lives, 10, 20);

  if (player.lives <= 0) {
    text("Game Over", width / 2, height / 2);
    noLoop();
  }
}

void keyPressed() {
  if (key == 'r' || key == 'R') {
    resetGame();
  }
}

void resetGame() {
  player = new Player(width / 2, height - 20, 20, 5, 3);
  for (int i = 0; i < numBalls; i++) {
    float x = random(width);
    float y = random(height / 2);
    float size = random(10, 30);
    float speedX = random(-2, 2);
    float speedY = random(-2, 2);
  }
  loop();
}
