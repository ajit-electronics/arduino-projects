#define BUTTON_PIN 3
void setup() {

  pinMode(BUTTON_PIN, INPUT);
  digitalWrite (BUTTON_PIN, LOW);

  pinMode(13, OUTPUT);
  digitalWrite (13, LOW);


  Serial.begin(115200);
  Serial.println(F("RF24/examples/GettingStarted"));
}
bool  val ;
void loop() {
  if (digitalRead(BUTTON_PIN) == 0)
  {
    Serial.println("closed");
    digitalWrite (13, HIGH);
  }
  else
  {
    Serial.println("Open");
    digitalWrite (13, LOW);
  }
  delay(500);
}