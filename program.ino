#include <Wire.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>  // Needed by the EMIC2 library
#include "EMIC2.h"

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 9, d5 = 8, d6 = 7, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
int buttonState = 0;

unsigned team_1_counter = 0;
unsigned team_2_counter = 0;

String team_1_str = "Team 1: ";
String team_2_str = "Team 2: ";

String team_1_str_initial = "Team 1: ";
String team_2_str_initial = "Team 2: ";

#define AUDIO_OUT 0  // Connect SOUT pin of the Emic 2 module to the RX pin
#define AUDIO_IN 1  // Connect SIN pin of the Emic 2 module to the TX pin

EMIC2 emic;  // Creates an instance of the EMIC2 library


void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  lcd.setCursor(0, 0);
  lcd.print(team_1_str + team_1_counter);
  
  lcd.setCursor(0, 1);
  lcd.print(team_2_str + team_2_counter);

  emic.begin(AUDIO_OUT, AUDIO_IN);

  emic.setVoice(0);  // Sets the voice (9 choices: 0 - 8)
    emic.setVolume(10);
    
  //Serial.begin(9600);
}

void loop() {

  byte d = digitalRead(2);
  byte c = digitalRead(3);
  byte b = digitalRead(4);
  byte a = digitalRead(5);

  if(a == HIGH)
  {
    lcd.setCursor(0, 0);
    team_1_str = team_1_str_initial;
    team_1_str.concat(++team_1_counter);

    lcd.print(team_1_str);
    delay(200);

    emic.speak("Team 1");
    emic.speak(team_1_counter);
    emic.speak("points");
    !emic;  // Pauses playback    
  }
  else if(b == HIGH)
  {
    lcd.setCursor(0, 1);
    team_2_str = team_2_str_initial;
    team_2_str.concat(++team_2_counter);

    lcd.print(team_2_str);
    delay(200);

    emic.speak("Team 2");
    emic.speak(team_2_counter);
    emic.speak("points");
    !emic;  // Pauses playback
  }
  else if(c == HIGH)
  {
    lcd.setCursor(0, 0);

    if(team_1_counter > 0)
    {
      team_1_str = team_1_str_initial;
      team_1_str.concat(--team_1_counter);	
      lcd.print(team_1_str);
    }
    delay(200);

    emic.speak("Team 1");
    emic.speak(team_1_counter);
    emic.speak("points");
    !emic;  // Pauses playback
  }
  else if(d == HIGH)
  {
    lcd.setCursor(0, 1);

    if(team_2_counter > 0)
    {
      team_2_str = team_2_str_initial;
      team_2_str.concat(--team_2_counter);	
      lcd.print(team_2_str);
    }
    delay(200);

    emic.speak("Team 2");
    emic.speak(team_2_counter);
    emic.speak("points");
    !emic;  // Pauses playback
  }

}
