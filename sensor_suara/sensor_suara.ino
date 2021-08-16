/*
KY-037 Sound Detection Sensor + Arduino
modified on 16 Apr 2019
by Mohammadreza Akbari @ Electropeak
https://electropeak.com/learn/
*/
int sensor_value, i, suara, j;
long long previousmillis =0;
void setup() {
  Serial.begin(9600); // setup serial
}
void loop() {
  sensor_value     = analogRead(13);
  Serial.print(sensor_value);
  if(sensor_value>300){
    j++;
    Serial.print("    A: ");
    Serial.print(j);
  }
  Serial.println(" ");
  i++;
//  if(i%100 == 0){
//    Serial.print(" Ay  ");
//  }
//  Serial.println(sensor_value);
//  if((millis() - previousmillis)>=1000){
//    previousmillis =millis();
//    suara = sensor_value/i;
//    Serial.print("Suara : ");
//    Serial.println(suara);
//    Serial.print(" Millis : ");
//    Serial.println(millis());
//    sensor_value = 0;
//    i = 0;
//  }
  
}
