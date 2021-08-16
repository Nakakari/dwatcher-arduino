
//Wifi
#include <WiFi.h>
// Use WiFiClient class to create TCP connections
    WiFiClient client;
const char* ssid     = "realme 5i";
const char* password = "1sampai8";
const char* host = "192.168.43.110";
const char* streamId   = "....................";
const char* privateKey = "....................";
const int httpPort = 1000;

//Thermometer
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

float suhu;
int value = 0;

//Sound Sensor
const PROGMEM int ledPin = 5;               // define LED
    const PROGMEM int digitalPin = 4;           // define Sensor's D0 pin
    const PROGMEM int analogPin = 13;           // define Sensor's A0 pin

    static int maxA = 0;                        // max analog value
    static int minA = 1023;                     // min analog value
    int aValue = 0;                             // raw analog value
    int input;
    float volts;                                // analog voltage value
    float volts_input;
    int jmlbatuk;
    boolean batuk = false;
    float maxvolts;                             // max voltage value
    float minvolts;                             // min voltage value

void setup() {
  Serial.begin(9600);
  connectWifi();
//  Serial.println("Adafruit MLX90614 test");
  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };

  //Sensor Batuk
  pinMode(ledPin, OUTPUT);                   // define LED as output
  pinMode(digitalPin,INPUT);                 // define sensor D0 as input
  while(millis()<5000){
    kalibrasi();
  }
//  connectHost();
  delay(2000); 
}

void loop() {
  cekSuhu();
  cekBatuk();
  

  cetakData();
//  kirimData();
  batuk = false;
}

void cetakData(){
  Serial.print("Suhu : ");
  Serial.print(mlx.readObjectTempC());
  Serial.print("*C");
  Serial.print(" Jumlah batuk : ");
  Serial.print(jmlbatuk);
  Serial.println();

  Serial.print("A = "); Serial.print(aValue,DEC);
  Serial.print(" Max = "); Serial.print(maxvolts);
  Serial.print(" Min = "); Serial.print(minvolts);
  Serial.print(" volts = "); Serial.println(volts_input);
}
