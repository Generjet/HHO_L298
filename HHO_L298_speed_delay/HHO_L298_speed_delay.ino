// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;
// gapentiometer
int gap = A0;
int pwmPot = A1;
int pwm = 255;
int pwmVal = 0;
int delayVal = 1000;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // Serial
  Serial.begin(9600);
}

void loop() {
  delayVal = analogRead(gap);
  pwm = analogRead(pwmPot);
  pwm = map(pwm, 0, 1023, 20 , 255);
  Serial.print("pwm= ");
  Serial.print(pwm);
  Serial.print(" , gap= ");
  Serial.println(delayVal);
//  directionControl();
//  delay(delayVal);
  speedControl();
  delay(delayVal);
}

// This function lets you control spinning direction of motors
void directionControl() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, pwm);
  analogWrite(enB, pwm);

  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(delayVal);
   
  // Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// This function lets you control speed of the motors
void speedControl() {
  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
//  delay(delayVal);
  
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i=i+10) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
   
  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
