/**********电机、编码器及PID : 引脚、参数、初始化、输出**********/
/*电机速度调节参数定义*/
float MotorPWMA = 0.0;//输出转速（初始，调试用）
float MotorPWMB = 0.0;
float MotorPWMC = 0.0;
float MotorPWMD = 0.0;
static float spdA;//电机实际转速
static float spdB;
static float spdC;
static float spdD;

/*电机相关引脚定义*/
/*PWM输出口，连接到A4950*/
/*!!!注意P9P10为舵机预留；注意P13连了自带LED刚启动会闪两下*/
#define PWMA1 11
#define PWMA2 12
#define PWMB1 6
#define PWMB2 7
#define PWMC1 4
#define PWMC2 5
#define PWMD1 2
#define PWMD2 3

/*编码器相关引脚定义*/
/*Enc接编码器A相，Dir接编码器B相*/  
/*注意：MEGA外部中断引脚号：2，3，21，20，19，18，分别对应interrupt0~5
编码器A相需要接中断引脚*/
#define EncA 18 //编码器A相  
#define DirA 25//编码器B相
#define EncB 19
#define DirB 23
#define EncC 20
#define DirC 22 
#define EncD 21
#define DirD 24

/*电机PID相关参数定义*/
float MKp = 0.15;
float MKi = 0.00005;
float MKd = 1.0;

float MPrvErrA = 0.0;//需要继承的几个PID参数
float MpidIntA = 0.0;
float MPrvErrB = 0.0;
float MpidIntB = 0.0;
float MPrvErrC = 0.0;
float MpidIntC = 0.0;
float MPrvErrD = 0.0;
float MpidIntD = 0.0;

/*用于速度改变量较大时的快速调整*/
float PrvMA = 0.0;
float PrvMB = 0.0;
float PrvMC = 0.0;
float PrvMD = 0.0;

/*编码器测速相关参数定义*/
float countA = 0;//计数，由于需要计算speed是浮点型，故此处不能用整型
float countB = 0;
float countC = 0;
float countD = 0;
int interval = 5;//每5ms测量一次时间
int ppr = 16;//每圈脉冲数量，硬件决定
int spdrate = 43.8;//电机减速比，硬件决定
