void part1()    /************扫码************/
{
  if(index ==  0 )
  {//前往扫码区
    switch (stage)
    {
      case 0:   {MoveOUT(-90,1.0);     break;}
      case 1:   {MoveOUT(-45,0.8);     break;}
      case 2:   {TrackF(2);section=6;  break;}
      case 3:   {TrackCtrl(1);         break;}
      default:  {indexADD();           break;}
    }
  }
  if(index ==  1 )
  {//扫码，与树莓派通讯
    Serial.print("(s)");//扫码
    i = Serial.parseInt();delay(10);
    if((i==12)||(i==13)||(i==23)||(n>wait)){indexADD();}
  }
  if(index ==  2 )
  {//与车2通讯，语音播报
    delay(100);t++;
    if(i==12) {Serial3.print('3');}//红绿
    if(i==13) {Serial3.print('4');}//红蓝
    if(i==23) {Serial3.print('5');}//绿蓝
    if((Serial3.available())||(t>10))
    {indexADD();  t=0;index=0;part++;}
  }
}

void part2()    /************1区抓取************/
{
  if(index ==  0 )
  {//前往物料一区第一物块
    if(stage==0) {MoveOUT(-45,0.5);}
    if(stage==1) {TrackF(2);section=6;}
    if(stage==2) {TrackCtrl(1);LightON();}
    if(stage==3) {indexADD();}
  }
  if(index ==  1 )
  {//物料一区第一物块识别抓取
    Serial.print("(a)");
    i = Serial.parseInt();delay(20);
    if(i==1||n>wait){indexADD();}//收到信号或30秒未响应之后
  }
  if(index ==  2 )
  {//离开第一物块，前往第二物块
    if(stage==0) {TrackCtrl(2);}
    if(stage==1) {indexADD();}
  }
  if(index ==  3 )
  {//物料一区第二物块识别抓取
    Serial.print("(z)");
    i = Serial.parseInt();delay(20);
    if(i==2||n>wait){indexADD();}
  }
  if(index ==  4 )
  {//离开第二物块，前往第三物块
    if(stage==0) {TrackCtrl(1);}
    if(stage==1) {indexADD();}
  }
  if(index ==  5 )
  {//物料一区第三物块识别抓取
    Serial.print("(c)");
    i = Serial.parseInt();delay(20);
    if(i==3||n>wait){indexADD();  index=0;part++;LightOFF();}
  }
}

void part3()    /************2区抓取************/
{
  if(index ==  0 )
  {//离开第三物块，前往物料二区第一物块
    switch (stage)
    {
      case 0:   {MoveOUT(-90,0.3);      break;}
      case 1:   {TrackF(1);             break;}
      case 2:   {Turn(-90);             break;}
      case 3:   {MoveOUT(-45,1.0);      break;}
      case 4:   {TrackF(2);section=6;   break;}
      case 5:   {TrackCtrl(1);LightON();break;}
      default:  {indexADD();            break;}
    }
  }
  if(index ==  1 )
  {//物料二区第一物块
    Serial.print("(d)");
    i = Serial.parseInt();delay(20);
    if(i==4||n>wait){indexADD();}
  }
  if(index ==  2 )
  {
    if(stage==0) {TrackCtrl(2);}
    if(stage==1) {indexADD();}
  }
  
  if(index ==  3 )
  {//物料二区第二物块
    Serial.print("(e)");
    i = Serial.parseInt();delay(20);
    if(i==5||n>wait){indexADD();}
  }
  if(index ==  4 )
  {
    if(stage==0) {TrackCtrl(1);}
    if(stage==1) {indexADD();}
  }
  if(index ==  5 )
  {//物料二区第三物块
    Serial.print("(f)");
    i = Serial.parseInt();delay(20);
    if(i==6||n>wait){indexADD();LightOFF(); index=0;part=4;}
  }
}

void part6()
{
  if(index ==  0 )
  {
    switch (stage)
    {
      case 0:   {MoveOUT(-135,0.5); break;}
      case 1:   {ZigBee0();         break;}//通知车2回到原点
      default:  {indexADD();        break;}
    }
  }
  if(index ==  1 )
  {//溜
    switch (stage)
    {
      case 0:   {TrackL(2);         break;}
      case 1:   {TrackB(4);         break;}
      case 2:   {MoveOUT(-90,1.0);  break;}
//      case 3:   {Turn(0);           break;}
      default:  {indexADD();index=0;part=7;break;}
    }
  }
}
