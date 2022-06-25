/**********6路*2块循迹检测及判断**********/
#include "TrackPin.h"

void setup_Track()
{
  pinMode(TrackA1,INPUT);
  pinMode(TrackA2,INPUT);
  pinMode(TrackA3,INPUT);
  pinMode(TrackA4,INPUT);
  pinMode(TrackA5,INPUT);
  pinMode(TrackA6,INPUT);
  pinMode(TrackB1,INPUT);
  pinMode(TrackB2,INPUT);
  pinMode(TrackB3,INPUT);
  pinMode(TrackB4,INPUT);
  pinMode(TrackB5,INPUT);
  pinMode(TrackB6,INPUT);
}

void TrackRead()
{
  ta[0]= (digitalRead(TrackA1));
  ta[1]= (digitalRead(TrackA2));
  ta[2]= (digitalRead(TrackA3));
  ta[3]= (digitalRead(TrackA4));
  ta[4]= (digitalRead(TrackA5));
  ta[5]= (digitalRead(TrackA6));
  tb[0]= (digitalRead(TrackB1));
  tb[1]= (digitalRead(TrackB2));
  tb[2]= (digitalRead(TrackB3));
  tb[3]= (digitalRead(TrackB4));
  tb[4]= (digitalRead(TrackB5));
  tb[5]= (digitalRead(TrackB6));
  ta0=ta[0];tb2=tb[2];
}

void TrackLine()
{//循迹对经过的横竖线的计数
  PrvCountRow = CountRow;//先对前一次赋值，再计算本次计数和
  PrvCountCol = CountCol;
  CountRow = ta[0]+ta[1]+ta[2]+ta[3]+ta[4]+ta[5];
  CountCol = tb[0]+tb[1]+tb[2]+tb[3]+tb[4]+tb[5];
  //驶出黑线时，前一瞬间4个及以上灯为黑且后一瞬间3个及以下灯为黑，即为黑线判定
  if((PrvCountRow>4)&&(CountRow<=4))
  {LineRow++;}
  if((PrvCountCol>4)&&(CountCol<=4))
  {LineCol++;}
}

void TrackZero()
{//黑线计数清零，行走阶段清零
  LineCol=0;
  LineRow=0;
  TrackStage=0;
  PrvLightMove=0;
}
void Straight()
{
  TrackRead();
//  ReadMPU();
//  AngleCtrl();
  int value=5*ta[0]+2*ta[1]+ta[2]-ta[3]-2*ta[4]-5*ta[5];
  /*if(value>0)//偏左
  {Move(-30,15);}
  else if(value<0)//偏右
  {Move(30,15);}
  else
  {Move(0,15);}*/
//  Move((-5*value),30);
  Move(0,30);
  Motor();
}
void TrackR(int RLine,int CLine)
{//四向走格子
  //FirstRow：若输入1先走横，输入0先走竖
  TrackRead();
  TrackLine();
  if(LineRow<abs(RLine))//横向
  {Move((90-90*(RLine/abs(RLine))),50);}//直接计算角度，不需要判断方向
  else if(LineCol<abs(CLine))//竖向
  {Move((0-90*(CLine/abs(CLine))),50);}
  else
  {MotorSTOP();stage++;TrackZero();}//停止，黑线计数清零
  Motor();
}
void TrackC(int RLine,int CLine)
{//四向走格子
  //FirstRow：若输入1先走横，输入0先走竖
  TrackRead();
  TrackLine();
  if(LineCol<abs(CLine))
  {Move((0-90*(CLine/abs(CLine))),50);}
  else if(LineRow<abs(RLine))
  {Move((90-90*(RLine/abs(RLine))),50);}
  else
  {MotorSTOP();stage++;TrackZero();}
  Motor();
}/*
void TrackFree(float MoveAngle,float basespeed,int RLine,int CLine,boolean StopLightRow,int StopLight)
{//指定位置和速度移动，定点停车
  //指定方向速度移动，半精调需要判断正负，不需要先后
  TrackRead();
  TrackLine();
  if(TrackStage==0)
  {//粗调，指定方向全向移动
    if((LineRow<abs(RLine))&&(LineCol<abs(CLine)))
    {Move(MoveAngle,basespeed);}
    else 
    {TrackStage++;}
  }
  if(TrackStage==1)
  {//半精调，列达到预期值而行未达到（或相反情况）时进行四向移动
    if(LineRow<abs(RLine))
    {Move((90-90*(RLine/abs(RLine))),30);}
    else if(LineCol<abs(CLine))
    {Move((0-90*(CLine/abs(CLine))),30);}
    else
    {TrackStage++;}
  }
  if(TrackStage==2)
  {//精调
    if(StopLightRow==true)
    {
      if((ta[StopLight]==1)&&(PrvLight==0))//进入黑线时判断
      {MotorSTOP();}
      else 
      {Move(-90,15);TrackStage++;}
      PrvLight=ta[StopLight];
    }
    else
    {
      if((tb[StopLight]==1)&&(PrvLight==0))
      {MotorSTOP();TrackStage++;}
      else 
      {Move(0,15);}
      PrvLight=tb[StopLight];
    }
    if(TrackStage==3)
    {MotorSTOP();stage++;}
    Motor();
  }
}*/
/*↑为什么MotorPWM起调量在这里会出问题？和判断方向的boolean FirstRow有关*/
/*线走完后不要立刻STOP，按PID开始调整，惯性滑行一段，抵消刚起步时方向偏移*/
