#define led 2
#define pinButton 4
#define input 13

int val;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinButton, INPUT);
  pinMode(input, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(pinButton);
  Serial.println(val);
  if(val ==HIGH){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
}
