#define A 7
#define B 8
#define C 2
#define D 3
#define E 4
#define H 5
#define G 6

#define KAT1 9
#define KAT2 10
#define KAT3 11
#define KATX 12
#define KAT5 13

void clr()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(H, HIGH);
  digitalWrite(G, HIGH);

}
void one()
{
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(H, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void two()
{
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(H, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
}

void three()
{
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(H, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void four()
{
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(H, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void five()
{
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(H, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
}

void six()
{
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(H, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
}

void seven()
{
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(H, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void eight()
{
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(H, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void nine()
{
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(H, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void zero()
{
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(H, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void LoopDisplay()
{
//  one();
//  delay(1000);
//  two();
//  delay(1000);
//  three();
//  delay(1000);
//  four();
//  delay(1000);
//  five();
//  delay(1000);
//  six();
//  delay(1000);
//  seven();
//  delay(1000);
//  eight();
//  delay(1000);
//  nine();
//  delay(1000);
//  zero();
//  delay(1000);
}

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(H, OUTPUT);
  pinMode(G, OUTPUT);

  pinMode(KAT1, INPUT);
  pinMode(KAT2, INPUT);
  pinMode(KAT3, INPUT);
  pinMode(KATX, INPUT);
  pinMode(KAT5, INPUT);

  goTo(1);

  Serial.begin(9600);
  Serial.println("Starting\n");
}
bool on = false;
int currentFloor = 1;

void goTo(int floor) {
  currentFloor = floor;
  Serial.println(floor);
  switch (floor) {
    case 0:
      zero();
      break;
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
  }
}
int btnPressed = 1;
void loop()
{
  int btn1, btn2, btn3, btn4, btn5;
  
  
  if(!on) {
    btn1 = digitalRead(KAT1);
    btn2 = digitalRead(KAT2);
    btn3 = digitalRead(KAT3);
    btn4 = digitalRead(KATX);
    btn5 = digitalRead(KAT5);
  }

  if (btn1 == HIGH && !on) {
    btnPressed = 1;
  }
  else if (btn2 == HIGH && !on) {
    btnPressed = 2;
  }
  else if (btn3 == HIGH && !on) {
    btnPressed = 3;
  }
  else if (btn4 == HIGH && !on) {
    btnPressed = 4;
    Serial.println("BTN 4");
  }
  else if (btn5 == HIGH && !on) {
    btnPressed = 5;
    Serial.println("BTN 5");
  }

  if(currentFloor > btnPressed) {
    on = true;
    for(int i=currentFloor;i>=btnPressed;i--) {
      goTo(i);
      delay(1000);
    }
    on = false;
  }
  else if(currentFloor < btnPressed) {
    on = true;
    for(int i=currentFloor;i<=btnPressed;i++) {
      goTo(i);
      delay(1000);
    }
    on = false;
  }
  
//  if (btn1 == HIGH && !on) {
//    on = true;
//    Serial.println("On");
//    if (currentFloor == 1)
//      for (int i = 1; i <= 5; i++) {
//        goTo(i);
//        delay(1000);
//    }
//    else {
//      for (int i = currentFloor; i >= 1; i--) {
//        goTo(i);
//        delay(1000);
//      }
//    }
//  }
//
//  if (test == LOW && on) {
//    on = false;
//    Serial.println("Off");
//  }

  delay(100);

  // LoopDisplay();
}
