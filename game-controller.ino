#define JOYSTICK1_X 20
#define JOYSTICK1_Y 21
#define JOYSTICK2_X 17
#define JOYSTICK2_Y 18

#define JOYSTICK1_BTN 19
#define JOYSTICK2_BTN 0
#define BTN1 16
#define BTN2 5




void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(JOYSTICK1_BTN, INPUT);
  pinMode(JOYSTICK2_BTN, INPUT);
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


  //read values
  int y_1 = analogRead(JOYSTICK1_Y);
  int x_1 = analogRead(JOYSTICK1_X);
  int joystickButton_1 = digitalRead(JOYSTICK1_BTN);
  int btn_1 = digitalRead(BTN1);

  int y_2 = analogRead(JOYSTICK2_Y);
  int x_2 = analogRead(JOYSTICK2_X);
  int joystickButton_2 = digitalRead(JOYSTICK2_BTN);
  int btn_2 = digitalRead(BTN2);
  
  Joystick.X(x_1);
  Joystick.Y(y_1);
  Joystick.Z(x_2);
  Joystick.Zrotate(y_2);

  Joystick.button(1, btn_1);
  Joystick.button(2, btn_2);
  Joystick.button(3, joystickButton_1 ? 0 : 1);
  Joystick.button(4, joystickButton_2 ? 0 : 1);
 
  Serial.println(y_1);
  Serial.println(x_1);
  Serial.println(joystickButton_1 ? 0 : 1);
  Serial.println(btn_1);
  Serial.println(y_2);
  Serial.println(x_2);
  Serial.println(joystickButton_2 ? 0 : 1);
  Serial.println(btn_2);
  Serial.println("\n\n\n");

  delay(100);
}
