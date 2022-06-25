int Information;//接收数字信息，字符串暂未测试
int SendString;
int Color1,Color2;
int i;
void setup() 
{
  Serial.begin(9600);//串口0连接电脑
  Serial3.begin(19200);//串口3连接zigbee
}

void loop()
{
  QRcode();
  for(int n=0;n<2;n++)
  {
    Serial3.print(Color1);
//    Serial.print(Color1);
    delay(1500);
    Serial3.print(Color2);
//    Serial.print(Color2);
    delay(1500);
  }
}
void Receive()
{
    while(Serial2.available())
  {
    Information = Serial2.read();//串口2从zigbee接收信息
    Serial.println(Information);//串口打印信息到电脑
  }
}
void QRcode()
{
  Serial.print('1');//扫码传输
  int Cirs=0;
  while(1)
  {
    i=Serial.parseInt();
    if((i == 12)||(i == 13)||(i == 23)||(Cirs>5))//红1绿2蓝3
    {break;}
    else
    {Serial.print('1');Cirs++;}
  }
  Serial.print('9');
  Color1=i/10;
  Color2=i-10*Color1;
}
