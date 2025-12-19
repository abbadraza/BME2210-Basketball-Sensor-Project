#include <LiquidCrystal.h>

const int TRIG_PIN = 3;  //
const int ECHO_PIN = 4;
const int LED_PIN = 5;

// (RS, Enable, D4, D5, D6, D7)
// Pins: 8, 9, 10, 11, 12, 13
const int rsPin = 8;          //MODIFIED LINES 9-11 (needed to adjust pins so that the screen would stay in position without messing up the other components/wires)
const int enPin = 9;          //MODIFIED LINES 9-11 (needed to adjust pins so that the screen would stay in position without messing up the other components/wires)
const int d4Pin = 10;          //MODIFIED LINES 9-11 (needed to adjust pins so that the screen would stay in position without messing up the other components/wires)
const int d5Pin = 11;          //MODIFIED LINES 9-11 (needed to adjust pins so that the screen would stay in position without messing up the other components/wires)
const int d6Pin = 12;          //MODIFIED LINES 9-11 (needed to adjust pins so that the screen would stay in position without messing up the other components/wires)
const int d7Pin = 13;          //MODIFIED LINES 9-11 (needed to adjust pins so that the screen would stay in position without messing up the other components/wires)

LiquidCrystal lcd(rsPin, enPin, d4Pin, d5Pin, d6Pin, d7Pin);

float duration, distance;
int points = 0; //MODIFIED SO IT REGISTERS POINTS INSTEAD OF SCORE

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  // Initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);

  
  lcd.setCursor(0, 0);
  lcd.print("NBA SCOREBOARD"); //MODIFIED TO SAY NBA SCOREBOARD ON LCD 

  lcd.setCursor(0, 1); 
  lcd.print("Points: 0"); //MODIFIED TO DISPLAY POINTS SCORED
  Serial.begin(9600);
}

void updatepointsDisplay() { //ADDED A FUNCTION TO MAKE RUNNING PROGRAM ORGANIZED
  
  points++; //INCREASES POINTS ON BOARD

  
  lcd.setCursor(0, 1);
  lcd.print("Points: ");
  lcd.print(points); //MODIFIED TO UPDATE POINTS ON THE BOARD

  
  Serial.print("BUCKET! : ");
  Serial.println(points); //MODIFIED FROM EXAMPLE CODE TO OUTPUT IN SERIAL MONITOR
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
 
  if (distance <= 5.0) {
    digitalWrite(LED_PIN, HIGH);
    updatepointsDisplay();
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(500);
  /*
  MODIFIED LINES 63-70:
  INCLUDED IF ELSE STATEMENT TO LIGHT UP LED AND UPDATE THE POINTS ON THE BOARD USING THE CREATED FUNCTION
  OTHERWISE IF DISTANCE ISN'T MET IT WILL BE ON STANDY AND LED WILL TURN OFF
  DELAY IS SET TO 500 MS, ORIGINALLY FROM EXAMPLE CODE WHERE IT WAS 100 MS, WAS TOO FAST SO CHANGED TO 1000 MS (1 SEC), WAS TOO SLOW SO CHANGED TO 500 MS
  */
}