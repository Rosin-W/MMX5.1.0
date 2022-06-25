/**********通讯相关**********/
/**********树莓派通讯**********/
#include <String.h>
String str= "";
//接受数据
void receive()
{
  while(Serial.available()>0)
  {
    str += char(Serial.read());
    delay(2);
  }
  if(str.length()>0)
  {
    Serial.println(str);
    str= "";
  }
}
void work()
{
  String x,y;
  x = str.substring(0,3);
  y = str.substring(5,8);
}

void RecogCatch()
{
  Serial.print('0');//识别抓取
  while(1)
  {
    i=Serial.parseInt();
    if(i == 1) {break;}
    else
    {Serial.print('0');}
  }
  Serial.print('9');
}
void QRcode()
{
  Serial.print('1');//扫码传输
  int Cirs=0;
  while(1)
  {
    i=Serial.parseInt();
    if((i == 12)||(i == 13)||(i == 23)||(Cirs>3))//红1绿2蓝3
    {break;}
    else
    {Serial.print('1');Cirs++;}
  }
  Serial.print('9');
  Color1=i/10;
  Color2=i-10*Color1;
}
/*******************ZigBee无线传输模块*****************/
void setup_ZigBee() 
{
  Serial3.begin(19200);//3号串口波特率19200（与硬件设置相同）
}

void ZigBee(int Text)
{
  Serial3.write(Text);//远程传输至ZIGBEE另一端口，另一端口详见ZigBee1.ino
}
