//Pretend "counter" is "millis"
unsigned char counter = 0;
 int sensor_value, i, suara;
unsigned char previousCounter = 0;
unsigned long interval= 1000;
 
void setup() {
   Serial.begin(9600);
   delay(5000);  // give enough time to open the serial monitor after uploading
   Serial.println("Starting...");
}
void loop() {
  sensor_value     += analogRead(13);
  i++;
// ******* simulate millis()
       counter++; // simulate millis()
//       Serial.println(counter);
// ******
       unsigned char currentCounter = counter;
       if ((unsigned char)(currentCounter - previousCounter) >= interval) { // check for rollover
         Serial.println("Trigger Event!");
         suara = sensor_value/i;
         Serial.print("Suara : ");
          Serial.println(suara);
          Serial.print(" Millis : ");
          Serial.println(millis());
         previousCounter = currentCounter;
      }
//Serial.println("...stopping!");
//while(1); // Stop the Serial monitor output
}
