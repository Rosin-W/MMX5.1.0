/********超声波，用来检测决赛物块3区的白色物块********/
#define trig 28
#define echo 32
float Time;
float dist=0;

int FiltN=50;//算数平均滤波采样值数量
void setup_CSB()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}
void CSB()
{//初始值获取
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  Time = pulseIn(echo,HIGH);
//  if((Time<50000)&&(Time>200))
  {dist = Time/5.83;}
  return dist;
}

void CSBRead()
{//初始值滤波
  int num;
  int FiltSum = 0;
  delay(100);
  for(num=0;num<FiltN;num++)
  {
    CSB();
    FiltSum += dist;
    delay(1);
  }
  Distance = FiltSum/FiltN;
}
