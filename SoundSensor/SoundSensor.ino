
    // Other hardware pins
    const PROGMEM int ledPin = 5;               // define LED
    const PROGMEM int digitalPin = 4;           // define Sensor's D0 pin
    const PROGMEM int analogPin = 13;           // define Sensor's A0 pin

    static int maxA = 0;                        // max analog value
    static int minA = 1023;                     // min analog value
    int aValue = 0;                             // raw analog value
    int input;
    float volts;                                // analog voltage value
    float volts_input;
    int batuk;
    float maxvolts;                             // max voltage value
    float minvolts;                             // min voltage value
 
/* ***********************************************************
 *                      Global Variables                     *
 * ********************************************************* */
/* ***********************************************************
 *                         Void Setup                        *
 * ********************************************************* */
void setup(){
    Serial.begin (9600);
    pinMode(ledPin, OUTPUT);                   // define LED as output
    pinMode(digitalPin,INPUT);                 // define sensor D0 as input

    while(millis()<5000){
      checkAnalog();
    }
    delay(2000);                               // wait 2 seconds
}
 
/* ***********************************************************
 *                         Void Loop                         *
 * ********************************************************* */
void loop(){
    
  cekBatuk();
  Serial.print("Jumlah Batuk :");
  Serial.println(batuk);
}

/* ***********************************************************
 *                         Functions                         *
 * ********************************************************* */

void checkAnalog(){
    /* checkAnalog reads analog pin, saves min & max values, calculates voltages
     *   Parameters: (none)
     *   calls: drawMeter
     */
                                       
    aValue = analogRead(analogPin);             // analog values from 0-1023, 5V max

    if (aValue < minA) { minA = aValue;}        // save new min value
    if (aValue > maxA) { maxA = aValue;}        // save new max value
    volts = (aValue*5.0)/1024.0;
    minvolts = (minA*5.0)/1024.0;
    maxvolts = (maxA*5.0)/1024.0;

    // begin Debug code - Serial print analog value as decimal
        Serial.print("A = "); Serial.print(aValue,DEC);
        Serial.print(" Max = "); Serial.print(maxA);
        Serial.print(" Min = "); Serial.print(minA);
        Serial.print(" volts = "); Serial.println(volts);
}

void cekBatuk(){
  input = analogRead(analogPin);
  volts_input = (input*5.0/1024.0);
  if(volts_input>maxvolts){
    batuk++;
    Serial.println("---------BATUK-------------");
  }
}
