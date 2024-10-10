int pot= A0;
int delayVal = 0;
int mapVal = 20;
int s1 = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(s1, OUTPUT);
}

void loop() {
  delayVal = analogRead(pot);
  mapVal = map(delayVal, 0, 1023, 20 , 1000);
  Serial.print("PotVal = ");
  Serial.print(" ");
  Serial.print(delayVal);
  Serial.print(" Delay= ");
  Serial.println(mapVal);
  digitalWrite(s1, HIGH);
  delay(mapVal);
  digitalWrite(s1, LOW);
  delay(mapVal);
}
