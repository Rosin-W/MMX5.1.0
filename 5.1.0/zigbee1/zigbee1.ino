int AngleZ;
float AngleP;
void setup() 
{
  Serial.begin(9600);
  Serial2.begin(19200);
  pinMode(2,INPUT);  
  pinMode(12,OUTPUT);
}

void loop()
{
  while(Serial2.available())
  {
    AngleZ = Serial2.read();
    AngleP = (float)AngleZ/256*360;
    if(AngleP>180.0)
    {AngleP -=360;}
    Serial.println(AngleP);
  }
  if(digitalRead(2) == HIGH)
  { Serial.println("!");}
}
