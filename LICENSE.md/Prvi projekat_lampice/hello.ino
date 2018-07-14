
#define LED_PIN 12
#define LED_PIN2 11
#define LED_PIN3 10
#define PREKIDAC_PIN 4

int brojac = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(PREKIDAC_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(PREKIDAC_PIN);

    if(value == HIGH){
      brojac++;
      delay(200);
    }

    switch(brojac%3){
      case 1:
        mod();
        break;
      case 2:
        mod1();
        break;
      default:
        mod2();
    }

   Serial.println(value);
   Serial.println(brojac);
   delay(40);
}

void mod(){
  digitalWrite(LED_PIN, HIGH);
  delay(400);
  digitalWrite(LED_PIN2, HIGH);
  delay(400);
  digitalWrite(LED_PIN3, HIGH);
  delay(400);
  digitalWrite(LED_PIN3, LOW);
  delay(400);
  digitalWrite(LED_PIN2, LOW);
  delay(400);
  digitalWrite(LED_PIN, LOW);
  delay(400);
}

void mod1(){
  digitalWrite(LED_PIN, HIGH);
  delay(400);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(LED_PIN2, HIGH);
  delay(400);
  digitalWrite(LED_PIN2, LOW);
  digitalWrite(LED_PIN3, HIGH);
  delay(400);
  digitalWrite(LED_PIN3, LOW);
}

void mod2(){
  digitalWrite(LED_PIN, HIGH);
  delay(400);
  digitalWrite(LED_PIN2, HIGH);
  delay(400);
  digitalWrite(LED_PIN3, HIGH);
  delay(400);
  digitalWrite(LED_PIN, LOW);
  delay(400);
  digitalWrite(LED_PIN2, LOW);
  delay(400);
  digitalWrite(LED_PIN3, LOW);
  delay(400);
}

