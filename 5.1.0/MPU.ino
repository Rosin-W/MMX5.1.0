float AKp = 0.2;//角度PID参数
float AKi = 0.000;
float AKd = 0.0;

float APrvErr = 0.0;//需要继承的几个PID参数
float ApidInt = 0.0;

void setup_MPU()
{
  JY901.StartIIC();//使用IIC通讯，也可以使用串口
}

void ReadMPU()
{//测算车体偏航角度（保持车体向前）
  JY901.GetAngle();//获取角度原始值
  BodyAngle = -(float)JY901.stcAngle.Angle[2]/32768*180;//计算Z轴旋转角度(顺时针)
}

void AngleCtrl()
{//角度控制，使车身保持向前（未调试）
  float ApidErr = BodyAngle;
  ApidInt = ApidInt + BodyAngle;
  float ApidDif = ApidErr - APrvErr;
  APrvErr = ApidErr;
  MotorPWMA -= AKp * ApidErr + AKi * ApidInt + AKd * ApidDif;
  MotorPWMC -= AKp * ApidErr + AKi * ApidInt + AKd * ApidDif;
}
