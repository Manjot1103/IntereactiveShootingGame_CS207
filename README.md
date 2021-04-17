# INTERACTIVE SHOOTING GAME

The interactive shooting game is a homemade game made with the help of the arduino and other electronic devices.

## Table of content:
-  Features
-  List Of Components
-  Build Instructions
-  Circuit Diagram
-  Software
-  Usage
-  Planned Features
-  Errors
-  Team members
-  Credits

## Features
The features of the projects are:
- The Blaster gun: One of the main components of the project is the blaster. The blaster is used by the player to eliminate its targets which are right in front of them. The blaster gun fires the paper bullet which is used to take down the targets.
- Scoreboard: The project also has a scoreboard in it. The players are able to see their score on there. And, even the time left for each play. In addition to this, the players can also compare their scores with each other as this game is one vs one game. And, the scoreboard tells the name of the winner.
- Targets or enemies: Targets are not that easy to hit. To get the point, the player has to hit at a certain to take down his targets. Moreover, it does not mean that, one`s the target is down it will not come back. After a few seconds the target will again stand and the player has to eliminate it again. And, this process will go on and on until the player is out of the time of the play. And, the score will be the total points or we can say the number of targets the player was able to hit.
- The display: We have tried to set the display as fun as the game. The background is covered with the black space with the lighting giving a kind of feeling of the war in the project. The targets are placed in zig-zag order which makes the things difficult for the players. And, lastly the scoreboard is standing right at the side of the targets letting the user about the time and scores.

 ## List Of Components
The components which we have used in our project are:
- Arduino Uno:

Arduino Uno is a microcontroller board which is an open-source platform used to connect hardware and software together. The programming language which it supports is one of the most common programming languages in the world which is C++. The software used to operate Arduino uno is Arduino IDE.

- BreadBoard:

Breadboard is a plastic board which helps to connect electronic devices and also helps to wire them together. There are many sockets in the breadboard which can vary according to its size. Its sockets are connected to each other in an order. For example, In the given picture, in the middle, the sockets are connected to each other horizontally whereas at the both ends of the board (left and right) which represents the 5v and ground, the sockets are connected vertically.

- Multiplexer:

Multiplexer is a device used to operate by sending or receiving  more than one signal (analogue and digital) over a common device at different periods of time. Moreover, helps to increase the number of pins in the Arduino as we can use its channels. So, It has 16 channels (pins) and 4 control pins.

- Piezo Element:

Piezo Element is a sensor used to detect the sound, vibration or knocking near itself. Whenever the piezo detects the knock, it generates voltage which the arduino easily interprets and gives the result to the user.

- LCD Module:

An LCD module or we can say Liquid Crystal Display module is an electronic display. The display which we have used in the project is a 20x4 LCD module which means it consists of 20 rows and 4 columns in it. It has a special library to use which is already created in the Arduino IDE named as Liquid Crystal library.

- DC Motors:

DC motor is an electronic device which uses electrical energy (DC) and converts it into mechanical energy (rotation). There are two types of DC motors brushed and brushless motors.

- Servos:

Servo Motor is a type of actuator that helps to achieve linear and angular positions. It consists of three wires which represents data wire which is used to receive information,voltage wire and ground wire. It also uses a special library which is already built in the Arduino IDE named as servo.

- ESP8266 (WiFi Module):

ESP8266 is an integrated chip used to add wifi to the arduino. With the help of this module, arduino is able to get access to the internet. Now, we are able to send SMS, mail or perform many more internet things in Arduino. 

- Resistors:

Resistors are the electronic devices used to resist the flow of the current in the circuit. Moreover, it prevents the burning of the device caused due to the direct flow of the current.

- Jumper Wires and Batteries.

## Build Instructions

The build of the project is disturbed into different elements of the project. And these builts are briefly described below:

- ### Build of Blaster for shooting:

Building bluster is one of the main and difficult parts of the project. Blaster helps to throw paper made bullets to targets. And, if that paper bullet hits the right position which has the piezo element attached to it, the target will fall down and the player will get one point to its scoreboard. 
        

The first thing of the project which started to prepare was its gun and its magazine was the initial step of its build. The magazine of the blaster helps to store paper bullets in it. First of all, we made cut outs for it and used glue guns to attach those cardboard cutouts together. To let the paper bullets bounce out the magazine, we need something like a spring which will make the bullets to come out the magazine. And, cables wires were the best option for us. We used cable wires as spring by folding it continuously to the end to make it work like a spring.

The next thing was to prepare the functioning of the blaster which consists of how it will be able to throw paper bullets. So, we used a wide mouthed straw as a nozzle. DC motors play the most important role in working the blaster. Total 3 DC motors were used in the blaster. Two of them were attached on the side of the straw which will accelerate the coming out  speed of the paper bullet. Another was used behind the straw and above the magazine which helps the bullet to get removed from the magazine and enter the nozzle. After making an extra cut out to cover the motors and nozzle we were able to get our blaster ready for use.

- ### Connecting Servos:

We have servo to make targets in the project. As, servos helps in the movement of the targets. So, first of all, we attached a cut out of the cardboard to the servo`s horn with the help of ice cream sticks. And, for the working of the servo, we have connected its pins with the arduino. We have used a total of 4 servos in the project and there are attached to pin 2,3,4,and 5 respectively. And, we have setted their angular movement from 0 degree to 90 degree where 0 degree represents the standing position of the target and 90 degree represents the fall down of the target.


