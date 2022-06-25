float GDistX = 0.0;//由树莓派获取
float GDistY = 0.0;

void DistanceCtrl()
{//位置微调，根据树莓派反馈摄像头数据进行位置调整，暂不用PID
  if(abs(GDistY-20)>0.1)
  {
    if(GDistY > 0)
    Move(0,30);
    else
    Move(180,30);
  }
  else if(GDistX > 100)
  {
    Move(90,30);
  }
}

float PrvGDistX = 0.0;
float PrvGDistY = 0.0;

void DistanceFilt()
{//对读取的数据进行滤波，极低配置卡尔曼滤波
  GDistX = GDistX*0.7 + PrvGDistX*0.3;
  GDistY = GDistY*0.7 + PrvGDistY*0.3;
  PrvGDistX = GDistX;
  PrvGDistY = GDistY;
  Serial.print("1");//接受完成的反馈
}
