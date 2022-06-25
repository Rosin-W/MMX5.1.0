/**********1路*2激光循迹模块**********/
#define Track1 38
#define Track2 34
#define Track3 30
#define Track4 26

//循迹值设定见全局变量

void setup_Track12()
{
  pinMode(Track1,INPUT);
  pinMode(Track2,INPUT);
  pinMode(Track3,INPUT);
  pinMode(Track4,INPUT);
}

void TrackRead()
{
  PrvT1=T1;
  PrvT2=T2;
  PrvT3=T3;
  PrvT4=T4;
  T1=digitalRead(Track1);
  T2=digitalRead(Track2);
  T3=digitalRead(Track3);
  T4=digitalRead(Track4);
}

void TrackF(int RLine)
{//前走
  TrackRead();
  AngleCtrl();
  if((PrvT2==1)&&(T2==0)&&(n>0.5*sec))
  {Line++;n=0;}
  if(Line<abs(RLine))
  {Move(0,TrackSpd);}
  else
  {stage++;TrackZERO();Move(0,0);}
}

void TrackB(int RLine)
{//后走
  TrackRead();
  AngleCtrl();
  if((PrvT1==1)&&(T1==0)&&(n>0.5*sec))
  {Line++;n=0;}
  if(Line<abs(RLine))
  {Move(180,TrackSpd);}
  else
  {stage++;TrackZERO();Move(0,0);}
}

void TrackL(int CLine)
{//左走
  TrackRead();
  AngleCtrl();
  if((PrvT4==1)&&(T4==0)&&(n>0.5*sec))
  {Line++;n=0;}
  if(Line<abs(CLine))
  {Move(-90,TrackSpd-20);}
  else
  {stage++;TrackZERO();Move(0,0);}
}
void TrackR(int CLine)
{//右走
  TrackRead();
  AngleCtrl();
  if((PrvT3==1)&&(T3==0)&&(n>0.5*sec))
  {Line++;n=0;}
  if(Line<abs(CLine))
  {Move(90,TrackSpd-20);}
  else
  {stage++;TrackZERO();Move(0,0);}
}
