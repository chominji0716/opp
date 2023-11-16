float [] x1, x2, y1, y2, vx1, vx2, vy1, vy2;
float x, y;
float a1, b1, a2, b2, a3, b3, a4, b4, a5, b5, a6, b6;
float textOn;

void setup() {
  size(800, 600);
  x = 100;
  y = 50;
  textOn = 0;
  x1 = new float[3];
  x2 = new float[3];
  y1 = new float[3];
  y2 = new float[3];
  vx1 = new float[3];
  vx2 = new float[3];
  vy1 = new float[3];
  vy2 = new float[3];
  for (int i=0; i<3; i++) {
    x1[i] = random(width);
    y1[i] = random(height);
    x2[i] = random(width);
    y2[i] = random(height);
    vx1[i] = random(-4, 4);
    vy1[i] = random(-3, 3);
    vx2[i] = random(-4, 4);
    vy2[i] = random(-3, 3);
  }
}

void draw() {
  background(255, 255, 255);
  wall(200, 0, 10); //장애물1
  wall(500, 300, 10); //장애물2
  star(700, 500, 2);

  if (keyPressed) {
    if (key == 'd') x += 5;
    else if (key == 'a') x -= 5;
    else if (key == 'w') y -= 5;
    else if (key == 's') y += 5;
    else if (key == 'e') {
      x += 5;
      y -=5;
    } else if (key == 'q') {
      x -= 5;
      y -=5;
    } else if (key == 'z') {
      x -= 5;
      y +=5;
    } else if (key == 'x') {
      x += 5;
      y +=5;
    }
  } //키 조작하기
  mych(x, y, 2); //주인공

  for (int i=0; i<3; i++) {
    x1[i] += vx1[i];
    y1[i] += vy1[i];
    x2[i] += vx2[i];
    y2[i] += vy2[i];
    ghost(x1[i], y1[i], 2);
    cuby(x2[i], y2[i], 2);
    if (x1[i]<0 || x1[i]>width) vx1[i] = -vx1[i];
    if (y1[i]<0 || y1[i]>height) vy1[i] = -vy1[i];
    if (x2[i]<0 || x2[i]>width) vx2[i] = -vx2[i];
    if (y2[i]<0 || y2[i]>height) vy2[i] = -vy2[i];
    a1 = x1[0];
    a2 = x1[1];
    a3 = x1[2];
    a4 = x2[0];
    a5 = x2[1];
    a6 = x2[2];
    b1 = y1[0];
    b2 = y1[1];
    b3 = y1[2];
    b4 = y2[0];
    b5 = y2[1];
    b6 = y2[2];
  } //몬스터들의 움직임

  if (x<20 || x>width-20) {
    textOn=1;
    if (textOn==1) {
      background(0);
      fill(255, 0, 0);
      textSize(90);
      text("Game Over!", 200, 300);
      fill(255, 255, 255);
      textSize(30);
      text("Press 'R' key to replay the game.", 200, 400);
      if (keyPressed) {
        if (key=='r') {
          textOn=0;
          x=100;
          y=50;
        }
      }
    }
  }
  if (y<20 || y>height-80 || (x>190)&&(x<310)&&(y>0)&&(y<310)|| (x>490)&&(x<610)&&(y>220)) {
    textOn=1;
    if (textOn==1) {
      background(0);
      fill(255, 0, 0);
      textSize(90);
      text("Game Over!", 200, 300);
      fill(255, 255, 255);
      textSize(30);
      text("Press 'R' key to replay the game.", 200, 400);
      if (keyPressed) {
        if (key=='r') {
          textOn=0;
          x=100;
          y=50;
        }
      }
    }
  }
  collide(a1, b1);
  collide(a2, b2);
  collide(a3, b3);
  collide(a4, b4);
  collide(a5, b5);
  collide(a6, b6);
  complete(700, 500);
}

void mych(float x, float y, float d) {
  fill(255, 255, 255);
  stroke(0);
  circle(x, y, 20*d);
  fill(255, 255, 255);
  stroke(0);
  fill(0);
  circle(x-3*d, y-2*d, 3*d);
  fill(0);
  circle(x+3*d, y-2*d, 3*d);
  fill(255, 255, 255);
  arc(x, y+5*d, 9*d, 5*d, PI, 2*PI);
  fill(255, 255, 255);
  line(x, y+10*d, x, y+30*d);
  line(x, y+15*d, x-10*d, y+20*d);
  line(x, y+15*d, x+10*d, y+20*d);
  line(x, y+30*d, x-10*d, y+40*d);
  line(x, y+30*d, x+10*d, y+40*d);
  fill(0, 0, 255);
  ellipse(x-10*d, y+40*d, 5*d, 3*d);
  ellipse(x+10*d, y+40*d, 5*d, 3*d);
} //주인공 함수

