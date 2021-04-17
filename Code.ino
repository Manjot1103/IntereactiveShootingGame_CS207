/* Interactive Shooting game
 * CS 207 Project
 * Written by: Preetinder Singh
 * Project Partner: Manjot Singh
 */

//Library for led module
#include <LiquidCrystal_I2C.h> 
//Library for multiplexer 
#include <Mux.h>
//Library for Servos
#include <Servo.h>

using namespace admux;

//Array for 4 servos
Servo servo[4];
//Array storing the 4 pins for servo
const byte servoPins[4] = {2,3,4,5};
//Multiplexer object with d(ata pin, input type, pintype)  and Pinset for control pins. 
Mux mux(Pin(A0, INPUT, PinType::Analog), Pinset(8, 9, 10, 11));
//Array for storing readings from 4 knock sensor (piezo element)
int sensor[4] = {0,0,0,0};
// Array to store the previous position (angle value) of the 4 servos.
int old[4] = {78,78,78,78};
// Array to store the current position (angle value) of the 4 servos.
int pos[4]= {78,78,78,78};
// Array to store the score of 2 players
int player[2] = {0,0};

// LiquidCrystal_I2C class object for the lcd module with parameters (lcd address, columns, rows) 
LiquidCrystal_I2C lcd(0x27, 20, 4);

// timer threshold of value 20 (it is the duration for which the game will run i.e 20 secs)
long timerThreshold = 20;
// sensor threshold of value 50 (it is the value for which the senor will trigger the servo)
byte sensorThreshold = 50;
// variable to keep record of the previous version of a value in code for comparison.
int prevRan;

void setup() {
  //calling the lcd method to trun on the lcd module
  lcd.begin();
  //calling the backlight method to turn on the lcd backlight
  lcd.backlight();
  //Setting the serial baud rate at 9600
  Serial.begin(9600);

  //loop to attach the 4 pins to the servos and setting then at an angle of 78
  for(int  i = 0 ; i < 4 ; i++)
  {
    servo[i].attach(servoPins[i]);
    servo[i].write(78);
  }
  
  // printing to the lcd at (0,0)
  lcd.print("      WELCOME!      ");
  // setting lcd cursor to row 0 and column 1
  lcd.setCursor(0,1);
  lcd.print("  TO SHOOTING GAME  ");
  // delay of 2600 milliseconds
  delay(2600);
  
  // setting all the 4 servos at an angle of 3
    for(int  i = 0 ; i < 4 ; i++)
  {
    servo[i].write(3);
  }
  // delay of 1000 milliseconds
  delay(1000);
  // setting all the 4 servos at an angle of 78
    for(int  i = 0 ; i < 4 ; i++)
  {
    servo[i].write(78);
  }


  /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
  // Game code 
  /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

  // loop runs twice for the number of players
  for(int i = 0 ; i < 2 ; i++)
  {
  // function to clear the lcd module
  lcd.clear();
  // set the lcd cursor to row 0 to column 1
  lcd.setCursor(0,1);
  lcd.print("       Player");
  lcd.print(i+1);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("You have ");
  lcd.print(timerThreshold);
  lcd.print(" seconds");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("      START!      ");
  delay(1000);
  lcd.clear();

  // to stroe the miiliseconds since the arduino got started
  long timer = millis();
   // to store the difference of the previous recorded time and the current time for running the timer of the game
  long newTime = millis()-timer;
    // loop runs while the time difference doesnot meet the timeThreshold
    while(newTime <= timerThreshold*1000 )
    {
      
      printScore(i);
      printTime(newTime);
      up();
      updateMux();  // function callings
      down(i);
      newTime = millis()-timer;  // getting the new time from the current time
    }
    
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("      GAME END      ");
  delay(2600);
  }
  // calling the result function
  result();

  // setting all the 4 servos at an angle of 78
    for(int  i = 0 ; i < 4 ; i++)
  {
    servo[i].write(78);
  }
  
}

void loop() {
/**/
}

// 
void updateMux () {
  //loop runs 4 time for recording each.
  for (int i = 0; i < 4; i++){
    //selecting the channel 
    mux.channel(i);
    //putting the sensor value in to the sensor array 
    sensor[i] = mux.read();
    delay(3);
  }
}

// function to get the enimies up or standing.
void up()
{
  // variable to store a random number generated ahead in the function
  int ran;
  do
  {
    // generating a random number from 0 to 3
   ran = random(4);
  }
  while(ran == prevRan);
  
  // loop runs 4 times to check if any target is standing
  for(int i = 0 ; i < 4 ; i++)
  {
    //if any servo has an angle of 78 (or is standing) the function is returned
    if(pos[i] != 78)
    {
      return;
    }
   }
   // saving the random value in prevRan
   prevRan = ran;
   // changing the angle of the servo in array
   pos[ran] = 3;
    // chanig the angle of the servo to 3.
   servo[ran].write(3);
  
}

// function to put down the the servos when the target get hit (knock sensor) 
void down(int num)
{
  // loop runs 4 times for checking each sensor.
  for(int i = 0; i < 4 ; i++)
  {
    // if the sensor value exceeds the threshold the sevo is moved to angle of 78
    if(sensor[i] >= sensorThreshold)
    {
      pos[i] = 78;
      //changing servo position to 78 angle
      servo[i].write(78);
      // incrementing the score of the current player
      player[num] += 1;
    }
  }
}

// to print the timer on the lcd 
void printTime(long milli)
{
   int sec = milli/1000;
   lcd.setCursor(0,3);
   lcd.print("Timer: ");
   lcd.print(timerThreshold-sec);
   lcd.print(" sec");
   lcd.print(" ");
}

// to print the score of the player on lcd
void printScore(int num)
{
  lcd.setCursor(0,0);
  lcd.print("       Player");
  lcd.print(num+1);
  lcd.setCursor(0,1);
  lcd.print("Score: ");
  lcd.print(player[num]);
}

// function to print the Scoreboard and result of the game.
void result()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("     SCOREBOARD     ");
    lcd.setCursor(0,1);
    lcd.print("Player1: ");
    lcd.print(player[0]);
    lcd.setCursor(0,2);
    lcd.print("Player2: ");
    lcd.print(player[1]);
    lcd.setCursor(0,3);
  //checking if player 1 won or player 2 won
    if(player[0] > player[1])
    {
      lcd.print("Player1 WON");  
    }
    else if(player[0] < player[1])
    {
      lcd.print("Player2 WON");
    }
    else
    {
      lcd.print("ITS A TIE");
    }
}
