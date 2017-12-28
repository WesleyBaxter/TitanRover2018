// Sends the voltage of a single LiPo battery to a LiquidCrystal display
// Modeled off of http://www.instructables.com/id/Arduino-Voltmeter/
// David Feinzimer dfeinzimer@gmail.com
// Last Updated 12/27/17

#include <LiquidCrystal.h>

// LiquidCrystal setup
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Arduino max analog input voltage
float refVcc = 5.0;

void setup() {
  
  Serial.begin(9600);

  // Initialize 16x2 LiquidCrystal display
  lcd.begin(16, 2);
  
}

void loop() {

  lcd.setCursor(0, 0);

  // Get raw analog input data
  int sensorValue = analogRead(A0);

  // Display raw analog input data
  lcd.print("Analog: ");
  lcd.print(sensorValue);

  // Display time elapsed since program start
  lcd.setCursor(14, 0);
  lcd.print(millis() / 1000);

  lcd.setCursor(0, 1);

  // Display calculated voltage of a single cell of the LiPo battery
  lcd.print("Voltage: ");
  lcd.print(sensorValue*refVcc/1024);

  // Wait 1 second and start the process again
  delay(1000);        // delay a whole second before reading again
  
}
