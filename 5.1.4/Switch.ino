void setup_switch()
{
  pinMode(50,INPUT);
  pinMode(52,INPUT);
  pinMode(36,OUTPUT);
}
int sessionCount=0;
void Switch()
{
  ReadInitMPU();
  InitAngle = BodyAngle;
  if(digitalRead(50)==1)//预计将其改成上升沿触发，以应用于全局
  {part=1;delay(500);n=0;}
  else {part=0;}
  /*for(int num=0;num<10;num++)
  {
    if(digitalRead(52)==1)
    {sessionCount++;}//初赛为默认状态连接GND即始终为0，进决赛了直接拔掉跳线帽也可以
    delay(10);
  }
  if(sessionCount>=2)
  {session=0;n=0;}//0决赛1初赛
  else 
  {session=1;n=0;}*/
}

void indexADD()
{
  MotorSTOP();
  delay(200);
  TrackZERO();
  stage=0;
  index++;
}

void TrackZERO()
{//计数等数据清零,慎用
  Line=0;
  section=1;
  n=0;
}

void LightON()
{digitalWrite(36,HIGH);}//开灯

void LightOFF()
{digitalWrite(36,LOW);}//关灯
