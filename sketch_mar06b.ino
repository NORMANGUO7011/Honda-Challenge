
// put your setup code here, to run once:
//defining variables
// include the libraries:
#include <LiquidCrystal.h>
#include <CapacitiveSensor.h>
#include <Servo.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
//Initalizing the Liquid Crystal
const int rs = 13, en = 12, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const float STEPS_PER_REV = 200;
//bi_polar_Stepper myStep(6,7,8,9);
//Stepper myStep( STEPS_PER_REV, 6, 7, 8, 9);
Servo myservo;



//Defining variables for the ultrasound sensors
//Define variables for the stepper motor
int StepsRequired = 0;;
//change to fit specific stepper motor

long duration;
int distance;
const int trigPin = 10;
const int echoPin = 11;
int inputPin = A0;
int input = 0;
int preState = LOW;
int rpm = 60;
int stepCount = 0;  // number of steps the motor has taken
int pos = 0;
const int servo = 9;

void setup() {
  //Setting all Analog Pins as Digital
  pinMode(A0, OUTPUT);
  digitalWrite(A0, HIGH);
  //  pinMode(A1, OUTPUT);
  //  digitalWrite(A1, HIGH);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, HIGH);
  pinMode(A3, OUTPUT);
  digitalWrite(A3, HIGH);
  pinMode(A4, OUTPUT);
  digitalWrite(A4, HIGH);
  pinMode(A5, OUTPUT);
  digitalWrite(A5, HIGH);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);
  //defines pins numbers
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A0, INPUT);
  //  myStep.set_step_per_rev(STEPS_PER_REV);
  //  myStep.set_RPM(rpm);
//  myStep.setSpeed(5);
  myservo.attach(servo);
  myservo.write(0);
}

void loop() {
  //Ultrasound Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  //Triggering startup sequence when ultrasound sensor detects
  if (distance <= 15)
  {
    //Prints the distance and the startup sequence
    lcd.print(distance);
    lcd.print("cm");
    delay(500);
    lcd.setCursor(2, 1);
    lcd.print("Starting");
    delay(1000);
    for (int i = 0; i <= 16; i++)
    {
      lcd.setCursor(i, 0);
      lcd.write(".");
      delay(100);
      lcd.clear();
    }
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(2, 1);
    // Print a message to the LCD.
    lcd.print("Sanitizing....");
    delay(3000);
    lcd.clear();
    myservo.write(-45); // Sets Servo in stages from 0 to 180 degrees so soap does not pitch out.
    delay(100);
    myservo.write(-90);
    delay(100);
    myservo.write(-135);
    delay(100);
    myservo.write(180); //Ajust how far you want the servo to go.
    delay(1000);
    myservo.write(0); // Reset the servo to 0 Degrees
    delay(3000);   //Delay the next time someone can get soap
  }
  //    myStep.rotate_CW();
  //  //Motion Detector
  //      digitalWrite(A2, HIGH);
  //  input = digitalRead(inputPin);  // read input value
  //  if (input == HIGH) {            // check if the input is HIGH
  //    if (preState == LOW) {
  //      // we have just turned on
  //      Serial.println("Motion detected!");
  //      // We only want to print on the output change, not state
  //      preState = HIGH;
  //      lcd.print("Starting");
  //        delay(1000);
  //        for (int i = 0; i <= 16; i++)
  //        {
  //          lcd.setCursor(i, 0);
  //          lcd.write(".");
  //          delay(100);
  //          lcd.clear();
  //        }
  //        // set the cursor to column 0, line 1
  //        // (note: line 1 is the second row, since counting begins with 0):
  //        lcd.setCursor(2, 1);
  //        // Print a message to the LCD.
  //        lcd.print("Sanitizing....");
  //        delay(3000);
  //        lcd.clear();
  //    }
  //  }
  //    else
  //      if (preState == HIGH) {
  //        // we have just turned of
  //        Serial.println("Motion ended!");
  //        // We only want to print on the output change, not state
  //        preState = LOW;
  //      }

  //   sqrReading = analogRead(sqrAnalog);
  //  {
  //     digitalWrite(A2, HIGH);
  //    //Prints the distance and the startup sequence
  //    lcd.print(sqrReading);
  //    lcd.print("N");
  //    delay(1000);
  //    lcd.setCursor(2, 1);
  //    lcd.print("Starting");
  //    delay(1000);
  //    for (int i = 0; i <= 16; i++)
  //    {
  //      lcd.setCursor(i, 0);
  //      lcd.write(".");
  //      delay(100);
  //      lcd.clear();
  //    }
  //    // set the cursor to column 0, line 1
  //    // (note: line 1 is the second row, since counting begins with 0):
  //    lcd.setCursor(2, 1);
  //    // Print a message to the LCD.
  //    lcd.print("Sanitizing....");
  //    delay(3000);
  //    lcd.clear();
  //
  //    //Starts the stepper motor
  //    int motorSpeed = map(900, 0, 1023, 0, 100);
  //    myStepper.setSpeed(motorSpeed);
  //    myStepper.step(STEPS_PER_REV);
  //    delay(2000);
}
