#include <PinChangeInt.h>
#include <FlexiTimer2.h>
#include <Wire.h>
#include <JY901.h>
/*电机输出相关参数设定*/
float MotorA = 80;//预期转速
float MotorB = -80;//指定向前为正方向
float MotorC = 80;
float MotorD = -80;

float MotorPWMA = 0;//输出转速（初始，调试用）
float MotorPWMB = 0;
float MotorPWMC = 0;
float MotorPWMD = 0;

int MotorSpeedMax = 280;
static float spdA;//电机实际转速
static float spdB;
static float spdC;
static float spdD;

/*MPU相关设定*/
float BodyAngle = 0;

void setup() 
{
  Serial.begin(9600);//串口初始化，波特率9600
  setup_motor();//电机初始化
  setup_Encoder();//霍尔编码器初始化
  setup_MPU();//角度传感器JY61P初始化
//  setup_ZigBee();//无线通讯模块ZigBee初始化
//  Move(90,100.0);
  delay(500);//等待初始化完成、调试通电
  Serial.print("set up end.");//串口打印：初始化完毕
}

void loop() 
{
  Print();
  Motor();
//  ReadMPU();
//  AngleCtrl();
//  ZigBee();
}

void Print()
{//调试时的串口输出
  /*Serial.print("BodyAngle:");
  Serial.println(BodyAngle);*/
  Serial.print("  SpdA:");
  Serial.print(spdA);
  Serial.print("  SpdB:");
  Serial.print(spdB);
  Serial.print("  SpdC:");
  Serial.print(spdC);
  Serial.print("  SpdD:");
  Serial.println(spdD);/*
  Serial.print("MotorA:");
  Serial.print(MotorA);
  Serial.print("  MotorB:");
  Serial.print(MotorB);
  Serial.print("  MotorC:");
  Serial.print(MotorC);
  Serial.print("  MotorD:");
  Serial.println(MotorD);*/
}
