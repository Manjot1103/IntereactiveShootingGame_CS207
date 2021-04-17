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
//Array storing the pins for servo
const byte servoPins[4] = {2,3,4,5};
//
Mux mux(Pin(A0, INPUT, PinType::Analog), Pinset(8, 9, 10, 11));
int sensor[4] = {0,0,0,0};
int old[4] = {78,78,78,78};
int pos[4]= {78,78,78,78};
int player[2] = {0,0};

LiquidCrystal_I2C lcd(0x27, 20, 4);


long timerThreshold = 20;
byte sensorThreshold = 50;
int prevRan;

void setup() {

  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);

  for(int  i = 0 ; i < 4 ; i++)
  {
    servo[i].attach(servoPins[i]);
    servo[i].write(78);
  }
  
  
  lcd.print("      WELCOME!      ");
  lcd.setCursor(0,1);
  lcd.print("  TO SHOOTING GAME  ");
  delay(2600);

    for(int  i = 0 ; i < 4 ; i++)
  {
    servo[i].write(3);
  }
  delay(1000);
    for(int  i = 0 ; i < 4 ; i++)
  {
    servo[i].write(78);
  }


  /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
  /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

  


  for(int i = 0 ; i < 2 ; i++)
  {
    
  lcd.clear();
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

  long timer = millis();
  long newTime = millis()-timer;
    
    while(newTime <= timerThreshold*1000 )
    {
      printScore(i);
      printTime(newTime);
      up();
      updateMux();
      down(i);
      printt();
      newTime = millis()-timer;
    }
    
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("      GAME END      ");
  delay(2600);
  }
  result();

  for(int  i = 0 ; i < 4 ; i++)
  {
    servo[i].write(78);
  }
  
}

void loop() {
/**/
}

void updateMux () {
  for (int i = 0; i < 4; i++){
    mux.channel(i);
    sensor[i] = mux.read();
    delay(3);
  }
}

void up()
{
  int ran;
  do
  {
   ran = random(4);
  }
  while(ran == prevRan);
  
  for(int i = 0 ; i < 4 ; i++)
  {
    if(pos[i] != 78)
    {
      return;
    }
   }
   prevRan = ran;
   pos[ran] = 3;
   servo[ran].write(3);
  
}

void down(int num)
{
  for(int i = 0; i < 4 ; i++)
  {
    if(sensor[i] >= sensorThreshold)
    {
      pos[i] = 78;
      servo[i].write(78);
      player[num] += 1;
    }
  }
}

void printTime(long milli)
{
   int sec = milli/1000;
   lcd.setCursor(0,3);
   lcd.print("Timer: ");
   lcd.print(timerThreshold-sec);
   lcd.print(" sec");
   lcd.print(" ");
}

void printScore(int num)
{
  lcd.setCursor(0,0);
  lcd.print("       Player");
  lcd.print(num+1);
  lcd.setCursor(0,1);
  lcd.print("Score: ");
  lcd.print(player[num]);
}

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
