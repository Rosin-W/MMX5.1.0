/**********JY61P角度读取和车体角度控制**********/
float AKp = 0.0005;//角度PID参数
float AKi = 0.0000;
float AKd = 0.005;

float APrvErr = 0.0;//需要继承的几个PID参数
float ApidInt = 0.0;

float InitAngle = 0.0;//刚启动时的角度

void setup_MPU()
{
  //使用IIC通讯将会受到霍尔编码器的外部中断影响，使用sei()效果不佳
  Serial2.begin(9600);//使用串口通讯，JY61P的波特率为9600
}
void ReadInitMPU()
{//记录开关开启之前的角度，可使用901代替61P，且开启时不需要断电重置MPU
  BodyAngle = -((float)JY901.stcAngle.Angle[2]/32768*180);
  while (Serial2.available()) 
  {JY901.CopeSerialData(Serial2.read());}
}
void ReadMPU()
{//测算车体偏航角度(车启动时向前为正方向)
  BodyAngle = -((float)JY901.stcAngle.Angle[2]/32768*180)-InitAngle;//计算Z轴旋转角度(顺时针)
  while (Serial2.available()) 
  {JY901.CopeSerialData(Serial2.read());}
}

void AngleCtrl()
{//角度控制，使车身保持正位，可用于转向后
  ReadMPU();
  float ApidErr = BodyAngle-BaseAngle;
  ApidInt += ApidErr;
  float ApidDif = ApidErr - APrvErr;
  APrvErr = ApidErr;
  float ApidVal = AKp * ApidErr + AKi * ApidInt + AKd * ApidDif;
  MotorSpdA -= ApidVal;
  MotorSpdB += ApidVal;
  MotorSpdC -= ApidVal;
  MotorSpdD += ApidVal;
}

void Turn(float TurnToAngle)
{//车体自转
  ReadMPU();
  if(section==0)
  {
    BaseAngle=TurnToAngle;
    MotorSTOP();
    TrackZERO();
    stage++;
  }
  if(section==1)
  {MotorSTOP();delay(100);section++;}
  if(section==2)
  {
    if(abs(BodyAngle-TurnToAngle)>30)
    {
      if((BodyAngle-TurnToAngle)<0)//顺时针转
      {Move(360,CtrlSpd+10);}
      else//逆时针转
      {Move(-360,CtrlSpd+10);}
    }
    else if(abs(BodyAngle-TurnToAngle)>5)
    {
      if((BodyAngle-TurnToAngle)<0)//顺时针转
      {Move(360,CtrlSpd);}
      else//逆时针转
      {Move(-360,CtrlSpd);}
    }
    else
    {
      MotorSTOP();delay(100);
      if(abs(BodyAngle-TurnToAngle)<5)
      {section=0;}
    }
  }
}
