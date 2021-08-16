#define SENSOR A0
long long int waktu , wak;
int pulse, pulsedetik, pulsemenit, pulse2, batas;
int i, j;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SENSOR, INPUT);
  kalibrasi();
  Serial.print("Batas : ");
  Serial.println(batas);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sensor = analogRead(SENSOR); 
  if(sensor>batas){
    j++;
    if(millis()-waktu>1000){
      Serial.print("pulse/detik : ");
      Serial.println(j);
      waktu = millis();
      j=0;
    }
  }
delay(1);   
}
