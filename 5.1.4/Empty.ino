void part41()/*初赛前往装配区*/
{
  if(index ==  0 )
  {ZigBee0();}//车2开始运行
  if(index ==  1)
  {//离开物料二区，前往装配区
    if(stage==0) {MoveOUT(-120,0.7);}
    if(stage==1) {TrackL(3);section=6;}
    if(stage==2) {TrackCtrl(1);}
    if(stage==3) {indexADD();delay(200);  index=0;part=5;}
  }
}

void part42()  /************(决赛)3区抓取************/
{
  if(index ==  0 )
  {//前往物料三区第一物块
    switch (stage)
    {
      case 0:  {MoveOUT(-100,0.5);    break;}
      case 1:  {TrackF(1);            break;}
      case 2:  {Turn(90);             break;}
      case 3:  {MoveOUT(90,0.7);      break;}
      case 4:  {TrackR(2);section=6;  break;}
      case 5:  {TrackCtrl(1);         break;}
      case 6:  {MoveOUT(135,0.5);     break;}
      case 7:  {TrackR(1);            break;}
      case 8:  {MoveOUT(90,0.5);      break;}
      case 9:  {TrackF(1);section=6;  break;}
      case 10: {TrackCtrl(1);         break;}
      default :{indexADD();Obj=0;Distance=220;break;}
    }
  }
  if(index ==  1 )
  {//物料三区第一物块
    if(stage==0)
    {
      CSBRead();
      if(Distance<200)      {Serial.print("(g)");stage=1;n=0;Obj=1;}//检测到有物块
      else if((Distance>240)||(n>wait)) {indexADD();Obj=0;}
    }
    if(stage==1)
    {
      Serial.print("(g)");
      i = Serial.parseInt();delay(20);
      if(i==7||n>wait){indexADD();Obj=1;}//物块计数
    }
  }
  if(index ==  2 )
  {//离开第一物块，前往第二物块
    if(stage==0) {TrackCtrl(2);}
    if(stage==1) {indexADD();stage=0;}
  }
  if(index ==  3 )
  {//物料三区第二物块
    if(stage==0)
    {
      if(Obj<1){Serial.print("(g)");stage=1;n=0;}//第一个没有扫到，后两个必全抓
      else if(Obj>0){stage=2;section=1;n=0;}//扫到了第一个，第二个就继续扫
    }
    if(stage==1)
    {
      Serial.print("(g)");//发送抓取第一个白物块的讯息
      i = Serial.parseInt();delay(20);
      if(i==7||n>wait){indexADD();Obj=1;}
    }
    if(stage==2)
    {
      if(section==1)
      {
        Distance=220;
        CSBRead();
        if(Distance<200)      {Serial.print("(h)");section=2;n=0;Obj=2;}//第一个位置没有，但此处第二个位置扫到物块
        else if((Distance>240)||(n>wait)) {indexADD();Obj=1;}
      }
      if(section==2)
      {
        Serial.print("(h)");//发送抓取第二个白物块的指令
        i = Serial.parseInt();delay(20);
        if(i==8||n>wait){indexADD();section==1;Obj=2;}
      }
    }
  }
  if(index ==  4 )
  {//离开第二物块，前往第三物块
    if(stage==0) {TrackCtrl(1);}
    if(stage==1) {indexADD();}
  }
  if(index ==  5)
  {//物料三区第三物块
    if(Obj<2)//前两个如果只抓了一个，则第三个的位置必然抓
    {
      Serial.print("(h)");
      i = Serial.parseInt();delay(20);
      if(i==8||n>wait){indexADD();Obj=2;}
    }
    else//前两个若两个都抓，则第三个的位置必然不抓
    {indexADD();}
  }
  
  if(index ==  6 )
  {//离开物料三区，前往装配区
    if(stage==0) {MoveOUT(-120,0.5);}
    if(stage==1) {TrackL(2);}
    if(stage==2) {indexADD();}
  }
  if(index ==  7 )/*决赛前往装配区*/
  {ZigBee0();}//车2开始运行
  if(index ==  8 )
  {//离开物料三区，前往装配区
    if(stage==0) {Turn(-90);}
    if(stage==1) {MoveOUT(-60,0.7);}
    if(stage==2) {TrackF(1);section=6;}
    if(stage==3) {TrackCtrl(1);}
    if(stage==4) {indexADD();delay(5000);  index=0;part=5;}
  }
}

void part51()
{/****************初赛装配流程****************/
  if(index ==  0 )
  {//抓取放置物块组1
    Serial.print("(j)");
    i = Serial.parseInt();delay(20);
    if(i==10||n>2*wait){indexADD();}
  }
  if(index ==  1 )
  {
    Serial3.print('1');
    if(n>1*sec) {indexADD();}
  }
  if(index ==  2 )
  {//放置装配体然后抓取放置物块组2
    Serial.print("(k)");
    i = Serial.parseInt();delay(20);
    if(i==11||n>2*wait){indexADD();}
  }
  if(index ==  3 )
  {
    Serial3.print('7');
    if(n>1*sec) {indexADD();}
  } 
  if(index ==  4 )
  {
    Serial.print("(l)");
    i = Serial.parseInt();delay(20);
    if(i==12||n>2*wait){indexADD();}
  } 
  if(index ==  5 )
  {
    Serial3.print('1');
    if(n>1*sec) {indexADD();}
  } 
  if(index ==  6 )
  {
    Serial.print("(m)");
    i = Serial.parseInt();delay(20);
    if(i==15||n>2*wait){indexADD();}
  } 
  if(index ==  7 )
  {
    Serial3.print('7');
    if(n>1*sec) {indexADD();index=0;part=6;}
  } 
}

void part52()
{/****************决赛装配流程****************/
  if(index ==  0 )
  {//第一装配体，正向旋转，放置第一物块
    Serial3.print('1');
    Serial.print("(j)");
    i = Serial.parseInt();delay(20);
    if(i==10||n>30*sec){indexADD();}
  }
  if(index ==  1 )
  {//第一装配体，正向旋转，放置第二物块，第三物块，23装配
    Serial.print("(k)");
    i = Serial.parseInt();delay(20);
    if(i==11||n>60*sec){indexADD();}
  }
  if(index ==  2 )
  {//第一装配体，反向旋转，夹持第二物块，12装配，拿走装配体
    Serial3.print('2');
    Serial.print("(l)");
    i = Serial.parseInt();delay(20);
    if(i==12||n>30*sec){indexADD();}
  }
  if(index ==  3 )
  {
    if(n<5*sec){Serial3.print('7');}//停止
    else {indexADD();}
  }
  
  if(index ==  4 )
  {//第二装配体，正向旋转，放置第一物块
    Serial3.print('1');
    Serial.print("(m)");
    i = Serial.parseInt();delay(20);
    if(i==13||n>30*sec){indexADD();}
  }
  if(index ==  5 )
  {//第二装配体，正向旋转，放置第二物块，第三物块，23装配
    Serial.print("(n)");
    i = Serial.parseInt();delay(20);
    if(i==14||n>60*sec){indexADD();}
  }
  if(index ==  6 )
  {//第二装配体，反向旋转，夹持第二物块，12装配，拿走装配体
    Serial3.print('2');
    Serial.print("(o)");
    i = Serial.parseInt();delay(20);
    if(i==15||n>30*sec){indexADD();}
  }
  if(index ==  7)
  {indexADD();  index=0;part=6;}
}