- ### Connecting Multiplexer:

We have also used multiplexers in our project as it helped us with more pins to use in addition to the arduino pins. Multiplexer consists of 16 channels which we can also refer to as pins, one voltage pin (vcc), enabler, ground, signal pin (used to get input and output from arduino) and 6 selection pins. The sig pin is connected to the A0 of arduino. Enabler is connected to ground. And the 6 selection pins named as S0, S1, S2, and  S3c are attached to pins 8,9,10 and 11 respectively.
Connecting Piezo Element:


So, we have used piezo elements on the cut out of the target. So, when the paper bullet touches the element, the signal is sent to the arduino and then the arduino allows the servo to move which means the target falls down. And after a delay of a few seconds it again stands. We have used a total of 4 piezo elements in our project and each of them is connected to the multiplexer with pins C0, C1, C2,and C3 respectively. And another wire is attached to the ground. Most important thing to use a piezo element is to connect 1 mega ohms resistor to each element with one side connected to the voltage wire of the piezo element and the other to the ground wire. The reason to use this mega resistor is to increase the sensitivity of the element otherwise it will show no reading to the arduino.

- ### Connecting LCD Module:
To achieve the task to have a scoreboard, we have used an LCD module in our project. The scoreboard helps the player to know his score and time left. And, even tell the winner of the game at the end of a play. The LCD module is attached to a device named I2C which helps the module to use less pins to get attached with arduino. It consists of 4 pins: 5v, ground pin, SDA and SCL. And, these pins are attached to their respective arduino pins which also have the same names on it.

## Circuit Diagram

The following diagram contains the circuit including the connection of piezo elements, the multiplexer and servos with arduino:


And, the below diagram shows the connection of LCD module with the arduino using the I2C:


## Software

The software used for the project is Arduino IDE. All of the coding is done in this software. And, the libraries used for the project are: LiquidCrystal_I2CH, mux.h and servo.h.

All of the code is written from scratch.
Code: https://github.com/Manjot1103/IntereactiveShootingGame_CS207/blob/main/Project.ino

## Keywords:

Functions and methods:
- updateMux()
- Up()
- Down(int)
- printTime(long)
- printScore(int)
- result()

## Usage

The usage of our project is that it acts as an home-made interactive shooting game. Any person or group of persons can use things as a source of entertainment. Moreover, it is very easy to use. One or more players can also compete with each other as scores of each player will also be shown on the LCD module. 

The project does not need any open supply of electricity to operate. It only needs supply from the arduino and one batteries holder. 

## Planned Features

The following are the features which we planned to add to our project however because of some reasons:
- Wifi Module:
The extra feature we planned to add to our project was the use of the wifi module. As, with the use of the module, the arduino will get the access of the internet. And, using the internet, we could also send SMS and messages to the person. Like if a player broke someone's record a message will be forwarded to that player. However, due to the delivery issues created by the situation of COVID-19, the plan to add the module delay and ultimately we decided to not to add it. 
- Movement with DC motor:
The other feature we also wanted to add was the movement of the target from one side to other side with the help of the DC motors. To achieve that movement of that target, two dc motors are joined at the left and right side of the target. The motors will move one after another causing the horizontal movement. However, due to shortage of time we were not able to add it to the project.

## Errors

To complete the project, we have to come over many errors in the code as well as in hardware. However, with the proper knowledge and time we were able to overcome those obstacles. Here, are some errors we faced while completing the project:
- The problem we faced while using the piezo element was with soldering it. We are soldering the pins in the wrong way which let the piezo to not work. However, we realized it early and were able to solve this issue. And, moreover when we used piezo for the first time, we observed that it was not working. After some digging about the piezo, we came to know that it needs a resistor with high resistance to operate as it helps to increase its sensitivity. The resistor we used is a 1 mega ohms resistor.
- We had a hard time using servos. The pins connected to the servos and piezo did not match the pins which we used in the code resulting in no outcome. Thus, after analysis the code and the hardware the error was solved.
- Our servos were getting burnt up due to the interchange in the connection of 5v and ground pins. We burnt nearly 3 servos during making of the project. However, we were able to save some servos by opening them up and changing their gears with the servos which were already dead or burnt.
- There were also some coding errors like while using the timer, we were getting a timer in the pattern like 20,16,12 and so on. However, we were able to solve this problem.
- Unfortunately, we had an error with our blaster. The motors inside the blaster were not powerful enough to throw paper-bullets with speed so that they could hit the target and activate the piezo element. So, we have to use nerf guns as a solution for this problem.

## Team Members

- ### Preetinder Singh
Student ID: 200442004
Contribution to the project: Planning the execution and gathering parts for the project,
Project coding and project wiring.
- ### Manjot Singh
Student ID: 200444623
Contribution to the project: Documentation and build of Blaster.
And the final assembly of the project was done together.

## Credits
- Project theme: https://create.arduino.cc/projecthub/Ismail_San/laser-shooting-game-star-wars-f4acd8
- Creating cardboard gun using DC motors:
https://www.youtube.com/watch?v=L-i-eqjHiUI
- Usage of LCD module:
https://www.youtube.com/watch?v=wEbGhYjn4QI&t=1722s
- Github repository for multiplexer library:
https://github.com/stechio/arduino-ad-mux-lib
- Inspiration of using piezo element (knock sensor) rather than using photoresistor in the original project:
https://www.youtube.com/watch?v=X3XXRZMBPO0


