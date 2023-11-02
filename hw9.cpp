Player player;
Ball[] balls_1;
Ball[] balls_2;
int numBalls = 5;

void setup() {
  size(400, 400);
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
