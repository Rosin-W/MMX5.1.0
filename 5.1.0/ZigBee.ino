void setup_ZigBee() 
{
  Serial3.begin(19200);//3号串口波特率19200（与硬件设置相同）
}

void ZigBee()
{
  Serial3.write((int)BodyAngle);//远程传输至ZIGBEE另一端口，另一端口详见ZigBee1.ino
}
