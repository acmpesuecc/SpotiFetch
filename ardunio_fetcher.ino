
#include <LiquidCrystal_I2C.h> 
 
// Wiring: Connect SDA pin to A4 and SCL pin to A5
// Connects to LCD via I2C, at address 0x27 (A0-A2 not jumpered)
 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F,16,2); // Adjust to (0x27,20,4) for 20x4 LCD

String data = " ";
String song_name = "Initializing";
String artist_name = "SpotiFetch";

byte Sound[] = {
  B00001,
  B00011,
  B00101,
  B01001,
  B01001,
  B01011,
  B11011,
  B11000
};

byte Line[] = {
  B00000,
  B10000,
  B01000,
  B00100,
  B00010,
  B00001,
  B00000,
  B00000,
};

byte Full[] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
};

byte Middle[] = {
  B00000,
  B01110,
  B01010,
  B01010,
  B01010,
  B01010,
  B01110,
  B00000,
};

byte Inner[] = {
  B00000,
  B00000,
  B00100,
  B00100,
  B00100,
  B00100,
  B00000,
  B00000,
};

int time2 = 200;
int locx = 0;
int locy = 1;
String old_song = "";

void setup() {

  // Initiate the LCD and turn on the backlight
  lcd.init();          // Initiate the LCD module
  lcd.backlight();     // Turn on the backlight
  lcd.createChar(0, Sound);
  lcd.createChar(1, Line);
  lcd.createChar(2, Full);
  lcd.createChar(3, Middle);
  lcd.createChar(4, Inner);
  Serial.begin(9600);
  Serial.setTimeout(0);
}
 
void loop() {
  
  data = Serial.readString();   //Reads data from port
  
  for (int i = 0; i < data.length(); i++) //data is recieved as SongName%ArtistName. This loop splits it into 2 separate strings.
  {
    if (data.substring(i, i+1) == "%")
    {
      song_name = data.substring(0, i);
      artist_name = data.substring(i+1); 
      break;
    }
  }
  
  //The next If else was used when the song name was longer than 16 characters, to display it in the next line. This did not look aesthetically pleasing, and was removed.
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
  if(old_song != song_name)
  {
    lcd.clear();
    lcd.setCursor(0, 0);     
    lcd.print(song_name);  //prints song name in first line
    lcd.setCursor(2, 1);
    lcd.print(artist_name);  //prints artist name in the second line
    lcd.setCursor(15, 0);
    lcd.write((byte)0);
  }
  old_song = song_name;

  
  lcd.setCursor(locx, locy); 
  lcd.print("|");
  lcd.setCursor(locx, locy);  
  delay(time2);
  lcd.print("/");
  lcd.setCursor(locx,locy);
  delay(time2);
  lcd.print("-");
  lcd.setCursor(locx, locy);
  delay(time2);
  lcd.write((byte)1);
  lcd.setCursor(locx, locy);
  delay(time2);
  lcd.print("|");
  lcd.setCursor(locx, locy); 
  
  // A small rotating animation, added for aesthetics

  lcd.setCursor(locx, locy); 
  lcd.write((byte)2);
  delay(time2);
  lcd.setCursor(locx, locy); 
  lcd.write((byte)3);
  delay(time2);
  lcd.setCursor(locx, locy); 
  lcd.write((byte)4);
  delay(time2);
  lcd.setCursor(locx, locy); 
  lcd.write((byte)3);
  delay(time2);
  lcd.setCursor(locx, locy); 
  lcd.write((byte)2);
  
}
