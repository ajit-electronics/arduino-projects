/**
 * Demonstrates usage of thumb joystick e.g.
 * https://www.seeedstudio.com/Grove-Thumb-Joystick-p-935.html
 *
 * Reads the X and Y position of the thumb joystick
 * and prints the positions to the serial monitor.
 *
 * Connections:
 *
 * Arduino | Thumb Joystick
 * -----------------
 * GND     | GND
 * 5V      | VCC
 * A0      | Y
 * A1      | X
 */

int X_PIN = A1;
int Y_PIN = A0;

int baseX;
int baseY;

void setup() {
  Serial.begin(9600);

  // read initial values from joystick
  // and use these values a the base
  baseX = analogRead(X_PIN);
  baseY = analogRead(Y_PIN);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // read values from the joystick
  // and adjust them to be relative to the
  // initial base values
  int x = analogRead(X_PIN) - baseX;
  int y = analogRead(Y_PIN) - baseY;

  int val = map(x, 0, 518, 0, 255);
  analogWrite(13, val);

  int val2 = map(y, 0, 518, 0, 255);
  analogWrite(12, val2);

  Serial.println(String("(val=") + String(val) + ", val2=" + String(val2) + String(")"));
  Serial.println(String("(x=") + String(x) + ", y=" + String(y) + String(")"));
}
