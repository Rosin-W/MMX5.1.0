#include <PinChangeInt.h>
#include <FlexiTimer2.h>
#include <Wire.h>
#include <JY901.h>
#include "5.1Global.h"

void setup()
{
  Serial.begin(9600);//串口初始化，波特率9600
  setup_Encoder();//霍尔编码器初始化
  setup_motor();//电机初始化
  setup_Track12();//循迹初始化
  setup_MPU();//角度传感器JY61P初始化
  setup_CSB;//超声波初始化
  setup_ZigBee();//无线通讯模块ZigBee初始化
  setup_switch();//开关
  MotorSTOP();//电机静止，可用于流程空白时的硬件调试
  LightOFF();//LED灯带默认关闭
  part = 0;//阶段置零
  delay(500);//等待初始化完成、调试通电
  Serial.print("set up end.");//串口打印：初始化完毕
}
void loop() 
{
//  Print();//打印
//  debugAction();//动作测试，debug用
//  testAction();//流程测试
  Action1();//正式流程:初赛
//  Action2();//正式流程:决赛
}

void Print()
{//调试时的串口输出
  Serial.print(part);
  Serial.println(index);
}

void Action1()
{
  switch (part)
  {
    case 0: {Switch(); break;}//上电、等待开关开启（含有初始角度记录）
    case 1: {part1();  break;}//扫码
    case 2: {part2();  break;}//1区识别抓取
    case 3: {part3();  break;}//2区识别抓取
    case 4: {part41(); break;}//(初赛)前往装配区
    case 5: {part51(); break;}//物块装配
    case 6: {part6();  break;}//返回原点
    default : {MotorSTOP();  break;}//结束或暂停
  }
}

void Action2()
{
  switch (part)
  {
    case 0: {Switch(); break;}//上电、等待开关开启（含有初始角度记录）
    case 1: {part1();  break;}//扫码
    case 2: {part2();  break;}//1区识别抓取
    case 3: {part3();  break;}//2区识别抓取
    case 4: {part42(); break;}//(决赛)3区识别抓取
    case 5: {part52(); break;}//物块装配
    case 6: {part6();  break;}//返回原点
    default : {MotorSTOP();  break;}//结束或暂停
  }
}
