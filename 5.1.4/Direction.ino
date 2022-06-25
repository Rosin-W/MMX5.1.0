/**********全向移动的速度计算与赋值**********/
void Move(float MoveAngle, float basespeed)
{//固定角度行驶
  MotorA = basespeed*sin((MoveAngle+45)*3.14/180);
  MotorB = basespeed*cos((MoveAngle+45)*3.14/180);
  MotorC = basespeed*cos((MoveAngle+45)*3.14/180);
  MotorD = basespeed*sin((MoveAngle+45)*3.14/180);
  if(MoveAngle==-360.0)//代表逆时针旋转
  {
    MotorA = -basespeed;
    MotorB = basespeed;
    MotorC = -basespeed;
    MotorD = basespeed;
  }
  if(MoveAngle==360.0)//代表顺时针旋转
  {
    MotorA = basespeed;
    MotorB = -basespeed;
    MotorC = basespeed;
    MotorD = -basespeed;
  }
}

void MoveOUT(float MoveOutAng,float MoveOutSec)//粗略的短距离移动，指定角度和时间秒
{
  Move(MoveOutAng,TrackSpd-25);
  if(n>MoveOutSec*sec)
  {stage++;TrackZERO();}
}
/**********注********
麦轮定义及安装：    四轮运动速度：
\\------//      A:'^'-,_,-  (向前为正方向)
 |A    B|       B:'-,_,-'^  (顺时针，每格为45°)
 |(俯 视)|       C:'-,_,-'^  (正弦曲线，请意会)
 |C    D|       D:'^'-,_,- 
//------\\      
sin()与cos()函数中需要将表示角度的浮点型float数值转换为弧度rad值
Arduino中自带的Angle函数是将角度浮点型转换为度分秒，此处不可用
另：可以尝试修改函数至可以移动固定长度，未完成的距离移动详见废案
车主要用激光循迹定位，直线距离积分可以用于：短距离移动、过线与重复计线保护，但比较难写，有空再说下次一定:)
**********************/
