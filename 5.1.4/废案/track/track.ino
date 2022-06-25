#define track1  27 //12
#define track2  31 //34
#define track3  29 //1黑0白
#define track4  33

int t1, t2, t3, t4;
int Trow1=0, Tcol1=0, Trow2=0, Tcol2=0;
//用于判断横竖线，row横行，col竖列
int Prvt1=0;
int Row=0,Col=0;//经过的线
void setup()
{
  Serial.begin(9600);
  pinMode(track1, INPUT);
  pinMode(track2, INPUT);
  pinMode(track3, INPUT);
  pinMode(track4, INPUT);
}

void loop()
{
  Track();
  Serial.print(Row);
  Serial.println(Col);
}

void Track()
{
  t1 = digitalRead(track1);
  t2 = digitalRead(track2);
  t3 = digitalRead(track3);
  t4 = digitalRead(track4);
  Trow1 = t1+t2; Trow2 = t3+t4;
  Tcol1 = t1+t3; Tcol2 = t1+t3;
  if((t1 ==1)&&(Prvt1 ==0))
  {
    if((Trow1 == 2)||(Trow2 ==0))
    {Row++;}
    if((Tcol1 == 2)||(Tcol2 ==0))
    {Col++;}
  }    
  Prvt1 = t1;
}
