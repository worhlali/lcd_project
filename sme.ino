
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);


  
 const int redled=10;
 boolean y = true; 
 int buzzer = 12; 
 int Sensor= A1;


void setup() {
  // put your setup code here, to run once:
lcd.begin();
  lcd.backlight();

    lcd.backlight();
  lcd.print("HEY THERE!");
  lcd.setCursor(0,1);
  lcd.print("I AM WORLALI!");
  
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(Sensor, INPUT);
  pinMode(buzzer,OUTPUT);
  
  lcd.clear();
lcd.print("Sensor reading");
}

void loop() {
  // put your main code here, to run repeatedly:
 int c = analogRead(A1);
 Serial.println(c);
 lcd.setCursor(0,0);

 delay(500);
 lcd.setCursor(0,1);
 lcd.print(c);

 
 if (c <800 )
 {
  digitalWrite(10,HIGH);
  y== false;
  delay(1000);
  tone(buzzer,1000);
  delay(1000);
  noTone(buzzer);
   delay(100);
   
  
 }
 else if ( c>810 )
 {
  y==true;
   digitalWrite(10,LOW);
   delay(1000);
   tone(buzzer,300);
   delay(1000);
   noTone(buzzer);
   delay(100);
 }

 }
