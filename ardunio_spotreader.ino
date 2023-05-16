// ------------------------------------------------------------
// Hello World! Demo - Updated for PCBoard.ca 2020-08-20
//
// This sketch displays a simple message to the LCD screen
// ------------------------------------------------------------
 
#include <LiquidCrystal_I2C.h> // Driver Library for the LCD Module
 
// Wiring: Connect SDA pin to A4 and SCL pin to A5
// Connects to LCD via I2C, at address 0x27 (A0-A2 not jumpered)
 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F,16,2); // Adjust to (0x27,20,4) for 20x4 LCD

String data = " ";
String song_name = "Initializing";
String artist_name = "SpotiFetch";

void setup() {

  // Initiate the LCD and turn on the backlight
  lcd.init();          // Initiate the LCD module
  lcd.backlight();     // Turn on the backlight
  Serial.begin(9600);

  // changing the serial's timing to wait for stream data to 0.
  Serial.setTimeout(0);
}
 
void loop() {

  data = Serial.readString();
  int time2 = 200;
  
  for (int i = 0; i < data.length(); i++) 
  {
    if (data.substring(i, i+1) == "%") 
    {
      song_name = data.substring(0, i);
      artist_name = data.substring(i+1);
      break;
    }
  }
 /* if(song_name.length()>16)
  {
    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print(song_name.substring(0,16));
    lcd.setCursor(0, 1);
    lcd.print(song_name.substring(17));
    lcd.print("|" + artist_name); 
  }
  else
  {*/
    lcd.clear();
    lcd.setCursor(0, 0);     
    lcd.print(song_name);
    lcd.setCursor(2, 1);
    lcd.print(artist_name); 
    lcd.setCursor(0, 1);
    lcd.print(">");
    lcd.setCursor(15, 0);   
    lcd.print("|");
    lcd.setCursor(15, 0);
    delay(time2);
    lcd.print("/");
    lcd.setCursor(15, 0);
    delay(time2);
    lcd.print("-");
    lcd.setCursor(15, 0);
    delay(time2);
    lcd.print("\x0A ");
    lcd.setCursor(15, 0);
    delay(time2);
    lcd.print("|");
    lcd.setCursor(15, 0);
    delay(time2);
  //}
}