void ghost(float x, float y, float d) {
  fill(255, 255, 255);
  stroke(0, 240, 255);
  arc(x, y, d*24, d*35, PI, 2*PI);
  fill(0);
  stroke(0);
  arc(x-5*d, y-9*d, d*2, d*5, PI, 4*PI);
  fill(0);
  stroke(0);
  arc(x+5*d, y-9*d, d*2, d*5, PI, 4*PI);
  fill(0, 240, 255);
  stroke(0, 240, 255);
  arc(x-9*d, y+1, d*6, d*4, PI, 2*PI);
  fill(0, 240, 255);
  stroke(0, 240, 255);
  arc(x-3*d, y+1, d*6, d*4, PI, 2*PI);
  fill(0, 240, 255);
  stroke(0, 240, 255);
  arc(x+3*d, y+1, d*6, d*4, PI, 2*PI);
  fill(0, 240, 255);
  stroke(0, 240, 255);
  arc(x+9*d, y+1, d*6, d*4, PI, 2*PI);
} //몬스터1 함수

void cuby(float x, float y, float d) {
  fill(255, 173, 182);
  stroke(255, 173, 182);
  circle(x, y, 30*d);
  fill(240, 0, 0);
  stroke(240, 0, 0);
  ellipse(x+8*d, y+14*d, 15*d, 7*d);
  ellipse(x-8*d, y+14*d, 15*d, 7*d);
  fill(77, 84, 255);
  stroke(77, 84, 255);
  ellipse(x+4*d, y-6*d, 5*d, 9*d);
  ellipse(x-4*d, y-6*d, 5*d, 9*d);
  fill(9, 7, 142);
  stroke(9, 7, 142);
  ellipse(x+4*d, y-7*d, 3.5*d, 7*d);
  ellipse(x-4*d, y-7*d, 3.5*d, 7*d);
  fill(255, 255, 255);
  stroke(255, 255, 255);
  ellipse(x+4*d, y-8.3*d, 2*d, 4*d);
  ellipse(x-4*d, y-8.3*d, 2*d, 4*d);
  fill(237, 86, 126);
  stroke(237, 86, 126);
  ellipse(x+8*d, y+2*d, 5*d, 3*d);
  ellipse(x-8*d, y+2*d, 5*d, 3*d);
  fill(175, 9, 39);
  stroke(175, 9, 39);
  arc(x, y+3*d, 7*d, 10*d, 0, PI);
} //몬스터2 함수

void collide(float a, float b) {
  float dx = a - x;
  float dy = b - y -60;
  float d = sqrt(dx*dx+dy*dy);
  if (d<40) {
    x=100;
    y=50;
  }
}

void complete(float a, float b) {
  float dx = a - x;
  float dy = b - y -60;
  float d = sqrt(dx*dx+dy*dy);
  if (d<30) {
    background(0);
    fill(0, 0, 255);
    textSize(80);
    text("Game Complete!", 100, 300);
    fill(255,255,255);
      textSize(30);
      text("Press 'R' key to replay the game.",200,400);
      if (keyPressed) {
        if (key=='r') {
          textOn=0;
          x=100;
          y=50;
        }
      }
  }
}

void wall(float x, float y, float d) {
  fill(0, 0, 255);
  stroke(0, 0, 255);
  rect(x, y, 10*d, 30*d);
} //장애물 함수

void star(float x, float y, float d) {
  beginShape();
  fill(255, 255, 0);
  stroke(255, 255, 0);
  vertex(x, y-25*d);
  vertex(x+5*d, y-10*d);
  vertex(x+20*d, y-10*d);
  vertex(x+10*d, y);
  vertex(x+15*d, y+15*d);
  vertex(x, y+7*d);
  vertex(x-15*d, y+15*d);
  vertex(x-10*d, y);
  vertex(x-20*d, y-10*d);
  vertex(x-5*d, y-10*d);
  endShape();
}
