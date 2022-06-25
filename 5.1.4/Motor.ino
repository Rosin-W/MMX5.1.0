/**********电机及PID算法**********/
#include "MotorPin.h"

void setup_motor()
{//电机输出初始化
  pinMode(PWMA1,OUTPUT);  pinMode(PWMA2,OUTPUT);
  pinMode(PWMB1,OUTPUT);  pinMode(PWMB2,OUTPUT);
  pinMode(PWMC1,OUTPUT);  pinMode(PWMC2,OUTPUT);
  pinMode(PWMD1,OUTPUT);  pinMode(PWMD2,OUTPUT);
  FlexiTimer2::set(samptime, SpeedCtrl);//每samptime毫秒执行一次速度计算与调整程序
  FlexiTimer2::start();//定时中断开启
}

void SpeedCtrl()
{//基于定时中断的电机速度调整
  SpeedCount();//通过编码器的计数换算成速度转每分钟
  SpeedExchange();//当预设速度发生较大改变时，改变PWMPID初始值，有助快速响应
  if((MotorA==0)&&(MotorB==0)&&(MotorC==0)&&(MotorD==0)){MotorSTOP();}
  else{MotorPIDA();MotorPIDB();MotorPIDC();MotorPIDD();}//电机速度调整PID
  MotorPWM(MotorPWMA,MotorPWMB,MotorPWMC,MotorPWMD);//调整后的速度输出
  n++;//顺便计算一个n，用于不需要太精确的短距离过渡性移动，作用与delay相似
}

void MotorPWM(float pwm1,float pwm2,float pwm3,float pwm4)
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
  float MpidErrA = MotorSpdA - spdA;    //比例Proportion
  MpidIntA += MpidErrA;               //积分Integral
  float MpidDifA = MpidErrA - MPrvErrA;//微分Differential
  MotorPWMA += MKp*MpidErrA + MKi*MpidIntA + MKd*MpidDifA;
  MPrvErrA = MpidErrA;
  if (MotorPWMA > 250) {MotorPWMA = 250;}//将PWM值限定
  if (MotorPWMA < -250) {MotorPWMA = -250;}
}

void MotorPIDB()
{
  float MpidErrB = MotorSpdB - spdB;
  MpidIntB += MpidErrB;
  float MpidDifB = MpidErrB - MPrvErrB;
  MotorPWMB += MKp*MpidErrB + MKi*MpidIntB + MKd*MpidDifB;
  MPrvErrB = MpidErrB;
  if (MotorPWMB > 250) {MotorPWMB = 250;}
  if (MotorPWMB < -250) {MotorPWMB = -250;}
}
void MotorPIDC()
{
  float MpidErrC = MotorSpdC - spdC;
  MpidIntC += MpidErrC;
  float MpidDifC = MpidErrC - MPrvErrC;
  MotorPWMC += MKp*MpidErrC + MKi*MpidIntC + MKd*MpidDifC;
  MPrvErrC = MpidErrC;
  if (MotorPWMC > 250) {MotorPWMC = 250;}
  if (MotorPWMC < -250) {MotorPWMC = -250;}
}
void MotorPIDD()
{
  float MpidErrD = MotorSpdD - spdD;
  MpidIntD += MpidErrD;
  float MpidDifD = MpidErrD - MPrvErrD;
  MotorPWMD += MKp*MpidErrD + MKi*MpidIntD + MKd*MpidDifD;
  MPrvErrD = MpidErrD;
  if (MotorPWMD > 250) {MotorPWMD = 250;}
  if (MotorPWMD < -250) {MotorPWMD = -250;}
}

void SpeedExchange()
{//当预设速度发生较大改变时，改变PWMPID初始值，有助快速响应
  if((abs(MotorSpdA-MotorA)>15)||(abs(MotorSpdB-MotorB)>15)||(abs(MotorSpdC-MotorC)>15)||(abs(MotorSpdD-MotorD)>15))
  {//预设速度与调节速度相差较大时重新赋值调节速度
    MotorSpdA = MotorA;MotorSpdB = MotorB;MotorSpdC = MotorC;MotorSpdD = MotorD;
  }
  if((abs(PrvMA-MotorA)>10)||(abs(PrvMB-MotorB)>10)||(abs(PrvMC-MotorC)>10)||(abs(PrvMD-MotorD)>10))
  {//预设速度改变时重新赋值调节速度和输出PWM
    MotorSpdA = MotorA;MotorSpdB = MotorB;MotorSpdC = MotorC;MotorSpdD = MotorD;
  }
  PrvMA = MotorA;PrvMB = MotorB;PrvMC = MotorC;PrvMD = MotorD;
}

void MotorSTOP()
{//急停
  Move(0,0);
  MotorPWM(0,0,0,0);
  MotorSpdA = 0;  MotorSpdB = 0;  MotorSpdC = 0;  MotorSpdD = 0;
  MotorPWMA = 0;  MotorPWMB = 0;  MotorPWMC = 0;  MotorPWMD = 0;
}

/************************编码器测速*****************************/

void setup_Encoder()
{//编码器初始化
  attachInterrupt(digitalPinToInterrupt(EncA),EncodeA,FALLING);//编码器外部中断，详见库
  attachInterrupt(digitalPinToInterrupt(EncB),EncodeB,FALLING);//使用下降沿中断
  attachInterrupt(digitalPinToInterrupt(EncC),EncodeC,FALLING);//若改用上升沿，注意判定相位超前和滞后的逻辑关系
  attachInterrupt(digitalPinToInterrupt(EncD),EncodeD,FALLING);//两相位信号周期一样仅相位不同，跳变沿中断意义不大
  pinMode(EncA,INPUT);  pinMode(DirA,INPUT);
  pinMode(EncB,INPUT);  pinMode(DirB,INPUT);
  pinMode(EncC,INPUT);  pinMode(DirC,INPUT);
  pinMode(EncD,INPUT);  pinMode(DirD,INPUT);
}

void EncodeA()
{//A编码器读取计数
  if((millis()-interval)>0.1)
  {//A
    if((digitalRead(EncA)==LOW)&&(digitalRead(DirA)==HIGH)) {countA++;}
    else {countA--;}
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
  spdA = (countA/ppr)*(1000/samptime)*60/spdrate;//速度单位rpm，定义向前正方向
  countA = 0;//count归零
  spdB = (-countB/ppr)*(1000/samptime)*60/spdrate;
  countB = 0;
  spdC = (countC/ppr)*(1000/samptime)*60/spdrate;
  countC = 0;
  spdD = (-countD/ppr)*(1000/samptime)*60/spdrate;
  countD = 0;
}
