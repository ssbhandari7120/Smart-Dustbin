# Smart-Dustbin

# Introduction and Overview
Smart Dustbin is a part of Home Automation project using Arduino UNO. Project Automates the opening and closing of the dustbin lid.

# Components Required
1) Arduino UNO
2) Pedal Dustbin
3) Ultrasonic Sensors
4) Servo Motor

# Working
Ultrasonic Sensors is used to calculate the distance from Dustbin. Whenever distance between us and Dustbin dips below 30 cm the Lid opens up by turning Servo Motor. As we move away from the dustbin, lid closes automatically

# Code Burning
Take the Library uploaded and paste them in Libraries folder inside the Arduino Folder. Libararies are provided by Arduino itself, but some Libraries are not present by default some we need to add them, in such case we can add them by putting it into libraries folder. Take the code for Arduino , select Arduino UNO in Tool>Board option , futher select COM port and then burn the code.

