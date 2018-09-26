int led = 3;
int otp = A0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(otp, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int valueOTP = analogRead(otp);

  Serial.println(valueOTP);

  analogWrite(led,valueOTP);
}
