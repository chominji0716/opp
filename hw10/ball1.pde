void local_face(float x, float y, float d){ //지역변수 그림
  local_mask(x, y, d);
  local_nose(x, y, d);
  local_eye(x, y, d);
  local_mouse(x, y, d);
}
void local_mask(float x, float y, float d){
  stroke(0, 0, 0);
  strokeWeight(3);
  circle(x,y,d*18);
  strokeWeight(1);
}
void local_nose(float x, float y, float d){
  strokeWeight(1);
  arc(x, y+1.5*d, d*4, d*6, 0.4*PI, 1.4*PI);
  strokeWeight(4);
  point(x, y+3*d);
  point(x-d, y+3*d);
}
void local_mouse(float x, float y, float d){
  strokeWeight(1);
  fill(255);
  line(x-4*d, y+6*d, x+4*d, y+6*d);
}
void local_eye(float x, float y, float d){
  strokeWeight(1);
  line(x-2*d, y-4*d, x-5*d, y-5*d);
  line(x+2*d, y-4*d, x+5*d, y-5*d);
  strokeWeight(1);
  ellipse(x-4*d, y-2*d, d*3.5, d*2.5);
  ellipse(x+4*d, y-2*d, d*3.5, d*2.5);
  fill(0);
  circle(x-4*d, y-2*d, d*2);
  circle(x+4*d, y-2*d, d*2);
}
