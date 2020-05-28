//******** Documentation Section ***********
//Project name : Smart Dustbin
//Funtion : Automatically opens the lid of dustbin when you go near it.
// Author : Harshit Srivastava
// Date : 18th January 2017

// Library included
#include<Servo.h> // library for Servo Motors


// defines pins numbers
const int trigPin = 9;//Connect trig pin of UltraSonic Sensor. 
const int echoPin = 10;//Connect Echo pin of UltraSonic Sensor.
const int servoPin = 3;//Connect Servo Motor to given pin ( select any PWM pin ) 

// defines variables
long duration;
int distance;
int Dist;
Servo Servo_Motor;

// Prototype Declaration Section.
int MeasureDistance();

void setup() {
     
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Servo_Motor.attach(servoPin); // We need to attach the servo to the used pin number  
    Serial.begin(9600); // Starts the serial communication
}

void loop()
{
      Dist = MeasureDistance();
      if (Dist < 30)// if distance is less than 30cm
      {
           open ();// opens the lid of Dustbin When you are near to it  
           delay (1000);
      }
      else
      {
        close(); // Closes the lid of Dustbin When you are far from it.
        delay(500);  
      }  
}

void open ()
{
   Servo_Motor.attach(servoPin); 
   Servo_Motor.write(90);   // turns the horn of Servo motor by 90 degree from intial position 
   delay(1000);
   Servo_Motor.detach();     
}  

void close()
{
   Servo_Motor.attach(servoPin);
   Servo_Motor.write(0);   // bring back th horn of servo motor back to its original position
   delay(1000);
   Servo_Motor.detach();     
    
}

int MeasureDistance () 
{
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance in cm
    distance= duration*0.034/2;
    return distance;
}
