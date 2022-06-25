/**********过程测试**********/
void debugAction()
{//动作测试，DEBUG用
  CSB();
  CSBRead();
  Serial.println(Distance);
}

/**************************************************************************/
void testAction()
{
  if(part ==  0)/************启动************/
  {//启动
    if(index ==  0 )
    {Switch();}
  }
  if(part ==  1)/************扫码************/
  {
    if(index ==  0 )
    {
      if(stage==0){TrackL(2);}
      if(stage==1){TrackF(2);}
      if(stage==2){Turn(-90);}
      if(stage==3){TrackL(2);}
      if(stage==4){TrackB(2);}
      if(stage==5){Turn(90);}
      if(stage==6){indexADD();}
    }
    if(index ==  1 )
    {MotorSTOP();}
  }
}
  /*
}
  if(index==0)
  {//等待树莓派上电
    index=1;//完成上电后通过流程开关来开启，取消固定等待时间
  }
  if(index==1)
  {//扫码，与树莓派通讯
    Serial.print("(s)");//扫码
    i = Serial.parseInt();
    delay(10);n++;
    if((i==12)||(i==13)||(i==23))
    {n=0;index++;}
    if(n>wait)
    {i=12;n=0;index++;}
  }
  if(index==2)
  {
    delay(100);n++;
    if(i==12)//红绿
    {Serial3.print('3');}
    if(i==13)//红蓝
    {Serial3.print('4');}
    if(i==23)//绿蓝
    {Serial3.print('5');}
    if((Serial3.available())||(n>5))
    {n=0; index++; }
  }
  if(index==3)
  {//物料一区第一物块识别抓取
    Serial.print("(a)");
    i = Serial.parseInt();
    delay(20);n++;
    if(i==1||n>wait)//收到信号或15秒未响应之后
    {n=0;delay(2000);index++;}
  }
  if(index==4)
  {//物料一区第二物块识别抓取
    Serial.print("(z)");
    i = Serial.parseInt();
    delay(20);n++;
    if(i==2||n>wait)
    {n=0;delay(2000);index++;}
  }
  if(index==5)
  {//物料一区第三物块
    Serial.print("(c)");
    i = Serial.parseInt();
    delay(20);n++;
    if(i==3||n>wait)
    {n=0;delay(2000);index++;}
  }
  if(index==6)
  {//物料二区第一物块
    Serial.print("(d)");
    i = Serial.parseInt();
    delay(20);n++;
    if(i==4||n>wait)
    {n=0;delay(2000);index++;}
  }
  if(index==7)
  {//物料二区第二物块
    Serial.print("(e)");
    i = Serial.parseInt();
    delay(20);n++;
    if(i==5||n>wait)
    {n=0;delay(2000);index++;}
  }
  if(index==8)
  {//物料二区第三物块
    Serial.print("(f)");
    i = Serial.parseInt();
    delay(20);n++;
    if(i==6||n>wait)
    {n=0;delay(2000);index++;}
  }
  if(index==9)
  {MotorSTOP();}
}*/
