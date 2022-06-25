/**********循迹：引脚、变量**********/
#define TrackA1 27
#define TrackA2 29
#define TrackA3 31
#define TrackA4 33
#define TrackA5 35
#define TrackA6 37
//靠近vcc和gnd一端为1
#define TrackB1 39
#define TrackB2 41
#define TrackB3 43
#define TrackB4 45
#define TrackB5 47
#define TrackB6 49

boolean ta[6];//使用布尔值
boolean tb[6];//0白1黑
boolean PrvLight=0;

int CountRow=0,CountCol=0;//循迹行列计数和，用于检测是否经过黑线
int PrvCountRow=0,PrvCountCol=0;//前一次循迹行列计数和，用于确保每次经过黑线仅计一次数
int TrackStage=0;
/*车的方向*/
/*
轮C--------+--轮A
|   ↑ColB  |  |
|        联轴器| →初始位置到扫码区
|   →RowA |  |
轮D--------+--轮B
*/
/*


void Track(boolean FirstRow,int RLine,int CLine)
{//FirstRow：若输入1先走横，输入0先走竖
  TrackRead();
  TrackLine();
  if(FirstRow == true)
  {
    if(LineRow<abs(RLine))
    {//横向
      if(RLine>0)//正负对应前后走
      {Move(0,50);Motor();}
      else if(RLine<0)
      {Move(180,50);Motor();}
    }
    else if(LineCol<abs(CLine))
    {//竖向
      if(CLine>0)
      {Move(-90,50);Motor();}
      else if(CLine<0)
      {Move(90,50);Motor();}
    }
    else
    {MotorSTOP();LineRow=0;LineCol=0;}//停止，黑线计数清零
  }
  else if(FirstRow == false)
  {
    if(LineCol<abs(CLine))
    {//竖向
      if(CLine>0)//正负对应前后走
      {Move(-90,50);Motor();}
      else if(CLine<0)
      {Move(90,50);Motor();}
    }
    else if(LineRow<abs(RLine))
    {//横向
      if(RLine>0)
      {Move(0,50);Motor();}
      else if(RLine<0)
      {Move(180,50);Motor();}
    }
    else
    {MotorSTOP();LineRow=0;LineCol=0;}
  }
}

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
}


*/
