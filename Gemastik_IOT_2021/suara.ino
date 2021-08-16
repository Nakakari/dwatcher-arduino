void kalibrasi(){
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
    jmlbatuk++;
    batuk = true;
    if(batuk){
      Serial.println("---------BATUK-------------");
    }
  }
//  Serial.print("Jumlah Batuk :");
//  Serial.println(batuk);
}
