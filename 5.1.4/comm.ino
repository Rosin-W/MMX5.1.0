/**********ZigBee无线传输模块**********/
void setup_ZigBee() 
{
  Serial3.begin(19200);//3号串口波特率19200（与硬件设置相同）
}

void ZigBee1()
{//夹紧与松开的流程
  if(t<5)
  {
    Serial3.print('1');
    delay(100);t++;
    if(Serial3.available())
    {c =Serial3.read();}
    if((c=='1'))
    {t+=5;}
  }
  if(t>=5)
  {
    MotorSTOP();
    if(n>0.5*sec) {indexADD();}
  }
}

void ZigBee0()
{
  Serial3.print('0');
  delay(100);t++;
  if(Serial3.available())
  {c =Serial3.read();}
  if((c=='0')||(t>3))
  {indexADD();t=0;}
}
