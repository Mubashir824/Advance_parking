#define BLYNK_TEMPLATE_ID "TMPL67p-lWyRB"
#define BLYNK_TEMPLATE_NAME "IR TRANSDUCER BASED CAR PARKING SYSTEM"
#define BLYNK_AUTH_TOKEN "_RuQoUGMFEvUcBOhDEPvXecaa60i8aTY"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <WiFiClient.h>

#define IR_SENSOR_1 27
#define IR_SENSOR_2 14
#define IR_SENSOR_3 25
#define IR_SENSOR_4 26

char auth[] = "BLYNK_AUTH_TOKEN"; 
char ssid[] = "DONT KNOW";
char pass[] = "W@leed2021";
// Car 1 variables
unsigned long startTime1 = 0;
bool carPresent1 = false;
float charges1 = 0.0;
// Car 2 variables
unsigned long startTime2 = 0;
bool carPresent2 = false;
float charges2 = 0.0;
// Car 3 variables
unsigned long startTime3 = 0;
bool carPresent3 = false;
float charges3 = 0.0;
// Car 4 variables
unsigned long startTime4 = 0;
bool carPresent4 = false;
float charges4 = 0.0;

const float chargeRate = 0.9; 
const int maxparkingslot=4;
int parkedcars=0;

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(IR_SENSOR_1, INPUT);
  pinMode(IR_SENSOR_2, INPUT);
  pinMode(IR_SENSOR_3, INPUT);
  pinMode(IR_SENSOR_4, INPUT);
}

void loop() {
   Blynk.run();
  checkCarPresence1();
  checkCarPresence2();
  checkCarPresence3();
  checkCarPresence4();
  Serial.println(parkedcars);
  if (parkedcars>=maxparkingslot){
    Serial.println("Not enough space:");
    Blynk.virtualWrite(V5,"Not enough space:");
  }
  else if(parkedcars<maxparkingslot){
    Blynk.virtualWrite(V5,"Maximum Slot 4");
  }
  delay(1000); 
}

void checkCarPresence1() {
  bool sensorState1 = digitalRead(IR_SENSOR_2);
  Serial.print("sensorState1:");
  Serial.println(sensorState1);
  Serial.println();
  if (sensorState1 == LOW && !carPresent1) {
    // Car 1 has entered
    carPresent1 = true;
    startTime1 = millis();
    parkedcars++;
    Serial.println("Car 1 entered.");
  } else if (sensorState1 == HIGH && carPresent1) {
    // Car 1 has left
    carPresent1 = false;
    parkedcars--;
    unsigned long endTime = millis();
    unsigned long parkedTime = (endTime - startTime1) / 1000; 
    float parkedMinutes = parkedTime / 60.0;
    charges1 = parkedMinutes * chargeRate;
    
    Serial.print("Car 1 parked time: ");
    Serial.print(parkedMinutes, 2);
    Serial.print(" minutes, charges: $");
    Serial.println(charges1, 2);
    Blynk.virtualWrite(V1, charges1);
  }
}
void checkCarPresence2() {
  bool sensorState2 = digitalRead(IR_SENSOR_3);
  Serial.print("sensorState2:");
  Serial.println(sensorState2);
  Serial.println();
  if (sensorState2 == LOW && !carPresent2) {
    // Car 2 has entered
    carPresent2 = true;
    startTime2 = millis();
    parkedcars++;
    Serial.println("Car 2 entered.");
  } else if (sensorState2 == HIGH && carPresent2) {
    // Car 2 has left
    carPresent2 = false;
    parkedcars--;
    unsigned long endTime = millis();
    unsigned long parkedTime = (endTime - startTime2) / 1000; // in seconds
    float parkedMinutes = parkedTime / 60.0;
    charges2 = parkedMinutes * chargeRate;
    
    Serial.print("Car 2 parked time: ");
    Serial.print(parkedMinutes, 2);
    Serial.print(" minutes, charges: $");
    Serial.println(charges2, 2);
    Blynk.virtualWrite(V2, charges2);
  }
}

void checkCarPresence3() {
  bool sensorState3 = digitalRead(IR_SENSOR_1);
  Serial.print("sensorState3:");
  Serial.println(sensorState3);
  Serial.println();
  if (sensorState3 == LOW && !carPresent3) {
    // Car 3 has entered
    carPresent3 = true;
    startTime3 = millis();
    parkedcars++;
    Serial.println("Car 3 entered.");
  } else if (sensorState3 == HIGH && carPresent3) {
    // Car 3 has left
    carPresent3 = false;
    parkedcars--;
    unsigned long endTime = millis();
    unsigned long parkedTime = (endTime - startTime3) / 1000; // in seconds
    float parkedMinutes = parkedTime / 60.0;
    charges3 = parkedMinutes * chargeRate;
    
    Serial.print("Car 3 parked time: ");
    Serial.print(parkedMinutes, 2);
    Serial.print(" minutes, charges: $");
    Serial.println(charges3, 2);
    Blynk.virtualWrite(V3,charges3);
  }
}

void checkCarPresence4() {
  bool sensorState4 = digitalRead(IR_SENSOR_4);
  Serial.print("sensorState4:");
  Serial.println(sensorState4);
  Serial.println();
  if (sensorState4 == LOW && !carPresent4) {
    // Car 4 has entered
    carPresent4 = true;
    startTime4 = millis();
    parkedcars++;
    Serial.println("Car 4 entered.");
  } else if (sensorState4 == HIGH && carPresent4) {
    // Car 4 has left
    carPresent4 = false;
    parkedcars--;
    unsigned long endTime = millis();
    unsigned long parkedTime = (endTime - startTime4) / 1000; // in seconds
    float parkedMinutes = parkedTime / 60.0;
    charges4 = parkedMinutes * chargeRate;
    
    Serial.print("Car 4 parked time: ");
    Serial.print(parkedMinutes, 2);
    Serial.print(" minutes, charges: $");
    Serial.println(charges4, 2);
    Blynk.virtualWrite(V4, charges4);
  }}

