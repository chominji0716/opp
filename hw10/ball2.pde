void pig(float x, float y,float z,float w){
  fill(255,145,203);
  triangle(x-1.8*z,y-6.3*z,x-7.2*z,y-1.8*z,x-5.4*z,y-10.8*z);
  triangle(x+1.8*z,y-6.3*z,x+7.2*z,y-1.8*z,x+5.4*z,y-10.8*z);//귀
  
  ellipse(x,y,z*18,w*18);//얼굴
  
  fill(239,136,190);
  ellipse(x,y+2.7*z,5.4*z,3.6*z);
  fill(255,145,203);
  arc(x,y+5.4*z,5.4*z,3.6*z,0,PI);//코,입
  
  fill(219,125,174);
  circle(x-0.9*z,y+2.592*z,0.9*z);
  circle(x+0.9*z,y+2.592*z,0.9*z);//콧구멍
  
  fill(0,0,0);
  circle(x-3.6*z,y-3.6*z,1.8*z);
  circle(x+3.6*z,y-3.6*z,1.8*z);//눈
}
