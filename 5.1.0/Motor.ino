/*****************************电机及PID*********************************/
/*电机相关引脚定义*/
/*!!!注意P9P10口*/
int PWMA1 = 12;  
int PWMA2 = 13;
int PWMB1 = 11;  
int PWMB2 = 8;
int PWMC1 = 6;
int PWMC2 = 7;
int PWMD1 = 5; 
int PWMD2 = 4;

/*电机PID相关参数定义*/
float MKp = 0.05;
float MKi = 0.0002;
float MKd = 0.5;

float MPrvErrA = 0.0;//需要继承的几个PID参数
float MpidIntA = 0.0;
float MPrvErrB = 0.0;
float MpidIntB = 0.0;
float MPrvErrC = 0.0;
float MpidIntC = 0.0;
float MPrvErrD = 0.0;
float MpidIntD = 0.0;

void setup_motor()
{//电机输出初始化
  pinMode(PWMA1,OUTPUT);
  pinMode(PWMA2,OUTPUT);
  pinMode(PWMB1,OUTPUT);
  pinMode(PWMB2,OUTPUT);
  pinMode(PWMC1,OUTPUT);
  pinMode(PWMC2,OUTPUT);
  pinMode(PWMD1,OUTPUT);
  pinMode(PWMD2,OUTPUT);
}

void Motor()
{
//  SpeedExchange();
  MotorPWM(MotorPWMA,MotorPWMB,MotorPWMC,MotorPWMD);
//  MotorPID(MotorA,spdA,MpidIntA,MPrvErrA,MotorPWMA);//尝试用函数，未果
  MotorPIDA();
  MotorPIDB();
  MotorPIDC();
  MotorPIDD();
}

void MotorPWM(int pwm1,int pwm2,int pwm3,int pwm4)
{//电机PWM输出，定义向前为正转
  if(pwm1 > 0)    {analogWrite(PWMA1,pwm1);analogWrite(PWMA2,0);}
  else              {analogWrite(PWMA1,0);analogWrite(PWMA2,-pwm1);}
  if(pwm2 > 0)    {analogWrite(PWMB1,0);analogWrite(PWMB2,pwm2);}
  else              {analogWrite(PWMB1,-pwm2);analogWrite(PWMB2,0);}
  if(pwm3 > 0)    {analogWrite(PWMC1,pwm3);analogWrite(PWMC2,0);}
  else              {analogWrite(PWMC1,0);analogWrite(PWMC2,-pwm3);}
  if(pwm4 > 0)    {analogWrite(PWMD1,0);analogWrite(PWMD2,pwm4);}
  else              {analogWrite(PWMD1,-pwm4);analogWrite(PWMD2,0);}
}

void MotorPIDA()
{//PID控制程序，下同
  float MpidErrA = MotorA - spdA;    //比例Proportion
  MpidIntA += MpidErrA;               //积分Integration
  float MpidDifA = MpidErrA - MPrvErrA;//微分Differential
  MotorPWMA += MKp*MpidErrA + MKi*MpidIntA + MKd*MpidDifA;
  MPrvErrA = MpidErrA;
  if (MotorPWMA > 150) {MotorPWMA = 150;}//将PWM值限定
  if (MotorPWMA < -150) {MotorPWMA = -150;}
}

void MotorPIDB()
{
  float MpidErrB = MotorB - spdB;
  MpidIntB += MpidErrB;
  float MpidDifB = MpidErrB - MPrvErrB;
  MotorPWMB += MKp*MpidErrB + MKi*MpidIntB + MKd*MpidDifB;
  MPrvErrB = MpidErrB;
  if (MotorPWMB > 150) {MotorPWMB = 150;}
  if (MotorPWMB < -150) {MotorPWMB = -150;}
}
void MotorPIDC()
{
  float MpidErrC = MotorC - spdC;
  MpidIntC += MpidErrC;
  float MpidDifC = MpidErrC - MPrvErrC;
  MotorPWMC += MKp*MpidErrC + MKi*MpidIntC + MKd*MpidDifC;
  MPrvErrC = MpidErrC;
  if (MotorPWMC > 150) {MotorPWMC = 150;}
  if (MotorPWMC < -150) {MotorPWMC = -150;}
}
void MotorPIDD()
{
  float MpidErrD = MotorD - spdD;
  MpidIntD += MpidErrD;
  float MpidDifD = MpidErrD - MPrvErrD;
  MotorPWMD += MKp*MpidErrD + MKi*MpidIntD + MKd*MpidDifD;
  MPrvErrD = MpidErrD;
  if (MotorPWMD > 150) {MotorPWMD = 150;}
  if (MotorPWMD < -150) {MotorPWMD = -150;}
}

