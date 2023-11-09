void cuby(float x, float y, float d){
  fill(255, 173, 182);
  stroke(255, 173, 182);
  circle(x, y, 30*d); //얼굴
  
  fill(240, 0, 0);
  stroke(240, 0, 0);
  ellipse(x+8*d, y+14*d, 15*d, 7*d); //오른쪽 다리
  ellipse(x-8*d, y+14*d, 15*d, 7*d); // 왼쪽 다리
  
  fill(77, 84, 255);
  stroke(77, 84, 255);
  ellipse(x+4*d, y-6*d, 5*d, 9*d); //큰 오른쪽 눈
  ellipse(x-4*d, y-6*d, 5*d, 9*d); //큰 왼쪽 눈
 fill(9,7,142);
  stroke(9,7,142);
  ellipse(x+4*d, y-7*d, 3.5*d, 7*d); //중간 오른쪽 눈
  ellipse(x-4*d, y-7*d, 3.5*d, 7*d); //중간 왼쪽 눈
  
  fill(255, 255, 255);
  stroke(255, 255, 255);
  ellipse(x+4*d, y-8.3*d, 2*d, 4*d); // 작은 오른쪽 눈
  ellipse(x-4*d, y-8.3*d, 2*d, 4*d); //작은 왼쪽 눈
  
  fill(237, 86, 126);
  stroke(237, 86, 126);
  ellipse(x+8*d, y+2*d, 5*d, 3*d); //오른쪽 볼
  ellipse(x-8*d, y+2*d, 5*d, 3*d); //왼쪽 볼
  
  fill(175, 9, 39);
  stroke(175, 9, 39);
  arc(x, y+3*d, 7*d, 10*d, 0, PI); //입
}
