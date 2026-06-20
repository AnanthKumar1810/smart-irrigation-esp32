#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLuKAJ-y5i"
#define BLYNK_TEMPLATE_NAME "receving data"
#define BLYNK_AUTH_TOKEN "9nhv-NNRiSzzzzzczfA5-xxx-yyyyyyyy"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include<DHT.h>

#define DHTPIN 19
#define DHTTYPE DHT11
DHT dht(DHTΤΡΙΝ, DHTTYPE);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ssid";
char pass[] = "password";

void setup() {
Serial.begin(115200);
dht.begin();
pinMode(DHTPIN, INPUT); 
pinMode(18,INPUT); #Moisture Sensor
pinMode(5,OUTPUT); #Motor
pinMode(21, OUTPUT); #LED
pinMode(34,INPUT); #LDR
Blynk.begin(auth, ssid, pass);
}

void loop() {
float temp=dht.readTemperature();
float hum=dht.readHumidity();
Serial.print("Temperature: ");
Serial.println(temp);
Serial.print("Humidity: ");
Serial.println(hum);
delay(1000);

int light =analogRead(34);
Serial.println(light);
if(light>2000){
digitalWrite(21,HIGH);
}
else{
digitalWrite(21, LOW);
}

int moisture=digitalRead(18);
Serial.println(moisture);
if(moisture==1){
digitalWrite(5,HIGH);
}
else{
digitalWrite(5, LOW);
}

Blynk.virtualWrite(V1,light);
Blynk.virtualWrite(V2,temp);
Blynk.virtualWrite(V3,hum);
Blynk.virtualWrite(V4, moisture);
Blynk.run();
}

