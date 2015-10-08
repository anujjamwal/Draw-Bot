#include <Servo.h> 


Servo shoulderServo, elbowServo, wristServo;
int shoulder = 0, elbow = 0, wrist = 0;

void setup() {
  
  Serial.begin(9600);
  
  wristServo.attach(7);
  shoulderServo.attach(9);
  elbowServo.attach(8);

  shoulderServo.writeMicroseconds(700);
  elbowServo.writeMicroseconds(700);
  wristServo.writeMicroseconds(700);
}

void move() {
  shoulder = Serial.parseInt();
  elbow = Serial.parseInt();

  shoulderServo.writeMicroseconds(shoulder);
  elbowServo.writeMicroseconds(elbow);

  Serial.print("Move: ");
  Serial.print(shoulder);
  Serial.print(' ');
  Serial.print(elbow);
  Serial.println();
}


void pen() {
  wrist = Serial.parseInt();
  
  if (wrist == 1)
    wristServo.writeMicroseconds(1200);
  else
    wristServo.writeMicroseconds(700);
    
  Serial.println(wrist != 1 ? "Pen: UP" : "Pen: DOWN");
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    switch(Serial.read()) {
      case 'M': move(); break;
      case 'P': pen(); break;
      case 'H': 
        Serial.println("Draw Bot 1.0");
        Serial.println("");
        Serial.println("Commands:");
        Serial.println("M <Shoulder> <Elbow>");
        Serial.println("The Move command. Values range between 700 - 2300");
        Serial.println("");
        Serial.println("P <0/1>");
        Serial.println("Pen command to put the pen up or down");
        Serial.println("");
        Serial.println("Happy Hacking");
        Serial.println("- IOT Gurgaon Team");
        break;
    }
  }
}







