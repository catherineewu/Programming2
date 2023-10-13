/**#include <Servo.h>
Servo myservo;

int pos = 0;
int const potPin = A0;
int potval;
int angle;
int const senPin = A1;
int senval;


void setup() {
    // The servo control wire is connected to Arduino D2 pin.
    myservo.attach(9);
    // Servo is stationary.
    myservo.write(90);
    Serial.begin(9600);
}

void loop() {
    potval = analogRead(potPin);
    Serial.print("Measured Pot Value ");
    Serial.print(potval);

    senval = analogRead(senPin); // read EMG sensor
    Serial.print(" Measured Sensor Value ");
    Serial.print(senval); // display EMH sensor value on serial monitor

    angle = map(potval,0,1023,0,179);
    Serial.print(" Converted angle ");
    Serial.print(angle);
    // Servo spins forward at full speed for 1 second.
    //myservo.write(180);
    //delay(1000);
    // Servo is stationary for 1 second.
    //myservo.write(90);
    //delay(1000);
    // Servo spins in reverse at full speed for 1 second.
    //myservo.write(0);
    //delay(1000);
    // Servo is stationary for 1 second.
    //myservo.write(90);
    //(1000);
    myservo.write(angle);
    delay(20);
}*/