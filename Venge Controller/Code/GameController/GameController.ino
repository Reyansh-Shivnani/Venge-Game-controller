int xaxis;
int yaxis;
int strafe;
int forwardbackward;
int rxaxis;
int ryaxis;
int shift = 12;
int shoot = 11;
int space = 5;
int dance = 8;
int mainStop = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(shift, INPUT_PULLUP);
  pinMode(shoot, INPUT_PULLUP);
  pinMode(space, INPUT_PULLUP);
  pinMode(dance, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("a");

  xaxis = analogRead(A0); //set xaxis integer equal to the analog input signal from analog pin 0
  xaxis = map(xaxis, 0, 1023, 200, -200); //remap xaxis integer
  if (xaxis > mainStop) { //if xaxis integer is greater than the minimum threshold for movement (mainStop) then set strafe to 2
    strafe = 2;
  }
  if (xaxis < -mainStop) { //if xaxis integer is less than the minimum threshold for movement (mainStop) then set strafe to 1
    strafe = 1;
  }
  if (xaxis < mainStop && xaxis > -mainStop) { //if xaxis integer is between the movement thresholds (in the mainStop) then set strafe equal to 0
    strafe = 0;
  }
  Serial.print(strafe);

  yaxis = analogRead(A1);
  yaxis = map(yaxis, 0, 1023, -200, 200);
  if (yaxis > mainStop) {
    forwardbackward = 2;
  }
  if (yaxis < -mainStop) {
    forwardbackward = 1;
  }
  if (yaxis < mainStop && yaxis > -mainStop) {
    forwardbackward = 0;
  }
  Serial.print(forwardbackward);


  Serial.print("b");

  rxaxis = analogRead(A2);
  rxaxis = map(rxaxis, 0, 1023, 0, 9);
  Serial.print(rxaxis);

  ryaxis = analogRead(A3);
  ryaxis = map(ryaxis, 0, 1023, 0, 9);
  Serial.print(ryaxis);

  Serial.print("c");

  if (digitalRead(shift) == HIGH)
  {
    Serial.print("1");
  }
  else {
    Serial.print("0");
  }

  if (digitalRead(shoot) == HIGH)
  {
    Serial.print("1");
  }
  else {
    Serial.print("0");
  }

  Serial.print("f");

  if (digitalRead(space) == HIGH)
  {
    Serial.print("1");
  }
  else {
    Serial.print("0");
  }

  Serial.print("m");

  if (digitalRead(dance) == HIGH)
  {
    Serial.print("1");
  }
  else {
    Serial.print("0");
  }

  Serial.println();
  delay(1);
}
