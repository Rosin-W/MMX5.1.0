void Move(float MoveAngle, float basespeed)
{//固定角度行驶
  MotorA = basespeed * sin((MoveAngle+45)*3.14/180);
  MotorB = basespeed * cos((MoveAngle+45)*3.14/180);
  MotorC = basespeed * cos((MoveAngle+45)*3.14/180);
  MotorD = basespeed * sin((MoveAngle+45)*3.14/180);
}
