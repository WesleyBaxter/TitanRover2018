// Sends the voltage of a single LiPo battery to a LiquidCrystal display
// Modeled off of http://www.instructables.com/id/Arduino-Voltmeter/
// David Feinzimer dfeinzimer@gmail.com
// Last Updated 12/27/17

// Arduino max analog input voltage
float refVcc = 5.0;

void setup() {
  
  Serial.begin(9600);

}

void loop() {

  // Get raw analog input data
  int cell1 = analogRead(A0);
  int cell2 = analogRead(A1);
  int cell3 = analogRead(A2);
  int cell4 = analogRead(A3);



  // Display raw analog input data
  Serial.print("A1: ");
  Serial.println(cell1);

  Serial.print("A2: ");
  Serial.println(cell2);

  Serial.print("A3: ");
  Serial.println(cell3);

  Serial.print("A4: ");
  Serial.println(cell4);

  cell2 = cell2 - cell1;
  cell3 = cell3 - cell2 - cell1;
  cell4 = cell4 - cell3 - cell2 - cell1;

  // Display calculated voltage of a single cell of the LiPo battery
  Serial.print("Cell 1 Voltage: ");
  Serial.println((cell1*refVcc/1024)*5.72687);

  Serial.print("Cell 2 Voltage: ");
  Serial.println((cell2*refVcc/1024)*5.72687);

  Serial.print("Cell 3 Voltage: ");
  Serial.println((cell3*refVcc/1024)*5.72687);

  Serial.print("Cell 4 Voltage: ");
  Serial.println((cell4*refVcc/1024)*5.72687);

  Serial.println();

  // Wait 1 second and start the process again
  delay(1000);        // delay a whole second before reading again
  
}
