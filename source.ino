// void -> returns None
// setup() and loop() is 2 default functions that are required to exist

// set up global variables for the digital cell id
// define is constant
#define red 8
#define green 12
#define securityAlarmButton 4
String data = "";

void setup()
{
  // Serial is a module that provides interface to the serial monitor
  // define transmission with a speed 9600b/s
  Serial.begin(9600);
  //Serial.println("hello arduino");
  
  // set up pin 8 as output
  pinMode(8, OUTPUT);
  // set up button to handle click input
  pinMode(4, INPUT_PULLUP);
  
  Serial.println("Starting signalization system");
}

void securityAlarm()
{
  // if button pressed:
  // 	red -> off
  //	green -> on
  // else:
  // 	red -> on
  //	green -> off
  
  int buttonState = digitalRead(securityAlarmButton);
  
  if (buttonState == LOW)
  {
    Serial.println("Signalization status: OK");
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
  }
  else
  {
    Serial.println("Signalization status: ALARM!!!");
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  }
}

void loop()
{
  securityAlarm();
}
