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
/**********注********
麦轮定义及安装：    四轮运动速度：
\\------//      A:'^'-,_,-  (向前为正方向)
 |A    B|       B:'-,_,-'^  (顺时针，每格为45°)
 |(俯 视)|       C:'-,_,-'^  (正弦曲线，请意会)
 |C    D|       D:'^'-,_,- 
//------\\      
sin()与cos()函数中需要将表示角度的浮点型float数值转换为弧度rad值
Arduino中自带的Angle函数是将角度浮点型转换为度分秒，此处不可用
另：可以尝试修改函数至可以移动固定长度
示例Move(float 移动角度,float 车体速度,float 移动距离)
**********************/
/*
void Move(float MoveAngle, float basespeed)
{//固定角度距离行驶
  MotorA = basespeed*sin((MoveAngle+45)*3.14/180);
  MotorB = basespeed*cos((MoveAngle+45)*3.14/180);
  MotorC = basespeed*cos((MoveAngle+45)*3.14/180);
  MotorD = basespeed*sin((MoveAngle+45)*3.14/180);
  DXgoal = sin(MoveAngle*3.14/180)*basespeed;
  DYgoal = cos(MoveAngle*3.14/180)*basespeed;
  dLxyA = spdA/60000*50*235;
  dLxyB = spdB/60000*50*235;
  dLxyC = spdC/60000*50*235;
  dLxyD = spdD/60000*50*235;
  Lx0 += dLxyA - dLxyB - dLxyC +dLxyD;
  Ly0 += dLxyA + dLxyB + dLxyC +dLxyD;
  //接下来斜向以Lx0为基准，用AC电机调整Y，本质和直线环相同，还没想好怎么写
  //但如果基准的Lx0过小则不准，尤其是往前的时候
  //所以可以分区讨论分别以X和Y为基准，绝对值0~45和135~180以Y，45~135以X
  {
    if((abs(MoveAngle)<45)||(abs(MoveAngle)>135))
    {DErr = DYgoal - dLy0;}
    else
    {DErr = DXgoal - dLx0;}
  }
  DInt += DErr;
  DDif = DPrvErr -DErr;
  //以上本质就是个直线闭环，“基准”的积分接近指定距离值的时候也需要控制算法
  //大概不能一开始就对移动总长度作控制，不然刚开始一段会全速前进，对误差影响很大
  //未完
  //既然有了光流传感器那还写个P的定距离啊轮子转速积分误差贼大
 */