/*void MotorPID(float Motor, float spd, float MpidInt, float MPrvErr,float MotorPWM)
{//PID控制程序（可实现P闭环，待调试）
  float MpidErr = Motor - spd;
  MpidInt += MpidErr;
  float MpidDif = MpidErr - MPrvErr;
  MotorPWM += MKp*MpidErr + MKi*MpidInt + MKd*MpidDif;
  MPrvErr = MpidErr;
  if (MotorPWM > 150) {MotorPWM = 150;}
  if (MotorPWM < -150) {MotorPWM = -150;}
  return MotorPWM,MPrvErr;
}*/
float PrvMA = 0;
float PrvMB = 0;
float PrvMC = 0;
float PrvMD = 0;
void SpeedExchange()
{//当预设速度发生较大改变时，改变PWMPID初始值，有助快速响应
  if((PrvMA-MotorA)>10)
  {MotorPWMA = MotorA / 2;}
  if((PrvMB-MotorB)>10)
  {MotorPWMB = MotorB / 2;}
  if((PrvMC-MotorC)>10)
  {MotorPWMC = MotorC / 2;}
  if((PrvMD-MotorD)>10)
  {MotorPWMD = MotorD / 2;}
  PrvMA = MotorA;
  PrvMB = MotorB;
  PrvMC = MotorC;
  PrvMD = MotorD;
}
/*****************************编码器测速**********************************/
/*编码器相关引脚定义*/
/*注意：MEGA外部中断引脚号：2，3，21，20，19，18，分别对应interrupt0~5
编码器A相需要接中断引脚*/
#define EncA 3 //编码器A相  
#define DirA 26//编码器B相
#define EncB 2  
#define DirB 25
#define EncC 18
#define DirC 24 
#define EncD 19 
#define DirD 23

/*编码器测速相关参数定义*/
float countA = 0;//计数，由于需要计算speed是浮点型，故此处不能用整型
float countB = 0;
float countC = 0;
float countD = 0;
int interval = 5;//每5ms测量一次时间
int ppr = 13;//每圈脉冲数量，硬件决定
int spdrate = 50;//电机减速比，硬件决定
const double samptime = 30;//速度计算定时中断时长，间隔时间越长越精确但滞后越大

void setup_Encoder()
{//编码器初始化
  attachInterrupt(digitalPinToInterrupt(EncA),EncodeA,FALLING);//外部中断
  attachInterrupt(digitalPinToInterrupt(EncB),EncodeB,FALLING);
  attachInterrupt(digitalPinToInterrupt(EncC),EncodeC,FALLING);
  attachInterrupt(digitalPinToInterrupt(EncD),EncodeD,FALLING);
  FlexiTimer2::set(samptime, SpeedCount);//每samptime毫秒执行一次Read程序
  FlexiTimer2::start();
  pinMode(EncA,INPUT);
  pinMode(DirA,INPUT);
  pinMode(EncB,INPUT);
  pinMode(DirB,INPUT);
  pinMode(EncC,INPUT);
  pinMode(DirC,INPUT);
  pinMode(EncD,INPUT);
  pinMode(DirD,INPUT);
}

void EncodeA()
{//A编码器读取计数
  if((millis()-interval)>0.1)
  {//A
    if((digitalRead(EncA)==LOW)&&(digitalRead(DirA)==HIGH)) {countA++;}
    else  {countA--;}
  }
}

void EncodeB()
{//B编码器读取计数
  if((millis()-interval)>0.1)
  {//B
    if((digitalRead(EncB)==LOW)&&(digitalRead(DirB)==HIGH)) {countB++;}
    else  {countB--;}
  }
}

void EncodeC()
{//C编码器读取计数
  if((millis()-interval)>0.1)
  {//C
    if((digitalRead(EncC)==LOW)&&(digitalRead(DirC)==HIGH)) {countC++;}
    else  {countC--;}
  }
}

void EncodeD()
{//D编码器读取计数
  if((millis()-interval)>0.1)
  {//D
    if((digitalRead(EncD)==LOW)&&(digitalRead(DirD)==HIGH)) {countD++;}
    else  {countD--;}
  }
}

void SpeedCount()
{ //速度计算。精度与每圈脉冲ppr、减速比spdrate、中断时长samptime有关。
  //若速度低精度要求高，可使用光电编码器，光电编码器线数过高则arduino读取不完全
  spdA = (-countA/ppr)*(1000/samptime)*60/spdrate;//速度单位rpm，向前正方向
  countA = 0;//count归零
  spdB = (countB/ppr)*(1000/samptime)*60/spdrate;
  countB = 0;
  spdC = (-countC/ppr)*(1000/samptime)*60/spdrate;
  countC = 0;
  spdD = (countD/ppr)*(1000/samptime)*60/spdrate;
  countD = 0;
}
