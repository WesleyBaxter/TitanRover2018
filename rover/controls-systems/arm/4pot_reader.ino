/* Analog read of Linear Actuator Data
   
   David Feinzimer
   Feb 16 2018
   dfeinzimer@csu.fullerton.edu
   
   Copyleft 2005 DojoDave <http://www.0j0.org>
   
   ---
   
   Values Guide
   
   Extended:    972 - 975
   Retracted:   27 - 30
   
 */

int i = 0;            // Loop counter
int rr = 25;         // Report rate

int pot1_port = 0;    // Potentiometer 1 input port
int pot1_val = 0;     // Potentiometer 1 most recent value
int pot1_vals[99];    // Potentiometer 1 100 most recent values
int pot1_av = 0;

int pot2_port = 1;    // Potentiometer 2 input port
int pot2_val = 0;     // Potentiometer 2 most recent value
int pot2_vals[99];    // Potentiometer 2 100 most recent values
int pot2_av = 0;

int pot3_port = 2;    // Potentiometer 3 input port
int pot3_val = 0;     // Potentiometer 3 most recent value
int pot3_vals[99];    // Potentiometer 3 100 most recent values
int pot3_av = 0;

int pot4_port = 3;    // Potentiometer 4 input port
int pot4_val = 0;     // Potentiometer 4 most recent value
int pot4_vals[99];    // Potentiometer 4 100 most recent values
int pot4_av = 0;

void setup() {
 Serial.begin(9600);  // Initialize serial printing
}

void report() {       // Print out latest averaged values
 Serial.print("1: ");
 Serial.println(pot1_av);
 Serial.print("2: ");
 Serial.println(pot2_av);
 Serial.print("3: ");
 Serial.println(pot3_av);
 Serial.print("4: ");
 Serial.println(pot4_av);
}

void loop() {
 
 pot1_val = analogRead(pot1_port);    // Read the latest values
 pot1_vals[i] = pot1_val;
 
 pot2_val = analogRead(pot2_port);
 pot2_vals[i] = pot2_val;
 
 pot3_val = analogRead(pot3_port);
 pot3_vals[i] = pot3_val;
 
 pot4_val = analogRead(pot4_port);
 pot4_vals[i] = pot4_val;

 i++;

 if(i == rr) {                        // Calculate Averages 
  for(int t = 0; t < rr; t++) {
    pot1_av += pot1_vals[t];
    pot2_av += pot2_vals[t];
    pot3_av += pot3_vals[t];
    pot4_av += pot4_vals[t];
  }
   pot1_av = pot1_av / rr;
   pot2_av = pot2_av / rr;
   pot3_av = pot3_av / rr;
   pot4_av = pot4_av / rr;
   
   i = 0;
   
 } 
 
 delay(0);                         // Delay seconds (ms)

 report();

}
