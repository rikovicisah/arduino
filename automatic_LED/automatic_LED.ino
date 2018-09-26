//led, ldr, otpornici 220Ohm, button

int LIGHT = 2;
int LED_START = 4;
int LIGHT_SENZOR = A0;
int BUTTON_START = 12;

bool pritisnut = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LIGHT,OUTPUT);
  pinMode(LED_START,OUTPUT);
  pinMode(LIGHT_SENZOR, INPUT);
  pinMode(BUTTON_START,INPUT);
  Serial.begin(9600);
}

void upali_LED(){
  digitalWrite(LIGHT,HIGH);
}

void ugasi_LED(){
  digitalWrite(LIGHT,LOW);
}

void pritisnutM(){
  pritisnut = !pritisnut;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int lightValue_read = analogRead(LIGHT_SENZOR);

  Serial.println(lightValue_read);
  Serial.print("Button je pritisnut :");
  Serial.println(pritisnut);
  delay(400);

  if(digitalRead(BUTTON_START) == 0) pritisnutM();

  if(lightValue_read < 50 && pritisnut){
    upali_LED();
  }else{
    ugasi_LED();
  }

}
