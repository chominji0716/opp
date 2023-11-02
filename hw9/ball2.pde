void pig(float x, float y,float z,float w){
  fill(255,145,203);
  triangle(x-5*z,y-17.5*z,x-20*z,y-5*z,x-15*z,y-30*z);
  triangle(x+5*z,y-17.5*z,x+20*z,y-5*z,x+15*z,y-30*z);//귀
  
  ellipse(x,y,z*50,w*50);//얼굴
  
  fill(239,136,190);
  ellipse(x,y+7.5*z,15*z,10*z);
  fill(255,145,203);
  arc(x,y+15*z,15*z,10*z,0,PI);//코,입
  
  fill(219,125,174);
  circle(x-2.5*z,y+7.2*z,2.5*z);
  circle(x+2.5*z,y+7.2*z,2.5*z);//콧구멍
  
  fill(0,0,0);
  circle(x-10*z,y-10*z,5*z);
  circle(x+10*z,y-10*z,5*z);//눈
}
