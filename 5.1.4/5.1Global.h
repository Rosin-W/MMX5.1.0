/**********全局变量**********/
/*电机输出相关参数设定*/
float MotorA = 0.0;//预期转速
float MotorB = 0.0;//指定向前为正方向
float MotorC = 0.0;
float MotorD = 0.0;
float MotorSpdA = 0.0;//调参转速
float MotorSpdB = 0.0;//主要是角度环的调整
float MotorSpdC = 0.0;
float MotorSpdD = 0.0;

const double samptime = 50;//速度计算定时中断时长，间隔时间越长速度越精确但滞后越大
int n;//基于定时中断的时间计数，用于各种运动和通讯计数
int sec=1000/samptime;//一秒的n计算次数
int t;//基于循环的次数计数

/*MPU相关设定*/
float BodyAngle = 0.0;
float BaseAngle = 0.0;//车运行时指定的角度

/*循迹相关设定*/
int LineRow,LineCol;//经过的线，Row横行Col竖列
int Line=0;//线的计数不分行列
int T1=0,T2=0,T3=0,T4=0;//4路循迹，0白1黑
int PrvT1=0,PrvT2=0,PrvT3=0,PrvT4=0;//前一值，用于计数与判断
int TrackSpd = 90;//大段移动的较快速度
int CtrlSpd = 45;//精调的较慢速度

/*运动与通讯相关设定*/
String SendString = " ";
int session = 0;//区分初赛决赛，引脚52
int part = 0;//基于比赛流程的运动总阶段
int index = 0;//基于与树莓派通讯的运动总章节
int stage = 0;//运动的分阶段
int section = 1;//调整的段落，从1开始
int wait = 35*sec;//抓取物块时与树莓派通讯限定的次数，保证流程安全
char c;//ZigBee接收返回信号
int i;//从树莓派接受的扫码颜色数据
boolean STOP = true;//车体停止

int countN=30;
int Color1, Color2;
int Obj=0;
float Distance=0;
