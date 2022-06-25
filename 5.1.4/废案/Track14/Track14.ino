#define Track 30
int T1=0;int T2=0;int PrvT1;
void setup() 
{
  Serial.begin(9600);
  pinMode(Track,INPUT);
}

void loop() 
{
  PrvT1=T1;
  T1=digitalRead(Track);
  if(T1!=PrvT1)
  {T2++;}
  Serial.println(T2);

}
