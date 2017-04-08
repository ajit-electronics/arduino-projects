/**
 * Demonstrates usage of thumb joystick e.g. moves servo with joystick
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
 #include <Servo.h>
 Servo servo;
 int currentAngle = 0;

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
  servo.attach(8);
  rotateServo(90, 15); // start from 90 Degrees
}

void loop() {
  // read values from the joystick
  // and adjust them to be relative to the
  // initial base values
  int x = analogRead(X_PIN) - baseX;
  int y = analogRead(Y_PIN) - baseY;
  int angle = 0;
  if(x>=0) {
     angle = map(x, 0, 500, 90, 180); //  from 90 Degrees to 180, middle to left
  }
  else {
      angle = map(x*-1, 0, 500, 90, 0); // from 90 to 0, middle to right
  }
  Serial.println(String("(angle =")+ String(angle));
  rotateServo(angle, 15);


  //we do not have a y axis rotation on 1 servo// int val2 = map(y, 0, 518, 0, 180);
  //rotateServo(angle, 15);

  Serial.println(String("(x=") + String(x) + ", y=" + String(y) + String(")"));
}


//--------------------------Servo +++++++
/**
   Simple servo demo.

   Connections:

   Arduino   | Servo
   --------------------
   8         | Signal
   GND       | GND
   VCC (+5V) | 5V
*/
void rotateServo(int targetAngle, int speed) {
  if(currentAngle < targetAngle) {
    for(int angle = currentAngle; angle < targetAngle; angle++) {
      servo.write(angle);
      delay(speed);
    }
  } else {
    for(int angle = currentAngle; angle > targetAngle; angle--) {
      servo.write(angle);
      delay(speed);
    }
  }
  currentAngle = targetAngle;
}
