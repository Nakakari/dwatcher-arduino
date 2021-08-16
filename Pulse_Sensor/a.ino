void kalibrasi(){
  wak = millis();
  while(millis() - wak <= 5000){
    float sensor = analogRead(SENSOR); 
    pulse+=sensor;
    i++;
  }
    Serial.print("Kalibrasi : ");
    Serial.println(pulse/i);
    batas = pulse/i;
    waktu = millis();
    pulse = 0;
    i= 0;
}
