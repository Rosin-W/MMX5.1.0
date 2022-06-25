/*void TrackCtrl1()//已有初步安全措施，问题：如何避免误差如灰尘引起的反复横跳？
{//准备抓取13位置物块时1灯对齐的精调
  TrackRead();
  if(section==0)
  {section=1;stage++;}//完成动作后进入主流程的下一阶段
  if(section==1)
  {//斜向移出，防止略过线后电机速度调整期间后退引起计线
    Move(-45,CtrlSpd+10);Motor();n++;
    if(n>50)
    {section=2;n=0;}
  }
  if(section==2)
  {//向前走使1灯与黑线对齐
    if(T1==1)//一旦扫到黑线就进入下一段横向移动，所以不需要避免重复计数
    {MotorSTOP();section=3;}//若扫到则进入下一段
    else if(T2==1&&PrvT2==0)//从白到黑，这里可能引起反复横跳，所以需要避免重复计数？
    {MotorSTOP();section=4;}//若过线使其他灯扫到黑线则退回重扫
    else
    {Move(0,CtrlSpd);Motor();}
  }
  if(section==3)
  {//向右走使4灯与黑线对齐
    if((T4==1)&&(PrvT4==0))
    {MotorSTOP();section=0;}
    else if(T3==1&&PrvT3==0)
    {MotorSTOP();section=5;}
    else if(T4==0)
    {Move(90,CtrlSpd);Motor();}
  }
  if(section==4)
  {//1灯过线安全措施向后走
    if(T1==1)
    {MotorSTOP();section=3;}//若扫到则进入横向调整阶段
    else if(T2==1&&PrvT2==0)
    {MotorSTOP();section=2;}//若又过线则回到1
    else
    {Move(180,CtrlSpd);Motor();}
  }
  if(section==5)
  {//4灯过线安全措施向左走
    if(T4==1)
    {MotorSTOP();section=0;}
    else if(T3==1&&PrvT3==0)
    {MotorSTOP();section=3;}
    else if(T4==0)
    {Move(-90,CtrlSpd);Motor();}
  }
}*/

void TrackCtrl(int Light)//已有初步安全措施，问题：如何避免误差如灰尘引起的反复横跳？
{//准备抓取13位置物块时1灯对齐的精调
  TrackRead();
  if(section==0)
  {section=1;stage++;}//完成动作后进入主流程的下一阶段
  if(section==1)
  {//斜向移出，防止略过线后电机速度调整期间后退引起计线
    Move(-45,CtrlSpd+10);Motor();n++;
    if(n>50)
    {section=2;n=0;}
  }
  if(section==2)
  {//向前走使灯与黑线对齐
    if(Light==1)
    {
      if(T1==1)//一旦扫到黑线就进入下一段横向移动，所以不需要避免重复计数
      {MotorSTOP();section=3;}//若扫到则进入下一段
      else if(T2==1&&PrvT2==0)//从白到黑，这里可能引起反复横跳，所以需要避免重复计数？
      {MotorSTOP();section=4;}//若过线使其他灯扫到黑线则退回重扫
      else
      {Move(0,CtrlSpd);Motor();}
    }
    else if(Light==2)
    {
      if(T2==1)
      {MotorSTOP();section=3;}
      else if(T2==1&&PrvT2==0)
      {MotorSTOP();section=4;}
      else
      {Move(0,CtrlSpd);Motor();}
    }
  }
  if(section==3)
  {//向右走使4灯与黑线对齐
    if((T4==1)&&(PrvT4==0))
    {MotorSTOP();section=0;}
    else if(T3==1&&PrvT3==0)
    {MotorSTOP();section=5;}
    else if(T4==0)
    {Move(90,CtrlSpd);Motor();}
  }
  if(Light==1)
  {
    if(section==4)
    {//灯过线安全措施向后走
      if(T1==1)
      {MotorSTOP();section=3;}//若扫到则进入横向调整阶段
      else 
      {Move(180,CtrlSpd);Motor();}
    }
  }
  if(Light==2)
  {
    if(section==4)
    {//灯过线安全措施向后走
      if(T2==1)
      {MotorSTOP();section=3;}//若扫到则进入横向调整阶段
      else 
      {Move(180,CtrlSpd);Motor();}
    }
  }
  if(section==5)
  {//4灯过线安全措施向左走
    if(T4==1)
    {MotorSTOP();section=0;}
    else 
    {Move(-90,CtrlSpd);Motor();}
  }
}


/*
void TrackCtrl2()
{//准备抓取2位置物块时2灯对齐的精调
  TrackRead();
  if(section==0)
  {section=1;stage++;}//完成动作后进入主流程的下一阶段
  if(section==1)
  {//斜向移出，防止略过线后电机速度调整期间后退引起计线
    Move(-45,CtrlSpd+10);Motor();n++;
    if(n>50)
    {section=2;n=0;}
  }
  if(section==2)
  {//向前走使1灯与黑线对齐
    if(T2==1)//一旦扫到黑线就进入下一段了，所以不需要避免重复计数
    {MotorSTOP();section=3;}//若扫到则进入下一段
    else if(T1==1&&PrvT1==0)//从白到黑，这里可能引起反复横跳，所以需要避免重复计数
    {MotorSTOP();section=4;}//若过线使其他灯扫到黑线则退回重扫
    else
    {Move(0,CtrlSpd);Motor();}
  }
  if(section==3)
  {//向右走使4灯与黑线对齐
    if((T4==1)&&(PrvT4==0))
    {MotorSTOP();section=0;}
    else if(T3==1&&PrvT3==0)
    {MotorSTOP();section=5;}
    else if(T4==0)
    {Move(90,CtrlSpd);Motor();}
  }
  if(section==4)
  {//1灯过线安全措施向后走
    if(T2==1)
    {MotorSTOP();section=3;}//若扫到则进入横向调整阶段
    else if(T1==1&&PrvT1==0)
    {MotorSTOP();section=2;}//若又过线则回到2
    else
    {Move(180,CtrlSpd);Motor();}
  }
  if(section==5)
  {//4灯过线安全措施向左走
    if(T4==1)
    {MotorSTOP();section=0;}
    else if(T3==1&&PrvT3==0)
    {MotorSTOP();section=3;}
    else
    {Move(-90,CtrlSpd);Motor();}
  }
}*/
